//本文件用于性别鉴定，主要是csv文件的读写
#include<opencv2/opencv.hpp>
#include "include.h"

#include<iostream>
#include<sstream>
#include<fstream>

//#include"stdafx.h"


//标注：早期的opencv使用IplImage作为图像类型，基本的转换关系如下：
//1.将ImlImage类型转为Mat类型
//	Mat::Mat(const IplImage* img,bool copyData=false);//默认情况下
//		新的Mat类型与原来的IplImage类型共享图像数据，转换只是创建一个Mat矩阵头，
//		当参数copyData为true后，就会复制整个图像数据。
//例如：IplImage* iplImg=cvLoadImage("lena.jpg);
//		Matmtx(iplImg);//IplImage* ->Mat共享数据
//		or:Mat mtx=ipImg;

using namespace std;
using namespace cv;
//通过Opencv进行性别识别的基本工具是FaceRecognizer.这是opencv2.0版本中国的一个基本人脸识别类，
//它封装了三种基本但是也是经典的人脸识别算法：基于PCA变换的人脸识别（EigenFaceRecognizer），
//基于Fisher变换的人脸识别（FisherFaceRecogbnizer）、基于局部二值化模式的人脸识别（LBPFaceRecognizer）
//上述算法可能都已近较老了，供学习使用

//数据集的收集
//下面例子，使用400张男性人脸图，400张女性人脸图
//测试集包含三个部分：男性样本，女性样本，测试样本
//使用CSV文件方法来批量读取训练样本

//编写一个批量读写csv文件的函数
//这里对算法部分进行新的改进批量读取函数必须一次性将所有训练样本读入内存中
//内存消耗较大，
//CSV文件：逗号分隔值(Comma-SeparatedValues,CSV,有时也称为字符分隔值，因为分隔字符也可以不是逗号），其文件以纯文本形式存储表格数据
//(数字和文本）。
#if 0
void ReadCsv(String& fileName, vector<Mat>& images, vector<int>& labels, char separator = ';')//这里的vector都是来自std命名空间内部的
{
	ifstream file(fileName.c_str(),ifstream::in);//以读入方式打开文件
	string line, path, label;
	while (getline(file, line))//从文本中读取一行字符，未指定符默认限定符为“/n”
	{
		stringstream lines(line);
		getline(lines, path, separator);//根据指定分割符进行分割，分为“路径+标号”
		getline(lines, label);
		if (!path.empty() && !label.empty())//读取成功，则将图片和对应标签压入对应容器中
		{
			images.push_back(imread(path, 1));//读取训练样本
			labels.push_back(atoi(label.c_str()));//读取训练样本标号

		}
	}
}
#else
//这里的好处在于不是直接存储图片，可以减小对内存的消耗
void ReadCsv(String& csvPath, vector<String>& trainPath, vector<int>& label, char separator = ';')
{
	string line, path, classLabel;
	ifstream file(csvPath.c_str(), ifstream::in);
	//加一个文件是否存在的判断
	if (!file)
	{
		string error_message = "No valid input file was given ,please check the given filename.";
		cout << error_message << endl;
	}
	while (getline(file, line))
	{
		stringstream lines(line);
		getline(lines, path, separator);
		getline(lines, classLabel);
		if (!path.empty() && !classLabel.empty())
		{
			trainPath.push_back(path);
			label.push_back(atoi(classLabel.c_str()));
		}
	}
}
//上面将Vector<Mat>改为Vector<String>,然后返回装有训练样本的所有路径的容器，需要时在根据其中的路径进行读取
#endif


#ifdef USE_SEX_DECT
int main(int argc, char** argv)
{
#if 0
	//加载性别识别的数据库
	string csvPath = "D:\\图像数据库\\性别数据库\\性别识别数据库—CAS-PEAL\\at.txt";
	vector<Mat> images;
	vector<int> labels;
	ReadCsv(csvPath, images, labels);
	cout << "运行状态确认" << endl;
#else
	//加载性别识别的数据库
	string csvPath = "D:\\图像数据库\\性别数据库\\性别识别数据库—CAS-PEAL\\at.txt";
	vector<String> vecTrainPath;
	vector<int> vecTrainLabel;
	ReadCsv(csvPath,vecTrainPath,vecTrainLabel);
	//使用迭代器输出
	cout << "运行状态OK" << endl;
#endif
#if 0

	Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	modelPCA->train(images, labels);
	modelPCA->save("D:\\图像数据库\\性别数据库\\性别识别数据库—CAS-PEAL\\PCA_Model.xml");

	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//modelFisher->train(images, labels);
	//modelFisher->save("D:\\图像数据库\\性别数据库\\性别识别数据库—CAS-PEAL\\Fisher_Model.xml");

	Mat testImage = imread("D:\\图像数据库\\性别数据库\\性别识别数据库—CAS-PEAL\\测试样本\\男性测试样本\\face_480.bmp",0);
	int predictPCA = modelPCA->predict(testImage);
	if (predictPCA)
		cout << "我是男人" << endl;
	else
		cout << "我是女人" << endl;
#else

#endif
////////////////////使用SVM方法进行性别区分/////////////////
//1、训练初始化-------提取HOG特征之前，需要初始化训练数据矩阵
	//初始化训练数据矩阵
	int iNumTrain = 800;
	Mat trainDataHog;
	Mat trainLabel = Mat::zeros(iNumTrain, 1, CV_32FC1);//切记SVM训练的数据必须是CV_32FC1格式，因此
	//要将标签矩阵trainLabel初始化为CV_32FC1格式

//提取图像HOG特征
	//循环读入所有的训练样本，提取HOG特征，放在训练数据矩阵中
	Mat imageSrc;
	for (int i = 0; i < iNumTrain; i++)
	{
		imageSrc = imread(vecTrainPath[i].c_str(), 1);//从vecTrainPath容器内循环读入样本
		resize(imageSrc, imageSrc, Size(64, 64));//尺寸归一化为64*64，参考一个关于HOG特征的博客，64*64不一定是一个最优尺寸
		HOGDescriptor *hog = new HOGDescriptor(cvSize(64, 64), cvSize(16, 16),//计算出HOG特征，根据Opencv来计算
			cvSize(8, 8), cvSize(8, 8), 9);
		vector < float> descriptor;
		hog->compute(imageSrc, descriptor, Size(1, 1), Size(0, 0));
		if (i == 0)
		{
			trainDataHog = Mat::zeros(iNumTrain, descriptor.size(), CV_32FC1);
		}
		int n = 0;
		for (vector<float>::iterator iter = descriptor.begin(); iter != descriptor.end(); iter++)
		{
			trainDataHog.at<float>(i, n) = *iter;
			n++;
		}
		trainLabel.at<float>(i, 0) = vecTrainLabel[i];
	}

	waitKey(60000);
	return 0;
}
#else
#endif