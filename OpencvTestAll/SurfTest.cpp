#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>  //------这个目录里面有很多头文件集合
#include <vector>
#include "include.h"

using namespace cv;
using namespace std;








#ifdef USE_SURF_TEST
int  main(int argc,char **argv)
{
	Mat img = imread("D:\\4.jpg");
	imshow("原图",img);

	//首先得到特征点的集合
	vector<KeyPoint> keyPoint;
	//在库中：typedef SURF SurfFeatureDetector;   typedef SURF SurfDescriptorExtractor;所以三者是等价的（别名） 
	//SURF surf(1000);
	SurfFeatureDetector surf(1000);
}

#else
#endif