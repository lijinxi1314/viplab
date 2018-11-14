
#pragma once
#include "AdaBooster.h"
#include "CrossValidator.h"
#include "FeatureParser.h"
#include "FeatureVector.h"
#include "sorting.h"
#include "StrongClassifier.h"
#include "TrainingData.h"
#include "WeakClassifier.h"
#include "Element.h"
#include <iostream>
#include <fstream>
#include<stdio.h>
#include<iostream>
#include "ConfidenceCell.h"
#include "ConfidenceMap.h"
using namespace std;
#include <string>
#include "opencv2/opencv.hpp"
using namespace cv;

//CLASSIFIER ��
#define TESTCLASSIFIER 3
//�̹��� ����

#define   WIDTH   64//64
#define HEIGHT   128//128
#define   ORIGINAL_WINDOW_SIZE_X   64
#define   ORIGINAL_WINDOW_SIZE_Y   128


//#define   TR_IMG_PER_CLASS   100

#define   TR_IMG_PER_CLASS_POSITIVE   924
#define   TR_IMG_PER_CLASS_NEGATIVE   1499
//#define	TR_POS_DIR "F:/Pedestrian detection/Pedestrian detection/PedestrianDetection/face/trainingSet/faces"
#//define	TR_NEG_DIR "F:/Pedestrian detection/Pedestrian detection/PedestrianDetection/face/trainingSet/nonFaces"

#define	TR_POS_DIR "F:/MIT/MIT/positive"
#define	TR_NEG_DIR "F:/MIT/MIT/negative1"


//#define	TR_POS_DIR "F:/MIT/MIT/positive"
//#define	TR_NEG_DIR "F:/MIT/MIT/negative1"

//���Ǵ��� �� ��� ����
#define	BAR		8
#define	MAXCOLOR	255
#define	QUANTLEVEL	16

//ó�� ��� ����
#define	DONE 1
#define	FAIL 0


vector<Element> extractFeature(Mat integralImg);
Mat calculateIntegralFrom(Mat input);
float calMaskfromIntegral(Mat integral, int x, int y, int w, int h);
void cal_confiValue(int s_x, int s_y, int e_x, int e_y, int _type, float err);
void draw_confidenceMap(vector<ConfidenceCell> cells, char* ofilename);
void generateConfMapWithTop(vector<ConfidenceCell> cells, char* ofilename, int K);

//11-10
StrongClassifier strongClassifier;

typedef struct {
	int x;
	int y;
} POINT;

typedef struct {
	int x; //���� x��ǥ
	int y; //���� y��ǥ
	int w; //�ʺ�
	int h; //����
	int cx;
	int cy;
	int rank;
	float conf; //confidence
	float error;
	int id;
	//   int sx; //step-size x
	//   int sy; //step-size y
}Block;

typedef struct {
	Block* comb;
	float* weights;
	int numCom;
}MSHF;



typedef struct {
	int x;
	int y;
	float confidencevalue;

}CellPosition;


ConfidenceCell cmap[28][28];
//ConfidenceMap confidence_map;

//////////////////////
TrainingData td;
//FeatureParser fp;
//string ftr_file = "haarfeature.txt";
AdaBooster adaboost;

int main() {
	//cout << "�ڵ� �����Ϸ�" << endl;


	/*
	1. feature �Է�

	//feature�� �� �о�� Ȯ�� �Ϸ�
	*/
	//fp.parseFtrVectors(td, ftr_file);
	//cout << endl;

	//cout <<"td.dimension(): "<< td.dimensions() << endl;
	//cout << "td.size(): " << td.size() << endl;





	//���� main �Լ�
	//AdaBooster adaboost;
	//adaboost.getStrongClassifier(td,10);

	/*
	�� ���� ����� Ȯ��
	*/

	/*
	1. �� ���� : feature ����
	*/
	//�󱼰��� - �ƴٺν�Ʈ.

	////positive ���� �Է� => Ư¡ ����
	char filepath[300];
	//Mat* trImgs = new Mat[TR_IMG_PER_CLASS * 2];

	vector<pair<vector<Element>, int>> trData;
	for (int i = 1; i < TR_IMG_PER_CLASS_POSITIVE + 1; i++)
		//int i = 1;
	{
		/*if (i < 10)
			sprintf_s(filepath, "%s/face000%d.png", TR_POS_DIR, i);
		else if (i < 100)
			sprintf_s(filepath, "%s/face00%d.png", TR_POS_DIR, i);
		else
			sprintf_s(filepath, "%s/face0%d.png", TR_POS_DIR, i);*/
		sprintf(filepath, "%s/%d.bmp", TR_POS_DIR, i);
		cout << filepath << endl;

		/*
		�ٽ� ����
		*/
		//filepath = TMP;
		Mat img = imread(filepath, CV_LOAD_IMAGE_GRAYSCALE);
		//imshow("img", img);

		//////////////////////////////////
		Mat mat = calculateIntegralFrom(imread(filepath, CV_LOAD_IMAGE_GRAYSCALE));
		//trImgs.push_back(mat);
		//cout << mat.size() << endl;
		vector<Element> feature = extractFeature(mat);


		/*for (int j = 0; j < feature.size(); j++) {

		cout << " "<< feature.at(j).type;
		}
		cout << endl;*/

		//cout << "feature size" << feature.size() << endl;
		int label = 1;

		trData.push_back(make_pair(feature, label));
		//trdata[0] �ȿ� feature 190000��

		/*if (i == 1) {
		cout << "first feature value//1" << endl;
		cout << trData.at(0).first.at(0) << endl;
		}*/
	}
	//   cout << "trData.size" << trData.size() << endl;

	cout << endl << "positive �Ϸ�" << endl;

	////negative ���� �Է� => Ư¡ ����
	for (int i = 1; i < TR_IMG_PER_CLASS_NEGATIVE + 1; i++)
	{
		/*if (i < 10)
			sprintf_s(filepath, "%s/nonface000%d.png", TR_NEG_DIR, i);
		else if (i < 100)
			sprintf_s(filepath, "%s/nonface00%d.png", TR_NEG_DIR, i);
		else
			sprintf_s(filepath, "%s/nonface0%d.png", TR_NEG_DIR, i);*/

		sprintf(filepath, "%s/%d.bmp", TR_NEG_DIR, i);
		cout << filepath << endl;
		Mat mat = calculateIntegralFrom(imread(filepath, CV_LOAD_IMAGE_GRAYSCALE));

		vector<Element> feature = extractFeature(mat);
		//cout << "feature size" << feature.size() << endl;


		/*cout << i << "��°: ";
		for (int j = 0; j < feature.size(); j++) {

		cout << " "<< feature.at(j).type;
		}
		cout << endl;*/

		int label = -1;
		trData.push_back(make_pair(feature, label));
		//////////trdata�ȿ� feature type=1 ����
		///*for (int j = 0; j < feature.size(); j++) {
		//	if (feature.at(j).type == 1) {
		//		cout << "str_x : " << trData[0].first.at(j).start_x << " str_y : " << trData[0].first.at(j).start_y <<
		//			" end_x :" << trData[0].first.at(j).end_x << " end_y :" << trData[0].first.at(j).end_y << " type : " << trData[0].first.at(j).type << "\n" << endl;
		//	}

		//}*/

	}

	//cout << endl << "negative �Ϸ�" << endl;

	int featDim = trData[0].first.size();

	//	cout << "featDim " << featDim << endl; // feature->190736

	/*Mat trainData(2 * TR_IMG_PER_CLASS, featDim, CV_32FC1);
	Mat labels(2 * TR_IMG_PER_CLASS, 1, CV_32SC1);

	for (int i = 0; i < trainData.rows; i++)
	for (int j = 0; j < trainData.cols; j++)
	{
	trainData.at<float>(i, j) = trData[i].first[j];
	labels.at<int>(i, 0) = trData[i].second;
	}*/

	//int imageH = integralI.length;
	//int imageW = integralI[0].length;

	//////////////////////////////////////////////////////////////////�ڵ� ����

	vector<float> ftrs;

	//   cout << "trData.size" << trData.size() << endl;
	// �ٽ� : featDim(feature dimension)�� �о(Ư¡��) feature_vector�� ������
	//�� feature�� ������ŭ ������
	for (int i = 0; i < trData.size(); i++) {


		//for (int j = 0; j < featDim; j++) {
		//   
		//   ftrs.push_back(trData[i].first[j]);//�ٽ� : ������ trData ���� i ��° feature vector ���� ftr �ȿ� ����

		//   ///
		//   /*if (i==0&&j == 0) {
		//      cout << "first feature value//2" << endl;
		//      cout << ftrs.at(0) << endl;
		//   }*/
		//}


		//set as a POSITIVE or NEGATIVE feature
		//cout << "trdat[i].first.size: " << trData[i].first.size() << endl;


		FeatureVector fv(trData[i].first, trData[i].second);
		//
		////feature �߰�
		////erro �˻�
		//cout << "feature size: " << fv.size() << endl;
		if (!td.addFeature(fv))
			printf("ERROR: feature vector incorrect size!\n");


	}

		//���� main �Լ�
		AdaBooster adaboost;
		//adaboost.getStrongClassifier(td, 10);// weak ������ ��ȯ
		
		/*
		11-10 weak classifier 10 ���� ���� confidence value ���
		*/
		////////////////////////////////*********************************************************************************
		strongClassifier= adaboost.getStrongClassifier(td,TESTCLASSIFIER);
	
		/*int m= strongClassifier.weakClassifiers().size();
		for (int j = 0; j < m; j++) {
			cout <<" "<< strongClassifier.weakClassifiers().at(j).threshold<< endl;
		}*/	
		////////////////////////////////*********************************************************************************
	
		//////////////////////////////////
		//weakset�� start_x, start_y, end_x, end_y, acc ���
		vector<WeakClassifier>weakList=strongClassifier.weakClassifiers();
		
		//���Ȯ��
		cout << endl;
		for (int i=0; i < weakList.size(); i++) {
			
			weakList.at(i).printClassifier();
			weakList.at(i).writeClassifier("weakclassifier_information_1113_400_toptest.txt");
		}
		cout << endl;
		
		//////////////////////////////////
		//confidence value  ���
	
		//�ʱ�ȭ
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				cmap[i][j].weak_count = 0;
				cmap[i][j].total_acc = 0;
				cmap[i][j].confidence_value = 0;
				cmap[i][j].pos_x = i;
				cmap[i][j].pos_y = j;
			}
		}
	
		//1. ���� �б�
		ifstream fin("weakclassifier_information_1113_400_toptest.txt");  
		
	
		if (!fin) 
		{
			cerr << "fail" << endl;
			return -1;
		}
			
		float dimension, error, am;
		int start_x, start_y, end_x, end_y, type;
	
		while (!fin.eof()) {
			fin >> dimension >> start_x >> start_y >> end_x >> end_y >> type >> error >> am;
			cout << dimension <<"\t"<< start_x << "\t" 
				<< start_y << "\t" << end_x << "\t" << end_y << "\t" << type << "\t" << error << "\t" << am<<endl;
		
			//confidence value 
			cal_confiValue(start_x, start_y, end_x, end_y, type, error);
		
		
		}
	
		fin.close();
	
		//cell�ȿ� �ִ� total_acc�� weak_count�� �̿���, confidence value�� ���Ѵ�
		
		cout << endl;
	
		ofstream con_txt("confidence_information_1113_400_toptest.txt", ios::app);
	
		
	
		vector<ConfidenceCell> c_cells;
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				cmap[i][j].confidence_value = cmap[i][j].total_acc / cmap[i][j].weak_count;
				if (cmap[i][j].weak_count == 0) {
					cmap[i][j].confidence_value = 0;
				}
				c_cells.push_back(cmap[i][j]);
				//printf("cell[%d,%d], confidence_value: %f\t", i, j, cmap[i][j].confidence_value);
				con_txt << i << "\t" <<j<< "\t" << cmap[i][j].confidence_value<<endl;
				
			}
			cout << endl;
		}
		con_txt.close();
	
		char filepath1[300];
		char filepath2[300];
		sprintf(filepath1, "confidence_map_1113_400_test.bmp");
		sprintf(filepath2, "confidence_map_1113_400_TOPK_test.bmp");
	//	cout << cells.size() << endl;
		draw_confidenceMap(c_cells, filepath1);
		generateConfMapWithTop(c_cells, filepath2, 5);
		
	
	
		/////////////////draw confidence map
	
		//ifstream cin_txt("confidence_information.txt");
	
		//
		//if (!cin_txt)
		//{
		//	cerr << "fail" << endl;
		//	return -1;
		//}
		//int position_x, position_y;
		//float confidence_value;
		//while (!cin_txt.eof()) {
		//	cin_txt >> position_x >> position_y >> confidence_value ;
		////	cout << position_x<<"\t" << position_y << "\t" << confidence_value <<endl;
	
		//	//confidence value 
		//	draw_confidenceMap(position_x,position_y,confidence_value);
		//}
	
		//cin_txt.close();
		/////////////////////////////
	
		int x;
		cin >> x;
		return 0;
}



Mat calculateIntegralFrom(Mat input)
{
	Mat integralimg(Size(input.cols + 1, input.rows + 1), CV_32F); //integral image�� ���� Ư���� ����� 1�ȼ��� �����Ѵ�.

	for (int i = 0; i < integralimg.rows; i++)
		for (int j = 0; j < integralimg.cols; j++)
		{
			if (i == 0 || j == 0)
				integralimg.at<float>(i, j) = 0;
			else
				integralimg.at<float>(i, j) = input.at<unsigned char>(i - 1, j - 1);
		}

	for (int i = 0; i < input.rows + 1; i++)
		for (int j = 0; j < input.cols + 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			else if (i == 0)
			{
				integralimg.at<float>(i, j) += integralimg.at<float>(i, j - 1);
			}
			else if (j == 0)
			{
				integralimg.at<float>(i, j) += integralimg.at<float>(i - 1, j);
			}
			else
			{
				integralimg.at<float>(i, j) += (integralimg.at<float>(i - 1, j) +
					integralimg.at<float>(i, j - 1) - integralimg.at<float>(i - 1, j - 1));
			}
		}
	return integralimg;
}

void drawCombineMSHF(MSHF m, char* filename)
{
	IplImage* confMapImg = cvCreateImage(cvSize(WIDTH, HEIGHT), IPL_DEPTH_8U, 3);
	for (int i = 0; i < confMapImg->height; i++)
		for (int j = 0; j < confMapImg->width; j++)
		{
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 2] = (unsigned char)0;
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 1] = (unsigned char)0;
			confMapImg->imageData[(i * confMapImg->width + j) * 3] = (unsigned char)0;
		}

	for (int i = 0; i < m.numCom; i++)
	{
		if (m.weights[i] > 0)
		{
			cvRectangle(confMapImg, CvPoint(m.comb[i].x + 1, m.comb[i].y + 1),
				CvPoint(m.comb[i].x + m.comb[i].w - 1, m.comb[i].y + m.comb[i].h - 1),
				Scalar(0, 0, 255), 3, 8, 0);
		}
		else
		{
			cvRectangle(confMapImg, CvPoint(m.comb[i].x + 1, m.comb[i].y + 1),
				CvPoint(m.comb[i].x + m.comb[i].w - 1, m.comb[i].y + m.comb[i].h - 1),
				Scalar(255, 0, 0), 3, 8, 0);
		}
	}

	cvSaveImage(filename, confMapImg);
	cvReleaseImage(&confMapImg);
}


vector<Element> extractFeature(Mat integralImg)
{
	vector<Element> vec;
	int featType[5][2] = { { 1, 2 },{ 1, 3 },{ 2, 1 },{ 3, 1 },{ 2, 2 } };
		int windowScale_X = integralImg.cols / ORIGINAL_WINDOW_SIZE_X;
		int windowScale_Y = integralImg.rows / ORIGINAL_WINDOW_SIZE_Y;
	//int windoScale = integralImg.cols  ;
	//int windowScale = 1;
	int imageH = integralImg.rows;
	int imageW = integralImg.cols;
	//imageH 25 imageW25  windowScale 1
	//	cout <<"Log: "<< imageH << " " << imageW << " " << windowScale << endl;  
		int maxH = imageH / windowScale_Y;
		int maxW = imageW / windowScale_X;
	//int maxH = imageH;
	//int maxW = imageW;
	int count = 0;
	int index = 0;
	int n = 0;

	for (int type = 0; type < 5; type++) {
		int windowCountH = featType[type][0];
		int windowCountW = featType[type][1];
		for (int featH = 1; featH <= (maxH / windowCountH); featH++) {
			for (int featW = 1; featW <= (maxW / windowCountW); featW++) {
				for (int y = 0; y < imageH - (featH * windowScale_Y * windowCountH - 1); y += windowScale_Y) {
					for (int x = 0; x < imageW - (featW * windowScale_X * windowCountW - 1); x += windowScale_X) {
						//cout << index << endl;
						//cout << "windowScale_X" << windowScale_X << "windowScale_Y: " << windowScale_Y << endl;
						int width = featW * windowScale_X;
						int height = featH * windowScale_Y;
						float result = 0;
						// type 1
						if (windowCountH == 1 && windowCountW == 2) {
							int sum1 = calMaskfromIntegral(integralImg, x, y, width, height);
							int sum2 = calMaskfromIntegral(integralImg, x + width, y, width, height);
							result = sum1 - sum2;
						}
						// type 2
						else if (windowCountH == 1 && windowCountW == 3) {
							int sum1 = calMaskfromIntegral(integralImg, x, y, width, height);
							int sum2 = calMaskfromIntegral(integralImg, x + width, y, width, height);
							int sum3 = calMaskfromIntegral(integralImg, x + width * 2, y, width, height);
							result = sum1 - sum2 + sum3;
						}
						// type 3
						else if (windowCountH == 2 && windowCountW == 1) {
							int sum1 = calMaskfromIntegral(integralImg, x, y, width, height);
							int sum2 = calMaskfromIntegral(integralImg, x, y + height, width, height);
							result = sum1 - sum2;
						}
						// type 4
						else if (windowCountH == 3 && windowCountW == 1) {
							int sum1 = calMaskfromIntegral(integralImg, x, y, width, height);
							int sum2 = calMaskfromIntegral(integralImg, x, y + height, width, height);
							int sum3 = calMaskfromIntegral(integralImg, x, y + height * 2, width, height);
							result = sum1 - sum2 + sum3;
						}
						// type 5
						else {
							int sum1 = calMaskfromIntegral(integralImg, x, y, width, height);
							int sum2 = calMaskfromIntegral(integralImg, x, y + height, width, height);
							int sum3 = calMaskfromIntegral(integralImg, x + width, y, width, height);
							int sum4 = calMaskfromIntegral(integralImg, x + width, y + height, width, height);
							result = sum1 - sum2 - sum3 + sum4;
						}

						/*if (type == 4) {
							count++;
						}*/
						
						count++;
						//   cout << endl << "result: " << result << endl;

						//���Ȯ��
						//cout << "result: " << result << endl;
						/*	cout << "x: " << x << endl;
						cout << "y: " << y << endl;
						cout << "type: " << type << endl;*/

						//cout << "count(index):" << count << endl;

						Element element(x, y,width,height, type, result);
						//vec.push_back(result);

						/*if (element.type ==0) {
							cout <<"str_x : "<< element.start_x << " str_y : " << element.start_y
								<<" width : " << width<<" height: "<< height
								 <<" end_x :"<<element.end_x
								<<" end_y :"<< element.end_y<< " type : " << element.type << "\n"<<endl;
						}*/
						//	cout << n << endl;
						vec.push_back(element);

					}
				}
			}

		}


	}
	//cout << n << endl;

	//for (int i = 0; i < vec.size(); i++) {
	//	//���Ȯ��
	//	cout << i<<" ��° type: "<<vec.at(i).type << endl;
	//}
	//cout << "size " << vec.size() << endl;
	cout << count << endl;
	return vec;

}

float calMaskfromIntegral(Mat integral, int x, int y, int w, int h)
{
	//cout << "integral" << endl;
	int endX = x + w > ORIGINAL_WINDOW_SIZE_X ? 63 : x + w;
	int endY = y + h > ORIGINAL_WINDOW_SIZE_Y ? 127 : y + h;
	int sum = integral.at<float>(endY, endX);
	sum -= x > 0 ? integral.at<float>(endY, x - 1) : 0;
	sum -= y > 0 ? integral.at<float>(y - 1, endX) : 0;
	sum += x > 0 && y > 0 ? integral.at<float>(y - 1, x - 1) : 0;
	//cout << "sum " <<sum << endl;
	return sum;
}

void cal_confiValue(int s_x, int s_y, int e_x, int e_y, int _type, float err) {

	/*
	1. ���  c(i,j)�� ���ؼ�
	2. weak �ִ��� �Ǵ�
	3. ����ִٸ� �ش� weak classifier �� error ���� �޾ƿ�
	*/

	//1. i, j �ִ� �� �Ǵ�

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			int cell_x = i, cell_y = j;

			//Ȯ��

			if (cell_x <= e_x &&cell_x > s_x) {
				if (cell_y >= s_y &&cell_y < e_y) {
					cmap[cell_x][cell_y].weak_count++;
					cmap[cell_x][cell_y].total_acc += 1 - err;
				}
			}
		}
	}


}
bool isWithRectBoundary;
void draw_confidenceMap(vector<ConfidenceCell> cells, char* ofilename) {
	/*for (int i = 0; i < cells.size(); i++) {
	cout << cells.at(i).pos_x <<"\t"<< cells.at(i).pos_y << "\t" << cells.at(i).confidence_value << endl;
	}*/
	if (cells.size() == 0) {
		cout << "fail" << endl;
	}

	cv::Scalar pixcolors[16] = {
		cv::Scalar(255, 0, 0),
		cv::Scalar(255, 34,	34),
		cv::Scalar(255, 68,	68),
		cv::Scalar(255, 102, 102),
		cv::Scalar(255, 136, 136),
		cv::Scalar(255, 170, 170),
		cv::Scalar(255, 204, 204),
		cv::Scalar(255, 238, 238),
		cv::Scalar(238, 238, 255),
		cv::Scalar(204, 204, 255),
		cv::Scalar(170, 170, 255),
		cv::Scalar(136, 136, 255),
		cv::Scalar(102, 102, 255),
		cv::Scalar(68, 68, 255),
		cv::Scalar(34, 34, 255),
		cv::Scalar(0,  0, 255)
	};
	float** confMap = new float*[HEIGHT];
	//	int** countMap = new int*[HEIGHT];

	for (int i = 0; i < HEIGHT; i++)
	{
		confMap[i] = new float[WIDTH];
		//		countMap[i] = new int[WIDTH];
	}

	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			confMap[i][j] = 0.0f;
			//		countMap[i][j] = 0;
		}
	//////////////////////////////////////////////////////
	for (int i = 0; i < cells.size(); i++)
	{
		for (int y = cells[i].pos_y; y < cells[i].pos_y + 1; y++)
			for (int x = cells[i].pos_x; x < cells[i].pos_x + 1; x++)
			{
				confMap[y][x] = cells[i].confidence_value;
				//	cout <<"x: "<< cells[i].pos_x <<"y: "<< cells[i].pos_y << "confidence value" << confMap[y][x] << endl;
			}

	}


	float maxConf = 0;
	float minConf = 1000000000.0f;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			//	confMap[i][j] = cells[i].confidence_value;

			maxConf = confMap[i][j] > maxConf ? confMap[i][j] : maxConf;
			minConf = confMap[i][j] < minConf ? confMap[i][j] : minConf;
		}
	}
	//	cout << "max:" << maxConf <<" min: "<<minConf<< endl;

	float rangeConf = (maxConf - minConf) / 2;

	IplImage* confMapImg = cvCreateImage(cvSize(WIDTH + 2 * BAR, HEIGHT), IPL_DEPTH_8U, 3);
	for (int i = 0; i < confMapImg->height; i++)
		for (int j = 0; j < confMapImg->width; j++)
		{
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 2] = (unsigned char)0;
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 1] = (unsigned char)0;
			confMapImg->imageData[(i * confMapImg->width + j) * 3] = (unsigned char)0;
		}

	for (int i = 0; i < confMapImg->height; i++)
		for (int j = WIDTH; j < WIDTH + BAR; j++)
		{
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 2] = (unsigned char)240;
			confMapImg->imageData[(i * confMapImg->width + j) * 3 + 1] = (unsigned char)240;
			confMapImg->imageData[(i * confMapImg->width + j) * 3] = (unsigned char)240;

		}


	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			if (confMap[i][j] >= 0)
			{
				int curLevel = (int)((float)(QUANTLEVEL - 1)*(float)(confMap[i][j] - minConf) / (float)(maxConf - minConf));
				Scalar pix = pixcolors[curLevel];

				confMapImg->imageData[(i * confMapImg->width + j) * 3 + 2] = (unsigned char)pix[2];
				confMapImg->imageData[(i * confMapImg->width + j) * 3 + 1] = (unsigned char)pix[1];
				confMapImg->imageData[(i * confMapImg->width + j) * 3] = (unsigned char)pix[0];

				//				cout << "curLEVEL" << curLevel << " "<< pix[0]<<endl;
				//				cout << "confMapImg: " << confMapImg->imageData[(i * confMapImg->width + j) * 3] << endl;

			}
		}

	////BAR
	for (int i = 0; i < QUANTLEVEL; i++)
	{
		int stepHeight = HEIGHT / QUANTLEVEL;
		int startY = HEIGHT - stepHeight*(i + 1);
		int endY = HEIGHT - stepHeight*(i);
		for (int y = startY; y < endY; y++)
			for (int x = WIDTH + BAR; x < WIDTH + BAR * 2; x++)
			{
				Scalar pix = pixcolors[i];
				confMapImg->imageData[(y * confMapImg->width + x) * 3 + 2] = (unsigned char)pix[2];
				confMapImg->imageData[(y * confMapImg->width + x) * 3 + 1] = (unsigned char)pix[1];
				confMapImg->imageData[(y * confMapImg->width + x) * 3] = (unsigned char)pix[0];
			}
	}
	if (isWithRectBoundary)
	{

		for (int i = 0; i < cells.size(); i++)
		{
			POINT sx, ex;
			sx.x = cells[i].pos_x;
			sx.y = cells[i].pos_y;
			ex.x = cells[i].pos_x + 1 > WIDTH ? WIDTH - 1 : cells[i].pos_x + 1;
			ex.y = cells[i].pos_y + 1 > HEIGHT ? HEIGHT - 1 : cells[i].pos_y + 1;

			cvRectangle(confMapImg, CvPoint(sx.x, sx.y),
				CvPoint(ex.x, ex.y),
				Scalar(255, 255, 0), 1, 8, 0);

		}
	}

	cvSaveImage(ofilename, confMapImg);
	cvReleaseImage(&confMapImg);
	//		return DONE;

	//////////////////////////////////////////////////////


}

void generateConfMapWithTop(vector<ConfidenceCell> cells, char* ofilename, int K) {
	if (cells.size() < K)
		cout << "Error: " << K << "is larger than #. of blocks " << cells.size() << endl;

	for (int i = 0; i< cells.size(); i++)
		for (int j = i + 1; j < cells.size(); j++)
		{
			if (cells[i].confidence_value < cells[j].confidence_value)
			{
				ConfidenceCell tmp;
				tmp = cells[i];
				cells[i] = cells[j];
				cells[j] = tmp;
			}
		}

	vector<ConfidenceCell> topKCell;
	for (int i = 0; i < K; i++)
	{
		topKCell.push_back(cells[i]);
		//	cout << " top confidence: " <<topKCell.at(i).confidence_value << endl;
	}
	draw_confidenceMap(topKCell, ofilename);


}