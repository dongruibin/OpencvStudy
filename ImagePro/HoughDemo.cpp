#include"include.h"
#include<iostream>
#include"opencv2/opencv.hpp"

using namespace std;
using namespace cv;

#ifdef HoughDemo
int MinTrackbar=50;
int MaxTrackbar=150;
Mat srcHough,srcHough_gray;
Mat srcHoughCanny;
Mat srcHoughSize;
int sTrackbar=MaxTrackbar;
int pTrackbar=MaxTrackbar;
//int k[140000000]={0};
void standHough(int,void*);
int main(int argc,char** argv)
{
	srcHough=imread("D:\\4.jpg");
	if(srcHough.empty())
	{
		return -1;
	}
	cout<<"resize����ʹ�ã�"<<endl;
	resize(srcHough,srcHoughSize,Size(100,100));
	imshow("srcHoughSize",srcHoughSize);

	cvtColor(srcHough,srcHough_gray,COLOR_RGB2GRAY);
	imshow("src_gray",srcHough_gray);

	cout<<"Mat srcHoughCanny�ĵ�ַ�ǣ�"<<&srcHoughCanny<<endl;

	//Canny����
	/*
�ο����ϣ�http://blog.csdn.net/hitwengqi/article/details/6877864
	Canny���ӵ���Ҫ����
	1���ø�˹�˲���ƽ��ͼ��
	2����һ��ƫ�����޲�ּ����ݶȷ�ֵ�ͷ���
	3�������η�ֵ���зǼ���ֵ����
	4����˫��ֵ�㷨�������ӱ�Ե
	threshold1��threshold2 ���е�С��ֵ�������Ʊ�Ե���ӣ������ֵ��������ǿ��Ե�ĳ�ʼ�ָ
	ע�⣺��������Ҫ�ǵ�ͨ��ͼƬ
	*/
	Canny(srcHough_gray,srcHoughSize,50,200);
	imshow("srcHoughSize",srcHoughSize);

	//Create Trackbars for Threshold
	char threshLabel[50];
	//sprintf(threshLabel,"Thres:%d+input",minThreshold);
	createTrackbar("threshold","srcHoughSize",&sTrackbar,MaxTrackbar,standHough);

	waitKey(60000);
	return 0;
}

vector<string> names;
void standHough(int ,void *)
{
	//cout<<"This is only a test"<<endl;
	cout<<"�������ֵMaxTrackbar:"<<MaxTrackbar<<endl;
	cout<<"����ʵ��ֵsTrackbar:"<<sTrackbar<<endl;
	vector<Vec2f> s_lines;
}
#endif


