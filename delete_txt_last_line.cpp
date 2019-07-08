#include <iostream>
#include <fstream>
#include<stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define PATH "C:/Users/lijinxi/Documents/Visual Studio 2015/Projects/INRIA_shf_adaboost/INRIA_shf_adaboost/mit/pos"
#define SAVEPATH "C:/Users/lijinxi/Documents/Visual Studio 2015/Projects/INRIA_shf_adaboost/INRIA_shf_adaboost/mit/save_pos"
int main() {
	char filepath[2000];
	
	sprintf(filepath, "C:/Users/lijinxi/Documents/Visual Studio 2015/Projects/INRIA_shf_adaboost/INRIA_shf_adaboost/mit/pos_filelist.txt");
	int numOfFiles = 523;
	ifstream fin(filepath);
	if (!fin)
	{
		cerr << "fail" << endl;
		return -1;
	}
	char filename[200];
	while (!fin.eof()) {
		fin >> filename;
	//	cout << filename << endl;
		char txtpath[200];
		char path[2000];
		sprintf(txtpath, "%s/%s", PATH, filename);
		//cout << txtpath << endl;
		ifstream fin1(txtpath); 
				char savepath[200];
		sprintf(savepath, "%s/%s", SAVEPATH, filename);
		ofstream result(savepath, ios::app);

		float value;
		int m = 0;
		while (m != 4536) {
			fin1 >> value;
	//		cout << m << " " << value << endl;
			result << value << endl;
			m++;
		}

	}
	cout << "finsh" << endl;
	fin.close();

}
////有些时候，因为项目未注释，再次运行会重复已有的过程，在生成的文件上再加入已有的文件，所以需要在txt文件里删除新加入的文件
