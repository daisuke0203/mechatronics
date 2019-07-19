#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
#pragma comment(lib, "opencv_world320d.lib")

HANDLE arduino;
bool Ret;

using namespace cv;
using namespace std;

bool file_exist(const char* filename) {
	ifstream fis(filename);
	return fis.is_open();
}

vector<string> split(string& input, char delimiter)
{
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

int main()
{

/*
	////通信//////////
	unsigned int  data = 0;
	//1.ポートをオープン
	arduino = CreateFile("\\\\.\\COM4", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (arduino == INVALID_HANDLE_VALUE) {
		printf("PORT COULD NOT OPEN\n");
		system("PAUSE");
		exit(0);
	}
	//2.送受信バッファ初期化
	Ret = SetupComm(arduino, 1024, 1024);
	if (!Ret) {
		printf("SET UP FAILED\n");
		CloseHandle(arduino);
		system("PAUSE");
		exit(0);
	}
	Ret = PurgeComm(arduino, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	if (!Ret) {
		printf("CLEAR FAILED\n");
		CloseHandle(arduino);
		exit(0);
	}
	//3.基本通信条件の設定
	DCB dcb;
	GetCommState(arduino, &dcb);
	dcb.DCBlength = sizeof(DCB);
	dcb.BaudRate = 9600;
	dcb.fBinary = TRUE;
	dcb.ByteSize = 8;
	dcb.fParity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;

	Ret = SetCommState(arduino, &dcb);
	if (!Ret) {
		printf("SetCommState FAILED\n");
		CloseHandle(arduino);
		system("PAUSE");
		exit(0);
	}
	//4.送信
	DWORD dwSendSize;
	DWORD dwErrorMask;

	VideoCapture cap(0);
	int i = 0;
	int x_br = 0;
	int x_tl = 0;

*/

	

	
		/*string file_name;
		cout << "ファイル名：";
		cin >> file_name;
		cout << "そのファイルは存在"
			<< (file_exist(file_name.c_str()) ? "します\n" : "しません\n");
			*/

		/*ofstream fos("route.txt");
		if (!fos)
			cerr << "\aファイル\"untitled\"をオープンできません\n";
		*/

	

	ofstream fos("route2.txt");
	ifstream fis("route.txt");
	float f[100] = { 0 };
	
	int i = 0;
	
	if (!fis)
		cerr << "\aファイルをオープンできません\n";
	else {
		string line;
		while (getline(fis, line)) {

			vector<string> strvec = split(line, ',');
			
			for (int i = 0; i < strvec.size(); i++) {
				cout << strvec.at(i) << endl;
			}

		}
	}

	/*while (1) {
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
		data = 0;
		for (auto it = people.begin(); it != people.end(); ++it) {
			rectangle(src_image1, it->tl(), it->br(), Scalar(0, 255, 255), 2, 8, 0);
			cout << "tl" << it->tl() << endl;
			cout << "br" << it->br() << endl;
			x_br = it->br().x;
			x_tl = it->tl().x;
			if (x_br < 200) data = 1;
			if ((x_br > 200) && (x_br < 400)) data = 2;
			if (x_br > 400) data = 3;
		}

		namedWindow("C");
		imshow("C", src_image1);

		if (waitKey(30) == 27) break;
		//destroyAllWindows();
		cout << data << endl;
		Ret = WriteFile(arduino, &data, sizeof(data), &dwSendSize, NULL);
		if (!Ret) {
			printf("SEND FAILED\n");
			CloseHandle(arduino);
			system("PAUSE");
			exit(0);
		}
	}
	*/
	printf("FINISH\n");
	CloseHandle(arduino);
	system("PAUSE");


	return 0;
}

