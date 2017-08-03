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
	cout<<"resize函数使用："<<endl;
	//resize(srcHough,srcHoughSize,Size(100,100));
	//imshow("srcHoughSize",srcHoughSize);

	cvtColor(srcHough,srcHough_gray,COLOR_RGB2GRAY);
	imshow("src_gray",srcHough_gray);

	cout<<"Mat srcHoughCanny的地址是："<<&srcHoughCanny<<endl;

	//Canny算子
	/*
参考资料：http://blog.csdn.net/hitwengqi/article/details/6877864
	Canny算子的主要步骤
	1、用高斯滤波器平滑图像
	2、用一阶偏导有限差分计算梯度幅值和方向
	3、对梯形幅值进行非极大值抑制
	4、用双阈值算法检测和连接边缘
	threshold1和threshold2 当中的小阈值用来控制边缘连接，大的阈值用来控制强边缘的初始分割。
	注意：参数输入要是单通道图片
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
使用霍夫变换检测图像中的直线，圆等图形是利用图形函数
从直角坐标系到极坐标系。
*/
void standHough(int ,void *)
{
	//cout<<"This is only a test"<<endl;
	cout<<"滑条最大值MaxTrackbar:"<<MaxTrackbar<<endl;
	cout<<"滑条实际值sTrackbar:"<<sTrackbar<<endl;
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
利用霍夫变换进行圆形检测

*/
void HoughCircle(int ,void *)
{
}
#endif


