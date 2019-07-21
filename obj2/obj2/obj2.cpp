// obj2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include<string>
#include <fstream>

using namespace std;

bool file_exist(const char* filename) {
	ifstream fis(filename);
	return fis.is_open();
}

int main() {
	/*string file_name;
	cout << "ファイル名：";
	cin >> file_name;
	cout << "そのファイルは存在"
		<< (file_exist(file_name.c_str()) ? "します\n" : "しません\n");
		*/

	ofstream fos("untitled.obj");
	if (!fos)
		cerr << "\aファイル\"untitled\"をオープンできません\n";
	else {
		fos << "# OBJ file format with ext.obj\n";
		fos << "# vertex count = 2503\n";
		fos << "# face count = 4968\n";
		fos << "v 0.00000000 0.0000000 0.0000000\n";   //1
		fos << "v 0.00443223 -0.00193917 -0.01013734\n";
		fos << "v -0.00079874 -0.00274275 -0.02410063\n";
		fos << "v -0.00713081 -0.00541004 -0.04186915\n";
		fos << "v -0.00682702 -0.00543704 -0.04249154\n";
		fos << "v -0.00578774 -0.00497836 -0.04613425\n";
		fos << "v -0.00471087 -0.00352998 -0.05172175\n";
		fos << "v -0.00499110 -0.00278048 -0.05923691\n";
		fos << "v -0.00355160 -0.00333357 -0.06800418\n";
		fos << "v -0.00518606 -0.00305264 -0.07311887\n"; //10
		fos << "v -0.00844581 -0.00142793 -0.08521906\n";
		fos << "v -0.01078181 -0.00103127 -0.09286787\n";
		fos << "v -0.01214282 -0.00147813 -0.09718567\n";
		fos << "v -0.00717961 -0.00299646 -0.08539797\n";
		fos << "v 0.03850350 -0.00677872 -0.05850243\n";
		fos << "v 0.05092291 -0.01421549 -0.03888016\n";
		fos << "v 0.04866178 -0.00818345 -0.04251440\n";
		fos << "v 0.04240522 -0.00096936 -0.01078777\n";
		fos << "v 0.03338418 0.00091987 0.00076368\n";
		fos << "v 0.04151767 -0.00407666 -0.05295367\n"; //20

		fos << "f 1 2 3\n";
		fos << "f 2 3 4\n";
		fos << "f 3 4 5\n";
		fos << "f 4 5 6\n";
		fos << "f 5 6 7\n";
		fos << "f 6 7 8\n";
		fos << "f 7 8 9\n";
		fos << "f 8 9 10\n";
		fos << "f 9 10 11\n";
		
		fos << "f 10 11 12\n";
		fos << "f 11 12 13\n";
		fos << "f 12 13 14\n";
		fos << "f 13 14 15\n";
		fos << "f 14 15 16\n";
		fos << "f 15 16 17\n";
		fos << "f 16 17 18\n";
		fos << "f 17 18 19\n";
		fos << "f 18 19 20\n";
		
	}
	
	

	/*ofstream fos("Bunny.obj");
	ifstream fis("rabit2.obj");
	if (!fis) 
		cerr << "\aファイルをオープンできません\n";
	else {
		while (true) {
			string text;
			getline(fis, text);
			if (!fis) break;

			fos << text << '\n';
		}
	}*/
	
}
