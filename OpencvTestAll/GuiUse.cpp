///尝试使用相应的ui工具进行相关的操作
//新建立的方法都属于DongCv这个命名空间里面的方法


#include<iostream>
#include<opencv2/opencv.hpp>
#include"include.h"

#include"GuiCv.h"

using namespace std;
#define WINDOWS_SIZE 500

//函数功能：
//	绘制一个椭圆
//函数参数:
//	1---椭圆将被画到img图像上
//  2---椭圆中心点为Point(WINDOWS_SIZE/2.0,WINDOWS_SIZE/2.0）,并且大小位于矩阵
//		Size(WINDOWS_SIZE/4.0,WINDOWS_SIZE/16.0),
//	3---椭圆的旋转角度为angle
//	4---椭圆扩展的弧度为0到360度
//	5---图形颜色为Scalar（255,0,255)
//	6---椭圆的粗度为thickness
//	7---线条的类型为lineType
void DongCv::DrawEllipse(Mat &img,double angle)
{
	int thickness = 2;
	int lineType = 8;
	ellipse(img,
		Point(WINDOWS_SIZE / 2.0, WINDOWS_SIZE / 2.0),
		Size(WINDOWS_SIZE / 4.0, WINDOWS_SIZE / 16.0),
		angle,
		0,
		360,
		Scalar(255, 0, 255),
		thickness,
		lineType
		);
}
///函数功能
//	绘制一个圆
//函数参数：
//	1---圆将被画到img图像上
//	2---圆心有center定义
//	3---圆的半径为：WINDOWS_SIZE/32.0
//	4---圆的颜色Scalar(0,0,255)
//	5---线的粗细为thinkness=-1,因此圆将填充
//函数返回值
//	无
void DongCv::DrawFillCircle(Mat& img,Point center)
{
	int thickness = -1;
	int lineType = 8;
	circle(img,
		center,
		WINDOWS_SIZE / 32.0,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}