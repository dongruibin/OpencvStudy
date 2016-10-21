#include <iostream>
#include<opencv2/opencv.hpp>  //------这个目录里面有很多头文件集合
#include "include.h"


using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);
//*********声明全局变量
String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

#ifdef USE_FACE_DECT

int main(int argc ,char** argv)
{ 
	Mat img = imread("D:\\5.jpg");
	//加载级联（cascade）
	if (!face_cascade.load(face_cascade_name))
	{
		printf("Error loading\n");
		return -1;
	}
	if (!eyes_cascade.load(eyes_cascade_name))
	{
		printf("Error loading\n");
		return -1;
	}
	detectAndDisplay(img);
	waitKey(60000);

	return 0;
}
#else
#endif

void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame,frame_gray,COLOR_BGR2GRAY);//变成灰度图
	imshow("灰度效果展示",frame_gray);
	//人脸检测
	face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
	for (size_t i = 0; i < faces.size();i++)
	{
		Point center(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2);//得到人脸的区域
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 2, 8, 0);
	}
	//显示最终的效果图
	imshow("人脸检测结果",frame);

}