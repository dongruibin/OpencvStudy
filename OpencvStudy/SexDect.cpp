//���ļ������Ա��������Ҫ��csv�ļ��Ķ�д
#include<opencv2/opencv.hpp>
#include "include.h"

#include<iostream>
#include<sstream>
#include<fstream>

//#include"stdafx.h"


//��ע�����ڵ�opencvʹ��IplImage��Ϊͼ�����ͣ�������ת����ϵ���£�
//1.��ImlImage����תΪMat����
//	Mat::Mat(const IplImage* img,bool copyData=false);//Ĭ�������
//		�µ�Mat������ԭ����IplImage���͹���ͼ�����ݣ�ת��ֻ�Ǵ���һ��Mat����ͷ��
//		������copyDataΪtrue�󣬾ͻḴ������ͼ�����ݡ�
//���磺IplImage* iplImg=cvLoadImage("lena.jpg);
//		Matmtx(iplImg);//IplImage* ->Mat��������
//		or:Mat mtx=ipImg;

using namespace std;
using namespace cv;
//ͨ��Opencv�����Ա�ʶ��Ļ���������FaceRecognizer.����opencv2.0�汾�й���һ����������ʶ���࣬
//����װ�����ֻ�������Ҳ�Ǿ��������ʶ���㷨������PCA�任������ʶ��EigenFaceRecognizer����
//����Fisher�任������ʶ��FisherFaceRecogbnizer�������ھֲ���ֵ��ģʽ������ʶ��LBPFaceRecognizer��
//�����㷨���ܶ��ѽ������ˣ���ѧϰʹ��

//���ݼ����ռ�
//�������ӣ�ʹ��400����������ͼ��400��Ů������ͼ
//���Լ������������֣�����������Ů����������������
//ʹ��CSV�ļ�������������ȡѵ������

//��дһ��������дcsv�ļ��ĺ���
//������㷨���ֽ����µĸĽ�������ȡ��������һ���Խ�����ѵ�����������ڴ���
//�ڴ����Ľϴ�
//CSV�ļ������ŷָ�ֵ(Comma-SeparatedValues,CSV,��ʱҲ��Ϊ�ַ��ָ�ֵ����Ϊ�ָ��ַ�Ҳ���Բ��Ƕ��ţ������ļ��Դ��ı���ʽ�洢�������
//(���ֺ��ı�����
#if 0
void ReadCsv(String& fileName, vector<Mat>& images, vector<int>& labels, char separator = ';')//�����vector��������std�����ռ��ڲ���
{
	ifstream file(fileName.c_str(),ifstream::in);//�Զ��뷽ʽ���ļ�
	string line, path, label;
	while (getline(file, line))//���ı��ж�ȡһ���ַ���δָ����Ĭ���޶���Ϊ��/n��
	{
		stringstream lines(line);
		getline(lines, path, separator);//����ָ���ָ�����зָ��Ϊ��·��+��š�
		getline(lines, label);
		if (!path.empty() && !label.empty())//��ȡ�ɹ�����ͼƬ�Ͷ�Ӧ��ǩѹ���Ӧ������
		{
			images.push_back(imread(path, 1));//��ȡѵ������
			labels.push_back(atoi(label.c_str()));//��ȡѵ���������

		}
	}
}
#else
//����ĺô����ڲ���ֱ�Ӵ洢ͼƬ�����Լ�С���ڴ������
void ReadCsv(String& csvPath, vector<String>& trainPath, vector<int>& label, char separator = ';')
{
	string line, path, classLabel;
	ifstream file(csvPath.c_str(), ifstream::in);
	//��һ���ļ��Ƿ���ڵ��ж�
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
//���潫Vector<Mat>��ΪVector<String>,Ȼ�󷵻�װ��ѵ������������·������������Ҫʱ�ڸ������е�·�����ж�ȡ
#endif


#ifdef USE_SEX_DECT
int main(int argc, char** argv)
{
#if 0
	//�����Ա�ʶ������ݿ�
	string csvPath = "D:\\ͼ�����ݿ�\\�Ա����ݿ�\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\at.txt";
	vector<Mat> images;
	vector<int> labels;
	ReadCsv(csvPath, images, labels);
	cout << "����״̬ȷ��" << endl;
#else
	//�����Ա�ʶ������ݿ�
	string csvPath = "D:\\ͼ�����ݿ�\\�Ա����ݿ�\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\at.txt";
	vector<String> vecTrainPath;
	vector<int> vecTrainLabel;
	ReadCsv(csvPath,vecTrainPath,vecTrainLabel);
	//ʹ�õ��������
	cout << "����״̬OK" << endl;
#endif
#if 0

	Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	modelPCA->train(images, labels);
	modelPCA->save("D:\\ͼ�����ݿ�\\�Ա����ݿ�\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\PCA_Model.xml");

	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//modelFisher->train(images, labels);
	//modelFisher->save("D:\\ͼ�����ݿ�\\�Ա����ݿ�\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\Fisher_Model.xml");

	Mat testImage = imread("D:\\ͼ�����ݿ�\\�Ա����ݿ�\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\��������\\���Բ�������\\face_480.bmp",0);
	int predictPCA = modelPCA->predict(testImage);
	if (predictPCA)
		cout << "��������" << endl;
	else
		cout << "����Ů��" << endl;
#else

#endif
////////////////////ʹ��SVM���������Ա�����/////////////////
//1��ѵ����ʼ��-------��ȡHOG����֮ǰ����Ҫ��ʼ��ѵ�����ݾ���
	//��ʼ��ѵ�����ݾ���
	int iNumTrain = 800;
	Mat trainDataHog;
	Mat trainLabel = Mat::zeros(iNumTrain, 1, CV_32FC1);//�м�SVMѵ�������ݱ�����CV_32FC1��ʽ�����
	//Ҫ����ǩ����trainLabel��ʼ��ΪCV_32FC1��ʽ

//��ȡͼ��HOG����
	//ѭ���������е�ѵ����������ȡHOG����������ѵ�����ݾ�����
	Mat imageSrc;
	for (int i = 0; i < iNumTrain; i++)
	{
		imageSrc = imread(vecTrainPath[i].c_str(), 1);//��vecTrainPath������ѭ����������
		resize(imageSrc, imageSrc, Size(64, 64));//�ߴ��һ��Ϊ64*64���ο�һ������HOG�����Ĳ��ͣ�64*64��һ����һ�����ųߴ�
		HOGDescriptor *hog = new HOGDescriptor(cvSize(64, 64), cvSize(16, 16),//�����HOG����������Opencv������
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