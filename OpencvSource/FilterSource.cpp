#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;//这个命名空间在#include<opencv2/opencv.hpp>里面


//////本文件分析的是源码的实现，为保证工程编译正常，函数名字加下划线。

//boxFilter()函数，在modules/imgproc/src/smooth.cpp

//我方函数
void _boxFilter(InputArray _src,OutputArray _dst,int ddepth,Size ksize,Point anchor,bool normalize,int borderType)
{
	Mat src=_src.getMat();//实现拷贝功能
	int sdepth=src.depth(),cn=src.channels();//定义临时变量，代表源图深度sdepth,源图通道的引用cn。
	//处理ddepth小于0的情况
	if(ddepth<0)
		ddepth=sdepth;
	_dst.create(src.size(),CV_MAKETYPE(ddepth,cn));//初始化目标图
	Mat dst=_dst.getMat();//拷贝目标图的形态Mat数据到临时变量，用于稍后的操作

	//处理borderType不为BORDER_CONSTANT且normalize为真得情况
	if(borderType!=BORDER_CONSTANT && normalize)
	{
		if(src.rows==1)
			ksize.height=1;
		if(src.cols==1)
			ksize.width=1;
	}
	//如果有HAVA_TRGRA_OPTIMIZATION优化选项的定义，则执行宏体中的trgra优化版函数并返回
#ifdef HAVA_TEGRA_OPTIMIZATION

#else
	//调用FilterEngine滤波引擎，正式开始滤波操作
	/*
	Prt<FilterEngine> f=createBoxFilter(src.type(),dst.type(),
										ksize,anchor,normalize,borderType);
	f->apply(src,dst);
	*/
	/*
	其中的Ptr是用来动态分配的对象的智能指针模板。FilterEngine是opencv图像滤波功能的核心引擎。



	*/
#endif
}