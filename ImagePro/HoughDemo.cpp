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
//namewindows 
const char* nameWin="standHough test";
//int k[140000000]={0};
void standHough(int,void*);
void HoughCircle(int , void*);
int CircleTrack;
int MAXCircleBar=100;
int main(int argc,char** argv)
{
	srcHough=imread("D:\\4.jpg");
	if(srcHough.empty())
	{
		return -1;
	}
	cout<<"resize����ʹ�ã�"<<endl;
	//resize(srcHough,srcHoughSize,Size(100,100));
	//imshow("srcHoughSize",srcHoughSize);

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
	standHough(0,0);//Can do the standHough before the Trackbar is clicked!

	cout<<"This is a demo for detect circle of image!"<<endl;
	//nameWindows("Detect Circle");
	createTrackbar("Detect Circle","Detect Circle",	&CircleTrack,MAXCircleBar,HoughCircle);

	waitKey(60000);
	return 0;
}

vector<string> names;
Mat houghStand;
vector<Vec2f> s_lines;
/*
ʹ�û���任���ͼ���е�ֱ�ߣ�Բ��ͼ��������ͼ�κ���
��ֱ������ϵ��������ϵ��
*/
void standHough(int ,void *)
{
	//cout<<"This is only a test"<<endl;
	cout<<"�������ֵMaxTrackbar:"<<MaxTrackbar<<endl;
	cout<<"����ʵ��ֵsTrackbar:"<<sTrackbar<<endl;
	//vector<Vec2f> s_lines;
	//cvtColor(srcHough_gray,houghStand,CV_GRAY2BGR);
	//imshow("houghStand",houghStand);
	cout<<"Detected the Line!"<<endl;
	HoughLines(srcHough_gray,s_lines,100,CV_PI/180,MinTrackbar+sTrackbar,0,0);//InuputArray is gray
	cout<<"The HoughLines threshold is :"<<MinTrackbar+sTrackbar<<endl;
	//show the result 
	cout<<"s_lines size is :"<<s_lines.size()<<endl;
	for(size_t i=0;i<s_lines.size();i++)
	{
	float r = s_lines[i][0], t = s_lines[i][1];
      double cos_t = cos(t), sin_t = sin(t);
      double x0 = r*cos_t, y0 = r*sin_t;
      double alpha = 1000;

       Point pt1( cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t) );
       Point pt2( cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t) );
       line( srcHough, pt1, pt2, Scalar(0,0,255), 3, CV_AA);//Scalar is B G R
	}
	imshow(nameWin,srcHough);
}
/*
���û���任����Բ�μ��

*/
void HoughCircle(int ,void *)
{
}
#endif


