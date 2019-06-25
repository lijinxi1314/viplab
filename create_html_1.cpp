#include <iostream>
#include <fstream>
#include<stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#define IMAGEPATH "C:/Users/lijinxi/Desktop/Crop_data/2_2" 
using namespace std;
//
class ImportantFrame {
public:
	int index;
	string imagename;
	float m_rankValue, m_centerDis;
	ImportantFrame(int index, string imagename, float m_rankValue, float m_centerDis);
	ImportantFrame();

};
ImportantFrame::ImportantFrame(int index, string imagename, float m_rankValue, float m_centerDis) {
	this->index = index;
	this->imagename = imagename;
	this->m_rankValue = m_rankValue;
	this->m_centerDis = m_centerDis;

}

ImportantFrame::ImportantFrame()
{
}

///////0////////////
float m_rankValue_max0 = 0;
float m_centerDis_min0 = 1;

vector<ImportantFrame> res0;
void cal_index_minmax0(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max0) {
		m_rankValue_max0 = m_rankValue;
		if (m_centerDis < m_centerDis_min0) {
			m_centerDis_min0 = m_centerDis;
			res0.push_back(ImportantFrame(index, filepath, m_rankValue_max0, m_centerDis_min0));	
		}
	}
}

///////1////////////
float m_rankValue_max1 = 0;
float m_centerDis_min1 = 1;

vector<ImportantFrame> res1;
void cal_index_minmax1(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max1) {
		m_rankValue_max1 = m_rankValue;
		if (m_centerDis < m_centerDis_min1) {
			m_centerDis_min1 = m_centerDis;
			res1.push_back(ImportantFrame(index, filepath, m_rankValue_max1, m_centerDis_min1));
		}
	}
}

///////2////////////
float m_rankValue_max2 = 0;
float m_centerDis_min2 = 1;

vector<ImportantFrame> res2;
void cal_index_minmax2(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max2) {
		m_rankValue_max2 = m_rankValue;
		if (m_centerDis < m_centerDis_min2) {
			m_centerDis_min2 = m_centerDis;
			res2.push_back(ImportantFrame(index, filepath, m_rankValue_max2, m_centerDis_min2));
		}
	}
}

///////3////////////
float m_rankValue_max3 = 0;
float m_centerDis_min3 = 1;

vector<ImportantFrame> res3;
void cal_index_minmax3(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max3) {
		m_rankValue_max3 = m_rankValue;
		if (m_centerDis < m_centerDis_min3) {
			m_centerDis_min3 = m_centerDis;
			res3.push_back(ImportantFrame(index, filepath, m_rankValue_max3, m_centerDis_min3));
		}
	}
}


///////4////////////
float m_rankValue_max4 = 0;
float m_centerDis_min4 = 1;

vector<ImportantFrame> res4;
void cal_index_minmax4(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max4) {
		m_rankValue_max4 = m_rankValue;
		if (m_centerDis < m_centerDis_min4) {
			m_centerDis_min4 = m_centerDis;
			res4.push_back(ImportantFrame(index, filepath, m_rankValue_max4, m_centerDis_min4));
		}
	}
}

///////5////////////
float m_rankValue_max5 = 0;
float m_centerDis_min5 = 1;

vector<ImportantFrame> res5;
void cal_index_minmax5(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max5) {
		m_rankValue_max5 = m_rankValue;
		if (m_centerDis < m_centerDis_min5) {
			m_centerDis_min5 = m_centerDis;
			res5.push_back(ImportantFrame(index, filepath, m_rankValue_max5, m_centerDis_min5));
		}
	}
}
///////6////////////
float m_rankValue_max6 = 0;
float m_centerDis_min6 = 1;

vector<ImportantFrame> res6;
void cal_index_minmax6(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max6) {
		m_rankValue_max6 = m_rankValue;
		if (m_centerDis < m_centerDis_min6) {
			m_centerDis_min6 = m_centerDis;
			res6.push_back(ImportantFrame(index, filepath, m_rankValue_max6, m_centerDis_min6));
		}
	}
}
///////7////////////
float m_rankValue_max7 = 0;
float m_centerDis_min7 = 1;

vector<ImportantFrame> res7;
void cal_index_minmax7(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max7) {
		m_rankValue_max7 = m_rankValue;
		if (m_centerDis < m_centerDis_min7) {
			m_centerDis_min7 = m_centerDis;
			res7.push_back(ImportantFrame(index, filepath, m_rankValue_max7, m_centerDis_min7));
		}
	}
}
///////8////////////
float m_rankValue_max8 = 0;
float m_centerDis_min8 = 1;

vector<ImportantFrame> res8;
void cal_index_minmax8(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max8) {
		m_rankValue_max8 = m_rankValue;
		if (m_centerDis < m_centerDis_min8) {
			m_centerDis_min8 = m_centerDis;
			res8.push_back(ImportantFrame(index, filepath, m_rankValue_max8, m_centerDis_min8));
		}
	}
}
///////9////////////
float m_rankValue_max9 = 0;
float m_centerDis_min9 = 1;

vector<ImportantFrame> res9;
void cal_index_minmax9(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max9) {
		m_rankValue_max9 = m_rankValue;
		if (m_centerDis < m_centerDis_min9) {
			m_centerDis_min9 = m_centerDis;
			res9.push_back(ImportantFrame(index, filepath, m_rankValue_max9, m_centerDis_min9));
		}
	}
}
///////10////////////
float m_rankValue_max10 = 0;
float m_centerDis_min10= 1;

vector<ImportantFrame> res10;
void cal_index_minmax10(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max10) {
		m_rankValue_max10 = m_rankValue;
		if (m_centerDis < m_centerDis_min10) {
			m_centerDis_min10 = m_centerDis;
			res10.push_back(ImportantFrame(index, filepath, m_rankValue_max10, m_centerDis_min10));
		}
	}
}

///////11////////////
float m_rankValue_max11 = 0;
float m_centerDis_min11 = 1;

vector<ImportantFrame> res11;
void cal_index_minmax11(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max11) {
		m_rankValue_max11 = m_rankValue;
		if (m_centerDis < m_centerDis_min11) {
			m_centerDis_min11 = m_centerDis;
			res11.push_back(ImportantFrame(index, filepath, m_rankValue_max11, m_centerDis_min11));
		}
	}
}

///////12////////////
float m_rankValue_max12 = 0;
float m_centerDis_min12 = 1;

vector<ImportantFrame> res12;
void cal_index_minmax12(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max12) {
		m_rankValue_max12 = m_rankValue;
		if (m_centerDis < m_centerDis_min12) {
			m_centerDis_min12 = m_centerDis;
			res12.push_back(ImportantFrame(index, filepath, m_rankValue_max12, m_centerDis_min12));
		}
	}
}

///////13////////////
float m_rankValue_max13 = 0;
float m_centerDis_min13 = 1;

vector<ImportantFrame> res13;
void cal_index_minmax13(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max13) {
		m_rankValue_max13 = m_rankValue;
		if (m_centerDis < m_centerDis_min13) {
			m_centerDis_min13 = m_centerDis;
			res13.push_back(ImportantFrame(index, filepath, m_rankValue_max13, m_centerDis_min13));
		}
	}
}


///////14////////////
float m_rankValue_max14 = 0;
float m_centerDis_min14 = 1;

vector<ImportantFrame> res14;
void cal_index_minmax14(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max14) {
		m_rankValue_max14 = m_rankValue;
		if (m_centerDis < m_centerDis_min14) {
			m_centerDis_min14 = m_centerDis;
			res14.push_back(ImportantFrame(index, filepath, m_rankValue_max14, m_centerDis_min14));
		}
	}
}

///////15////////////
float m_rankValue_max15 = 0;
float m_centerDis_min15 = 1;

vector<ImportantFrame> res15;
void cal_index_minmax15(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max15) {
		m_rankValue_max15 = m_rankValue;
		if (m_centerDis < m_centerDis_min15) {
			m_centerDis_min15 = m_centerDis;
			res15.push_back(ImportantFrame(index, filepath, m_rankValue_max15, m_centerDis_min15));
		}
	}
}
///////16////////////
float m_rankValue_max16 = 0;
float m_centerDis_min16 = 1;

vector<ImportantFrame> res16;
void cal_index_minmax16(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max16) {
		m_rankValue_max16 = m_rankValue;
		if (m_centerDis < m_centerDis_min16) {
			m_centerDis_min16 = m_centerDis;
			res16.push_back(ImportantFrame(index, filepath, m_rankValue_max16, m_centerDis_min16));
		}
	}
}
///////17////////////
float m_rankValue_max17 = 0;
float m_centerDis_min17 = 1;

vector<ImportantFrame> res17;
void cal_index_minmax17(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max17) {
		m_rankValue_max17 = m_rankValue;
		if (m_centerDis < m_centerDis_min17) {
			m_centerDis_min17 = m_centerDis;
			res17.push_back(ImportantFrame(index, filepath, m_rankValue_max17, m_centerDis_min17));
		}
	}
}
///////18////////////
float m_rankValue_max18 = 0;
float m_centerDis_min18 = 1;

vector<ImportantFrame> res18;
void cal_index_minmax18(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max18) {
		m_rankValue_max18 = m_rankValue;
		if (m_centerDis < m_centerDis_min18) {
			m_centerDis_min18 = m_centerDis;
			res18.push_back(ImportantFrame(index, filepath, m_rankValue_max18, m_centerDis_min18));
		}
	}
}
///////19////////////
float m_rankValue_max19 = 0;
float m_centerDis_min19 = 1;

vector<ImportantFrame> res19;
void cal_index_minmax19(int index, string imagename, float m_rankValue, float m_centerDis) {

	char filepath[1000];
	sprintf(filepath, "%s/%s", IMAGEPATH, imagename);
	if (m_rankValue >= m_rankValue_max19) {
		m_rankValue_max19 = m_rankValue;
		if (m_centerDis < m_centerDis_min19) {
			m_centerDis_min19 = m_centerDis;
			res19.push_back(ImportantFrame(index, filepath, m_rankValue_max19, m_centerDis_min19));
		}
	}
}


int main() {
	char imagename[1000];
	ifstream fin("C:/Users/lijinxi/Documents/Visual Studio 2015/Projects/INRIA_shf_adaboost/INRIA_shf_adaboost/result3.txt");
	if (!fin) {
		cerr << "fail" << endl;
		return -1;
	}
	char filepath[1000];
	int index;
	float m_rankValue, m_centerDis;
	char postxt1[400];
	sprintf_s(postxt1, "important_frame_3.txt");
	ofstream pos_result1(postxt1, ios::app);
	int num = 0;
	while (!fin.eof()) {
		fin >> index >> imagename >> m_rankValue >> m_centerDis;
		if (index == 0) {
			cal_index_minmax0(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 1) {
			cal_index_minmax1(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 2) {
			cal_index_minmax2(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 3) {
			cal_index_minmax3(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 4) {
			cal_index_minmax4(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 5) {
			cal_index_minmax5(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 6) {
			cal_index_minmax6(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 7) {
			cal_index_minmax7(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 8) {
			cal_index_minmax8(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 9) {
			cal_index_minmax9(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 10) {
			cal_index_minmax10(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 11) {
			cal_index_minmax11(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 12) {
			cal_index_minmax12(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 13) {
			cal_index_minmax13(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 14) {
			cal_index_minmax14(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 15) {
			cal_index_minmax15(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 16) {
			cal_index_minmax16(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 17) {
			cal_index_minmax17(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 18) {
			cal_index_minmax18(index, imagename, m_rankValue, m_centerDis);
		}
		else if (index == 19) {
			cal_index_minmax19(index, imagename, m_rankValue, m_centerDis);
		}
		else {
			continue;
		}
		
	}
	fin.close();

	pos_result1<< res0[res0.size() - 1].index<<"\t" << res0[res0.size() - 1].imagename << "\t" << res0[res0.size() - 1].m_rankValue << "\t" << res0[res0.size() - 1].m_centerDis << endl;
	pos_result1 << res1[res1.size() - 1].index << "\t" << res1[res1.size() - 1].imagename << "\t" << res1[res1.size() - 1].m_rankValue << "\t" << res1[res1.size() - 1].m_centerDis << endl;
	pos_result1 << res2[res2.size() - 1].index << "\t" << res2[res2.size() - 1].imagename << "\t" << res2[res2.size() - 1].m_rankValue << "\t" << res2[res2.size() - 1].m_centerDis << endl;
	pos_result1 << res3[res3.size() - 1].index << "\t" << res3[res3.size() - 1].imagename << "\t" << res3[res3.size() - 1].m_rankValue << "\t" << res3[res3.size() - 1].m_centerDis << endl;
	pos_result1 << res4[res4.size() - 1].index << "\t" << res4[res4.size() - 1].imagename << "\t" << res4[res4.size() - 1].m_rankValue << "\t" << res4[res4.size() - 1].m_centerDis << endl;
	pos_result1 << res5[res5.size() - 1].index << "\t" << res5[res5.size() - 1].imagename << "\t" << res5[res5.size() - 1].m_rankValue << "\t" << res5[res5.size() - 1].m_centerDis << endl;
	pos_result1 << res6[res6.size() - 1].index << "\t" << res6[res6.size() - 1].imagename <<"\t" << res6[res6.size() - 1].m_rankValue << "\t" << res6[res6.size() - 1].m_centerDis << endl;
	pos_result1 << res7[res7.size() - 1].index <<"\t" << res7[res7.size() - 1].imagename << "\t" << res7[res7.size() - 1].m_rankValue << "\t" << res7[res7.size() - 1].m_centerDis << endl;
	pos_result1 << res8[res8.size() - 1].index << "\t" << res8[res8.size() - 1].imagename << "\t" << res8[res8.size() - 1].m_rankValue << "\t" << res8[res8.size() - 1].m_centerDis << endl;
	pos_result1 << res9[res9.size() - 1].index << "\t" << res9[res9.size() - 1].imagename << "\t" << res9[res9.size() - 1].m_rankValue << "\t" << res9[res9.size() - 1].m_centerDis << endl;
	
	pos_result1 << res10[res10.size() - 1].index << "\t" << res10[res10.size() - 1].imagename << "\t" << res10[res10.size() - 1].m_rankValue <<"\t" << res10[res10.size() - 1].m_centerDis << endl;
	pos_result1 << res11[res11.size() - 1].index << "\t" << res11[res11.size() - 1].imagename << "\t" << res11[res11.size() - 1].m_rankValue << "\t" << res11[res11.size() - 1].m_centerDis << endl;
	pos_result1 << res12[res12.size() - 1].index << "\t" << res12[res12.size() - 1].imagename << "\t" << res12[res12.size() - 1].m_rankValue << "\t" << res12[res12.size() - 1].m_centerDis << endl;
	pos_result1 << res13[res13.size() - 1].index << "\t" << res13[res13.size() - 1].imagename << "\t" << res13[res13.size() - 1].m_rankValue << "\t" << res13[res13.size() - 1].m_centerDis << endl;
	pos_result1 << res14[res14.size() - 1].index << "\t" << res14[res14.size() - 1].imagename << "\t" << res14[res14.size() - 1].m_rankValue << "\t" << res14[res14.size() - 1].m_centerDis << endl;
	pos_result1 << res15[res15.size() - 1].index << "\t" << res15[res15.size() - 1].imagename << "\t" << res15[res15.size() - 1].m_rankValue << "\t" << res15[res15.size() - 1].m_centerDis << endl;
	pos_result1 << res16[res16.size() - 1].index << "\t" << res16[res16.size() - 1].imagename << "\t" << res16[res16.size() - 1].m_rankValue << "\t" << res16[res16.size() - 1].m_centerDis << endl;
	pos_result1 << res17[res17.size() - 1].index << "\t" << res17[res17.size() - 1].imagename << "\t" << res17[res17.size() - 1].m_rankValue <<"\t" << res17[res17.size() - 1].m_centerDis << endl;
	pos_result1 << res18[res18.size() - 1].index << "\t" << res18[res18.size() - 1].imagename << "\t" << res18[res18.size() - 1].m_rankValue <<"\t" << res18[res18.size() - 1].m_centerDis << endl;
	pos_result1 << res19[res19.size() - 1].index << "\t" << res19[res19.size() - 1].imagename << "\t" << res19[res19.size() - 1].m_rankValue << "\t" << res19[res19.size() - 1].m_centerDis << endl;


	//cout << res2[res2.size()-1].index<<" "<< res2[res2.size()-1].imagename<<" "<< res2[res2.size() - 1].m_rankValue <<" "<< res2[res2.size() - 1].m_centerDis << endl;
	//cout << res3[res3.size() - 1].index << " " << res3[res3.size() - 1].imagename << " " << res3[res3.size() - 1].m_rankValue << " " << res3[res3.size() - 1].m_centerDis << endl;
	//
	//

////////////////////输出html 使用下排代码即可///////////
	ifstream fin1("C:/Users/lijinxi/Documents/Visual Studio 2015/Projects/INRIA_shf_adaboost/INRIA_shf_adaboost/important_frame_3.txt");
	if (!fin1) {
		cerr << "fail" << endl;
		return -1;
	}
	char postxt[400];
	sprintf_s(postxt, "kdis_3.html");
	ofstream pos_result(postxt, ios::app);
	pos_result << "<html>\n";
	pos_result << "<table>\n";
	pos_result << "<tr>\n";
	while (!fin1.eof()) {
		fin1 >> index >> imagename >> m_rankValue >> m_centerDis ;
		pos_result << "<td>" << "<img src= \"" << imagename << "\", width=100,height=100>   </td>" << endl;
	
	}
	fin1.close();
	
	pos_result << "</tr>\n";
	pos_result << "</table>\n";
	pos_result << "</html>\n";
	cout << "finish" << endl;
	_getch();
	return 0;
}

