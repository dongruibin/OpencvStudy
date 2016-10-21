#include <iostream>
#include<opencv2/opencv.hpp>  //------���Ŀ¼�����кܶ�ͷ�ļ�����
#include "include.h"


using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);
//*********����ȫ�ֱ���
String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

#ifdef USE_FACE_DECT

int main(int argc ,char** argv)
{ 
	Mat img = imread("D:\\5.jpg");
	//���ؼ�����cascade��
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
	cvtColor(frame,frame_gray,COLOR_BGR2GRAY);//��ɻҶ�ͼ
	imshow("�Ҷ�Ч��չʾ",frame_gray);
	//�������
	face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
	for (size_t i = 0; i < faces.size();i++)
	{
		Point center(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2);//�õ�����������
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 2, 8, 0);
	}
	//��ʾ���յ�Ч��ͼ
	imshow("���������",frame);

}