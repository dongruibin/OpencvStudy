#include "include.h"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>


/*
	图像处理的流程一般都是：
	摄像头-->图像（摄像头畸变矫正）
	开始滤波（线性、非线性、除噪声）
	灰度图片（CV_BGR2GRAY）
	二值图片
	轮廓识别

	//处理定位：
	定位使用广角度较低摄像头，畸变不厉害
	定位功能得出的坐标是相对于自定义的图像坐标原点，在该系统中
	定义的原点就是图像中心（320,240）单位为像素。因此，在摄像头水平放置
	的情况下，自定义图像原点即为二维空间上的摄像头的正下方。

	定位的基本思想是利用已知目标物体的长度和求出的目标物体的像素长度，得出
	像素的尺寸，再利用像素尺寸和目标物体在自定义原点的XY方向的像素距离，
	进而求出目标物体相对水平放置的摄像头的XY方向的实际距离。
*/

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
	cout<<"the midImg3 row1 is:"<<dadd[1]<<endl;//datt是一个指向Vec3b的
	//上面的datt是一个指向Vec3b的指针，(datt直接count是指针地址)
#endif

	/*
	findContours(InputOutputArray image,OutputArrayOfArrays contours,
				OutputArray hierarch,int mode,
				int method,Point offset=Point());
	findContours(InputOutputArray image,OutputArrayOfArrays contours,
				int mode,int method, Point offset=Point());
	@param
	image:输入图像，8-bit的单通道二值图像，非零像素会被当作1.
	contours:检测到的轮廓，是一个向量，向量的每个元素都是
		一个轮廓，因此这个向量的每个元素仍是一个向量。
		vector<vector<Point> > contours;
	hierarchy:各个轮廓的继承关系，hierarchy也是一个向量，长度
		和contours相等，每个元素和contours的元素对应。
		hierarchy的每个元素是一个包含四个整型数的向量。
		vector<Vec4i> hierarchy;//Vec4i is a vector contains four number of int
		hierarchy[i][0],第i条轮廓(contours[i])的下一条，
		hierarchy[i][1],------------------------前一条。
					[2]
					[3]
	offset:Optional offset by which every contour point is shifted. This is 
	useful if the contours are extracted from the image ROI and then they should
	be analyzed in the whole image context.


	*/
	//开始发现contours
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	//midImg2是二值化图像
	findContours(midImg2,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);
	int index=0;
	for(;index>=0;index=hierarchy[index][0])
	{
		Scalar color(255,255,255);
		drawContours(midImg3,contours,index,color,NULL,8,hierarchy);
	}
	//显示轮廓图
	imshow("Lunkuotu",midImg3);
	Mat midImg4;
	midImg4=midImg3.clone();
	//计算一下总共有多少个contours---总共只有3个contours。
	cout<<"This image contours:"<<contours.size()<<endl;
	//创建包围轮廓的矩形边界
	for(int i=0;i<contours.size();i++)
	{
		//每个轮廓
		vector<Point> points=contours[i];//有i个这样的轮廓-dong-2018-1-18
		//对于给定的2D点集，寻找最小面积的包围矩形
		RotatedRect box=minAreaRect(Mat(points));
		Point2f vertex[4];
		box.points(vertex);//存放4个顶点？-dong-2018-1-18
		line(xianshi,vertex[0],vertex[1],Scalar(100,200,211),6,CV_AA);
		line(xianshi,vertex[1],vertex[2],Scalar(100,200,211),6,CV_AA);
		line(xianshi,vertex[2],vertex[3],Scalar(100,200,211),6,CV_AA);
		line(xianshi,vertex[3],vertex[0],Scalar(100,200,211),6,CV_AA);
		//额外画一下中心线
		line(xianshi,vertex[0],vertex[2],Scalar(255,0,0),6,CV_AA);
		line(xianshi,vertex[3],vertex[1],Scalar(255,0,0),6,CV_AA);
		cout<<"The "<<i<<"center is"<<(vertex[2]-vertex[0]).x<<endl;
	}
	imshow("rectLine",xianshi);




	waitKey(600000);//waitKey本质是什么？
	return 0;
}



#endif