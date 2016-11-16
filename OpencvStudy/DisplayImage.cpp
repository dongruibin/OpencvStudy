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
	cout << "Opencv�İ汾Ϊ��" ;
	cout << CV_VERSION << endl;
}
//������ʾһ������ͼ��
int  DisplayAll(Mat& img)
{
	return true;

}

//��ʾһ��ͼƬ������
void DisplayInfo(Mat& img)
{
	//cout << img << endl;

	cout << "dims:" << img.dims << endl;//�����ά
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
	if (!img.data) { printf("���ã���ȡimg������~�� \n"); return false; }
	//void imshow(const string& winname, InputArray mat); ---source code
	//namedWindow("����demo");
	//////////����demo
	//cornerHarris();
	imshow("ceshi",img);
	DisplayInfo(img);
	waitKey(60000);
	return 0;
#else
	//cv::Harris har;
	cv::Mat img = cv::imread("D:\\4.jpg");//Mats���������ռ�cv��
	imshow("test", img);
	//cornerHarris();
	cv::waitKey(600000);
	return 0;
#endif
}
#else

#endif