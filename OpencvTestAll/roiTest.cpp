#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include.h"
using namespace std;
using namespace cv;

//----------------------------------【ROI_AddImage( )函数】----------------------------------  
// 函数名：ROI_AddImage（）  
//     描述：利用感兴趣区域ROI实现图像叠加  
//----------------------------------------------------------------------------------------------  
bool ROI_AddImage()
{

	//【1】读入图像  
	Mat srcImage1 = imread("dota_pa.png");
	Mat logoImage = imread("ha.png");
	if (!srcImage1.data) { printf("roiTest.cpp文件，读取srcImage1错误~！ \n"); return false; }
	if (!logoImage.data) { printf("roiTest.cpp文件，读取logoImage错误~！ \n"); return false; }

	//【2】定义一个Mat类型并给其设定ROI区域  
	Mat imageROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));

	//【3】加载掩模（必须是灰度图）  
	Mat mask = imread("ha.png", 0);

	//【4】将掩膜拷贝到ROI  
	logoImage.copyTo(imageROI, mask);

	//【5】显示结果  
	namedWindow("<1>利用ROI实现图像叠加示例窗口");
	imshow("<1>利用ROI实现图像叠加示例窗口", srcImage1);

	return true;
}


#ifdef USE_ROI
int main(int argc,char** argv)
{
	cout<< "just a demo for test roi";
	ROI_AddImage();
	waitKey(60000);
	return true;
}

#else
#endif

