#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include"DisplayImage.h"
#include "include.h"
using namespace cv;
using namespace std;


#define USE_NAMESPACE_CV 1

#ifdef USE_NAMESPACE_CV 
using namespace cv;
#else
#endif


static void help()
{
	cout << "Opencv的版本为：" ;
	cout << CV_VERSION << endl;
}
//加载显示一张任意图像
int  DisplayAll(Mat& img)
{
	return true;

}

//显示一张图片的属性
void DisplayInfo(Mat& img)
{
	//cout << img << endl;

	cout << "dims:" << img.dims << endl;//矩阵的维
	cout << "rows:" << img.rows << endl;
	cout << "cols:" << img.cols << endl;
	cout << "channels:" << img.channels() << endl;
	cout << "type:" << img.type() << endl;
	cout << "depth:" << img.depth() << endl;
	cout << "elemSize:" << img.elemSize() << endl;
	cout << "elemSize1:" << img.elemSize1() << endl;
}
#ifdef USE_DISPLAYIMAGE
int main(int argc ,char** argv)
{
#ifdef USE_NAMESPACE_CV
	help();
	//Mat imread(const string& filename, intflags=1 );  ----source code
	Mat img = imread("D:\\4.jpg");
	if (!img.data) { printf("你妹，读取img不存在~！ \n"); return false; }
	//void imshow(const string& winname, InputArray mat); ---source code
	//namedWindow("测试demo");
	//////////测试demo
	//cornerHarris();
	imshow("ceshi",img);
	DisplayInfo(img);
	waitKey(60000);
	return 0;
#else
	//cv::Harris har;
	cv::Mat img = cv::imread("D:\\4.jpg");//Mats是在命名空间cv内
	imshow("test", img);
	//cornerHarris();
	cv::waitKey(600000);
	return 0;
#endif
}
#else

#endif