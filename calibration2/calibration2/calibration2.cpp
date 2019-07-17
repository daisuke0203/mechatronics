#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#pragma comment (lib,"opencv_world320d.lib")

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	int n_boards = 0; //入力リストにより設定される
	float image_sf = 0.5f;
	float delay = 1.f;
	int board_w = 0;
	int board_h = 0;

	board_w = 9;
	board_h = 6;
	n_boards = 5;

	if (argc > 4) delay = atof(argv[4]);
	if (argc > 5) image_sf = atof(argv[5]);

	int board_n = board_w * board_h;
	Size board_sz = Size(board_w, board_h);

	VideoCapture cap(1);

	//格納場所の確保
	vector<vector<cv::Point2f>>image_points;
	vector<vector<cv::Point3f>>object_points;

	double last_captured_timestamp = 0;
	Size image_size;

	while (image_points.size() < (size_t)n_boards)
	{
		Mat image0, image;
		cap >> image0;
		image_size = image0.size();
		resize(image0, image, Size(), image_sf, image_sf, INTER_LINEAR);

		//ボードを探す
		vector<Point2f> corners;
		bool found = findChessboardCorners(image, board_sz, corners);

		//描画
		drawChessboardCorners(image, board_sz, corners, found);

		//良いボードが見つかれば、データに加える
		double timestamp = (double)clock() / CLOCKS_PER_SEC;

		if (found&&timestamp - last_captured_timestamp > 1) {
			last_captured_timestamp = timestamp;
			image ^= Scalar::all(255);

			Mat mcorners(corners);
			mcorners *= (1. / image_sf);
			image_points.push_back(corners);
			object_points.push_back(vector<Point3f>());
			vector<Point3f>& opts = object_points.back();
			opts.resize(board_n);
			for (int j = 0; j < board_n; j++) {
				opts[j] = Point3f((float)(j / board_w), (float)(j%board_w), 0.f);
			}
			cout << "Collected our" << (int)image_points.size() <<
				"of" << n_boards << "needed chessboard images\n" << endl;
		}
		imshow("Calibration", image);
		if (waitKey(30) & 255 == 27) return -1;
	}

	destroyWindow("Calibration");
	cout << "\n\n***CALIBRATING THE CAMERA...\n" << endl;

	//キャリブレーション
	Mat intrinstic_matrix, distortion_coeffs;
	double  err = calibrateCamera(
		object_points,
		image_points,
		image_size,
		intrinstic_matrix,
		distortion_coeffs,
		noArray(),
		noArray(),
		CALIB_ZERO_TANGENT_DIST | CALIB_FIX_PRINCIPAL_POINT);

	cout << "***DONE!\n\nReprojection error is" << err <<
		"\nStoring Intrinsics.xml and Distorsions.xml files\n\n";
	FileStorage fs("intrinsics.xml", FileStorage::WRITE);

	fs << "image_width" << image_size.width << "image_height" << image_size.height
		<< "camera_matrix" << intrinstic_matrix << "distorsion_coefficients"
		<< distortion_coeffs;
	fs.release();

	fs.open("intrinstics.xml", FileStorage::READ);
	cout << "\nimage width: " << (int)fs["image_width"];
	cout << "\nimage_height: " << (int)fs["image_height"];

	Mat intrinsic_matrix_loaded, distortion_coeffs_loarded;
	fs["camera_matrix"] >> intrinsic_matrix_loaded;
	fs["distortion_coefficients"] > distortion_coeffs_loarded;
	cout << "\nintrinsic matrix: " << intrinsic_matrix_loaded;
	cout << "\ndistortion coefficients: " << distortion_coeffs_loarded << endl;

	Mat map1, map2;
	initUndistortRectifyMap(
		intrinsic_matrix_loaded,
		distortion_coeffs_loarded,
		Mat(),
		intrinsic_matrix_loaded,
		image_size,
		CV_16SC2,
		map1,
		map2
	);

	for (;;) {
		Mat image, image0;
		cap >> image0;
		if (image0.empty()) break;
		remap(
			image0,
			image,
			map1,
			map2,
			INTER_LINEAR,
			BORDER_CONSTANT,
			Scalar()
		);
		imshow("Undistorted", image);
		if ((waitKey(30) & 255) == 27) break;
	}
	return 0;
}
