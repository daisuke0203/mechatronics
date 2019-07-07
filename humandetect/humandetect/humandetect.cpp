#include "pch.h"
#include <iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#pragma comment(lib, "opencv_world320d.lib")
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap(0);
	int i = 0;
	while (1) {
		Mat src;
		cap >> src;
		//Mat src_image = imread("peo.PNG");
		Mat gray_image;
		cvtColor(src, gray_image, CV_BGR2GRAY);
		equalizeHist(gray_image, gray_image);
		vector<Rect>people;
		HOGDescriptor hog = HOGDescriptor(Size(64, 128),
			Size(16, 16), Size(8, 8), Size(8, 8), 9);
		hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
		hog.detectMultiScale(gray_image, people);
		Mat src_image1 = src.clone();
		for (auto it = people.begin(); it != people.end(); ++it) {
			rectangle(src_image1, it->tl(), it->br(), Scalar(0, 255, 255), 2, 8, 0);
			cout <<"tl"<< it->tl()<<endl;
			cout << "br" << it->br() << endl;
		}
		namedWindow("C");
		imshow("C", src_image1);
		
		if (waitKey(30)==27) break;
		//destroyAllWindows();
	}
	return 0;
}

