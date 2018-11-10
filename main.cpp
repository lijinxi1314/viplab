#include "AdaBooster.h"
#include "CrossValidator.h"
#include "FeatureParser.h"
#include "FeatureVector.h"
#include "sorting.h"
#include "StrongClassifier.h"
#include "TrainingData.h"
#include "WeakClassifier.h"
#include "Element.h"

#include<stdio.h>
#include<iostream>
using namespace std;
#include <string>
#include "opencv2/opencv.hpp"
using namespace cv;

//�̹��� ����
#define   WIDTH   64
#define HEIGHT   128
#define   ORIGINAL_WINDOW_SIZE   24

#define   TR_IMG_PER_CLASS   100

#define	TR_POS_DIR "F:/Pedestrian detection/Pedestrian detection/PedestrianDetection/face/trainingSet/faces"
#define	TR_NEG_DIR "F:/Pedestrian detection/Pedestrian detection/PedestrianDetection/face/trainingSet/nonFaces"

#define	te_pos_dir "c:/users/daseul/desktop/viplab/face/trainingset/testingexamples/faces"
#define	te_neg_dir "c:/users/daseul/desktop/viplab/face/trainingset/testingexamples/nonfaces"

//#define	TR_POS_DIR "F:/MIT/MIT/positive"
//#define	TR_NEG_DIR "F:/MIT/MIT/negative1"


vector<Element> extractFeature(Mat integralImg);
Mat calculateIntegralFrom(Mat input);
float calMaskfromIntegral(Mat integral, int x, int y, int w, int h);

//11-10
StrongClassifier strongClassifier;

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
	for (int i = 1; i < TR_IMG_PER_CLASS + 1; i++)
		//int i = 1;
	{
		if (i < 10)
			sprintf_s(filepath, "%s/face000%d.png", TR_POS_DIR, i);
		else if (i < 100)
			sprintf_s(filepath, "%s/face00%d.png", TR_POS_DIR, i);
		else
			sprintf_s(filepath, "%s/face0%d.png", TR_POS_DIR, i);
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
		vector<Element> feature = extractFeature(mat);
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
	for (int i = 1; i < TR_IMG_PER_CLASS + 1; i++)
	{
		if (i < 10)
			sprintf_s(filepath, "%s/nonface000%d.png", TR_NEG_DIR, i);
		else if (i < 100)
			sprintf_s(filepath, "%s/nonface00%d.png", TR_NEG_DIR, i);
		else
			sprintf_s(filepath, "%s/nonface0%d.png", TR_NEG_DIR, i);
		cout << filepath << endl;
		Mat mat = calculateIntegralFrom(imread(filepath, CV_LOAD_IMAGE_GRAYSCALE));
		
		vector<Element> feature = extractFeature(mat);
		//cout << "feature size" << feature.size() << endl;
		int label = -1;
		trData.push_back(make_pair(feature, label));
	}

	//cout << endl << "negative �Ϸ�" << endl;

	int featDim = trData[0].first.size();
	//cout << "featDim " << featDim << endl;
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
	
	strongClassifier= adaboost.getStrongClassifier(td,3);
	//////////////////////////////////
	//weakset�� start_x, start_y, end_x, end_y, acc ���
	vector<WeakClassifier>weakList=strongClassifier.weakClassifiers();
	
	cout << endl;
	for (int i=0; i < weakList.size(); i++) {
		weakList.at(i).printClassifier();
	}
	cout << endl;
	
	//////////////////////////////////

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
	int featType[5][2] = { { 1, 2 }, { 1, 3 }, { 2, 1 }, { 3, 1 }, { 2, 2 } };
	int windowScale = integralImg.rows / ORIGINAL_WINDOW_SIZE;
	int imageH = integralImg.rows;
	int imageW = integralImg.cols;
	//imageH 25 imageW25  windowScale 1
	//cout <<"Log: "<< imageH << " " << imageW << " " << windowScale << endl;  
	int maxH = imageH / windowScale;
	int maxW = imageW / windowScale;
	int count = 0;
	int index = 0;

	for (int type = 0; type < 5; type++) {
		int windowCountH = featType[type][0];
		int windowCountW = featType[type][1];
		for (int featH = 1; featH <= (maxH / windowCountH); featH++) {
			for (int featW = 1; featW <= (maxW / windowCountW); featW++) {
				for (int y = 0; y < imageH - (featH * windowScale * windowCountH - 1); y += windowScale) {
					for (int x = 0; x < imageW - (featW * windowScale * windowCountW - 1); x += windowScale) {
						//cout << index << endl;
						int width = featW * windowScale;
						int height = featH * windowScale;
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
						
						count++;
						//   cout << count << endl;
						//   cout << endl << "result: " << result << endl;

						//���Ȯ��
						//cout << "result: " << result << endl;
						/*	cout << "x: " << x << endl;
						cout << "y: " << y << endl;
						cout << "type: " << type << endl;*/

						//cout << "count(index):" << count << endl;

						Element element(x, y, type, result);
						//vec.push_back(result);
						vec.push_back(element);

					}
				}
			}
		}
	}
	
	//cout << "size " << vec.size() << endl;
	return vec;

}

float calMaskfromIntegral(Mat integral, int x, int y, int w, int h)
{
	//cout << "integral" << endl;
	int endX = x + w > ORIGINAL_WINDOW_SIZE ? 23 : x + w;
	int endY = y + h > ORIGINAL_WINDOW_SIZE ? 23 : y + h;
	int sum = integral.at<float>(endY, endX);
	sum -= x > 0 ? integral.at<float>(endY, x - 1) : 0;
	sum -= y > 0 ? integral.at<float>(y - 1, endX) : 0;
	sum += x > 0 && y > 0 ? integral.at<float>(y - 1, x - 1) : 0;
	//cout << "sum " <<sum << endl;
	return sum;
}

float cal_confiValue(WeakClassifier weak) {

	float c;
	return c;
}