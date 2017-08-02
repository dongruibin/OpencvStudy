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
	cout<<"resize函数使用："<<endl;
	resize(srcHough,srcHoughSize,Size(100,100));
	imshow("srcHoughSize",srcHoughSize);

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

	waitKey(60000);
	return 0;
}

vector<string> names;
void standHough(int ,void *)
{
	//cout<<"This is only a test"<<endl;
	cout<<"滑条最大值MaxTrackbar:"<<MaxTrackbar<<endl;
	cout<<"滑条实际值sTrackbar:"<<sTrackbar<<endl;
	vector<Vec2f> s_lines;
}
#endif


