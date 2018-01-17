#include "include.h"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>


#ifdef USE_markObject
using namespace cv;
using namespace std;
#define BIN_DIV 80


int main(int argc,char** argv)
{
	Mat srcImg,midImg,dstImg;
	srcImg=imread("D:\\object.jpg");

	Mat xianshi=srcImg.clone();
	Mat redChannel;
	//namedWindow("",WINDOW_NORMAL);
	imshow("src",srcImg);
	Mat grayImg;
	vector<Mat> channels;
	split(srcImg,channels);
	//取出其中一张图片
	//grayImg=channels[0];//也可以，不过为什么使用at
	grayImg=channels.at(0);
	imshow("split0",grayImg);

	redChannel=channels.at(2);
	//均值滤波
	blur(grayImg,grayImg,Size(20,20),Point(-1,-1));

	Mat midImg1=grayImg.clone();
	int rowNumber=midImg1.rows;
	int colNumber=midImg1.cols;

	//变成单通道图像了,是不是单blue图像？
	for(int i=0;i<rowNumber;i++)
	{
		uchar* data=midImg1.ptr<uchar>(i);//取i行的首地址
		uchar* redData=redChannel.ptr<uchar>(i);
		for(int j=0;j<colNumber;j++)
		{
			if(data[j]>BIN_DIV&&redData[j]<BIN_DIV*2/3)
				data[j]=255;
			else
				data[j]=0;
		}
	}
	imshow("二值化",midImg1);

	Mat midImg2=midImg1.clone();
	//开始闭运算
	Mat element=getStructuringElement(MORPH_RECT,Size(40,40));
	morphologyEx(midImg1,midImg2,MORPH_CLOSE,element);
	imshow("close algorthm",midImg2);
	
	//开始查找图像轮廓
	//1、先来构建一个空图像
	Mat midImg3=Mat::zeros(midImg2.rows,midImg2.cols,CV_8UC3);
	//Mat midImg4=Mat(midImg2.rows,midImg2.cols,size)
	//imshow("midImg3",midImg3);//创建的为什么是黑色（0-黑，255-白？？）
#if 1	
	cv::Vec3b *datt=srcImg.ptr<Vec3b>(0);//后面参数是列参数，是获取整列像素指针？
	Vec3b dadd=datt[1];
	cout<<"the midImg3 row1 is:"<<&dadd[1]<<endl;//datt是一个指向Vec3b的
	//上面的datt是一个指向Vec3b的指针，(datt直接count是指针地址)
#endif
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;




	waitKey(600000);//waitKey本质是什么？
	return 0;
}



#endif