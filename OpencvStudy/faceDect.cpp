#include <iostream>
#include<opencv2/opencv.hpp>  //------这个目录里面有很多头文件集合
#include "include.h"


using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);
//*********声明全局变量
//这种写法加载工程目录
//String face_cascade_name = "haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
//加载绝对位置,注意位置是用"\\"标识出来
String face_cascade_name = "D:\\OpencvStudy\\OpencvStudy\\haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "D:\\OpencvStudy\\OpencvStudy\\haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

#ifdef USE_FACE_DECT

int main(int argc ,char** argv)
{ 
	Mat img = imread("D:\\5.jpg");
	if(img.empty())
	{
		cout<<"img not found"<<endl;
		return -1;
	//imshow("原始图片",img);
	}
	//加载级联（cascade）
	if (!face_cascade.load(face_cascade_name))
	{
		printf(" Face Error loading\n");//这个路径需要特别注意
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

std::vector<Rect> faces;//这个变量如果是局部变量的话，会报内存错误
/*
主要是因为：之前局部变量faces为vector，在faces这个vector释放时，会出现
_CrtIsValidHeapPointer的bug，这是由于detectMultiScale函数封装在opencv的
dll中，在检测到人脸后会对face这个vector进行操作，而在该变量使用结束释放时，
再次对其进行操作时，就会报错
参考：http://blog.csdn.net/u014365862/article/details/49907055
*/
void detectAndDisplay(Mat frame)
{
	//std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame,frame_gray,COLOR_BGR2GRAY);//变成灰度图
	equalizeHist(frame_gray,frame_gray);
	//imshow("灰度效果展示",frame_gray);
	//人脸检测
	face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));//CV_HAAR_FIND_BIGGEST_OBJECT
	//face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_FIND_BIGGEST_OBJECT,Size(30,30));
	for (size_t i = 0; i < faces.size();i++)
	{
		//人脸数目
		cout<<"Face count:"<<faces.size()<<endl;
		//以下访问可能存在问题，vector里面肯能没有？
		//指针 对象调用
		//cout<<"Face re:"<<faces[0].area()<<endl;
		//cout<<"Face tl坐标："<<faces[0].tl()<<endl;//左上坐标
		//cout<<"Face br坐标："<<faces[0].br()<<endl;//右下坐标
		cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<"All the information of faces vector:"<<endl;
		for(vector<Rect>::iterator ibegin=faces.begin(),iend=faces.end();ibegin!=iend;ibegin++)
		{
			cout<<"This is vector of face"<<endl;
			cout<<"face re is :"<<ibegin->area()<<endl;
			cout<<"the iterator is a pointer to object!"<<endl;
			
		}

		Point center(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2);//得到人脸的区域
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 2, 8, 0);
	}
	//显示最终的效果图
	imshow("人脸检测结果",frame);

}