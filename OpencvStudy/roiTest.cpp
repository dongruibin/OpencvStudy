#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include.h"
using namespace std;
using namespace cv;

//----------------------------------��ROI_AddImage( )������----------------------------------  
// ��������ROI_AddImage����  
//     ���������ø���Ȥ����ROIʵ��ͼ�����  
//----------------------------------------------------------------------------------------------  
bool ROI_AddImage()
{

	//��1������ͼ��  
	Mat srcImage1 = imread("dota_pa.png");
	Mat logoImage = imread("ha.png");
	if (!srcImage1.data) { printf("roiTest.cpp�ļ�����ȡsrcImage1����~�� \n"); return false; }
	if (!logoImage.data) { printf("roiTest.cpp�ļ�����ȡlogoImage����~�� \n"); return false; }

	//��2������һ��Mat���Ͳ������趨ROI����  
	Mat imageROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));

	//��3��������ģ�������ǻҶ�ͼ��  
	Mat mask = imread("ha.png", 0);

	//��4������Ĥ������ROI  
	logoImage.copyTo(imageROI, mask);

	//��5����ʾ���  
	namedWindow("<1>����ROIʵ��ͼ�����ʾ������");
	imshow("<1>����ROIʵ��ͼ�����ʾ������", srcImage1);

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

