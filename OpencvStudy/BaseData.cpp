#include"include.h"
#include<opencv2/opencv.hpp>
#include<string.h>
#include<iostream>

using namespace cv;
using namespace std;

#ifdef USE_BASEDATA 

int main(int argc,char** argv)
{
	cout<<"Demo is runing !"<<endl;
//矩形类Rect的使用，创建对象rect(100,50,50,100)
	Rect rect(100,50,50,100);
	cout<<"rect的面积是："<<rect.area()<<endl;//返回rect的面积5000
	cout<<"rect的大小时："<<rect.size()<<endl;
	cout<<"rect的左上顶点的坐标是："<<rect.tl()<<endl;//返回rect的左上顶点的坐标【100,50】
	cout<<"rect的右下顶点的坐标是："<<rect.br()<<endl;//返回rect的右下顶点的坐标【150,150】
	//cout<<"rect的宽度是："<<rect.width()<<endl;
	//cout<<"rect的高度是："<<rect.height()<<endl;
	cout<<"rect是否包含Point（x,y):"<<rect.contains(Point(1,5))<<endl;
//简单的点线绘制
	return 0;
}
#else
#endif

namespace dong
{


//************************************
// 功  能:  获取矩形中心点坐标
// 参  数:    
// 作  者:	dong
// 返  回: 
//************************************
Point getCenterPoint(Rect rect)
{
	Point cpt;
	cpt.x=rect.x+cvRound(rect.width/2.0);
	cpt.y=rect.y+cvRound(rect.height/2.0);
	return cpt;
}

	//
}