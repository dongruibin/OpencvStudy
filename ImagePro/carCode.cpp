#include"include.h"
#include<iostream>
#include<opencv2/opencv.hpp>
//参考：http://blog.csdn.net/xukaiwen_2016/article/details/53525988



#ifdef USE_car

//车牌识别中主要使用了一些方法：
/*

	车牌输入（摄像头畸变矫正）--高斯模糊
	灰度图

*/
using namespace std;
using namespace cv;
//Method---Gaussian color
//Gaussian 1
//color  2
//Threshold 3
#define Method 1
//高斯模糊
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
	imshow("原图",img);

#if Method
	imgout=Gaussian(img);
	imshow("高斯滤波",imgout);
#endif

#if Method
	cvtColor(img,imgout,CV_RGB2GRAY);
	imshow("灰度图",imgout);
#endif

#if Method
	/*
		threshold_type:
		0:二进制阈值

		threshold();输入单通道8bit图！！
	*/
	int threshold_value=100;
	int max_BINARY_value=255;
	cvtColor(img,imgout,CV_RGB2GRAY);
	threshold(imgout,imgout,threshold_value,max_BINARY_value,0);
	imshow("二值化",imgout);
#endif

	waitKey(6000);
	return 0;
}

#endif