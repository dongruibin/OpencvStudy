#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>  //------���Ŀ¼�����кܶ�ͷ�ļ�����
#include <vector>
#include "include.h"

using namespace cv;
using namespace std;








#ifdef USE_SURF_TEST
int  main(int argc,char **argv)
{
	Mat img = imread("D:\\4.jpg");
	imshow("ԭͼ",img);

	//���ȵõ�������ļ���
	vector<KeyPoint> keyPoint;
	//�ڿ��У�typedef SURF SurfFeatureDetector;   typedef SURF SurfDescriptorExtractor;���������ǵȼ۵ģ������� 
	//SURF surf(1000);
	SurfFeatureDetector surf(1000);
}

#else
#endif