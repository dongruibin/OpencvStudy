#include"include.h"
#include<iostream>
#include<opencv2/opencv.hpp>
//�ο���http://blog.csdn.net/xukaiwen_2016/article/details/53525988



#ifdef USE_car

//����ʶ������Ҫʹ����һЩ������
/*

	�������루����ͷ���������--��˹ģ��
	�Ҷ�ͼ

*/
using namespace std;
using namespace cv;
//Method---Gaussian color
//Gaussian 1
//color  2
//Threshold 3
#define Method 1
//��˹ģ��
Mat Gaussian(Mat &img)
{
	Mat out;
	GaussianBlur(img,out,Size(3,3),0,0,BORDER_DEFAULT);
	return out;
}

int main(int argc,char** argv)
{
	Mat img,imgout;
	img=imread("D:\\car.jpg");
	imshow("ԭͼ",img);

#if Method
	imgout=Gaussian(img);
	imshow("��˹�˲�",imgout);
#endif

#if Method
	cvtColor(img,imgout,CV_RGB2GRAY);
	imshow("�Ҷ�ͼ",imgout);
#endif

#if Method
	/*
		threshold_type:
		0:��������ֵ

		threshold();���뵥ͨ��8bitͼ����
	*/
	int threshold_value=100;
	int max_BINARY_value=255;
	cvtColor(img,imgout,CV_RGB2GRAY);
	threshold(imgout,imgout,threshold_value,max_BINARY_value,0);
	imshow("��ֵ��",imgout);
#endif

	waitKey(6000);
	return 0;
}

#endif