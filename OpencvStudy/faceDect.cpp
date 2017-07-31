#include <iostream>
#include<opencv2/opencv.hpp>  //------���Ŀ¼�����кܶ�ͷ�ļ�����
#include "include.h"


using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);
//*********����ȫ�ֱ���
//����д�����ع���Ŀ¼
//String face_cascade_name = "haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
//���ؾ���λ��,ע��λ������"\\"��ʶ����
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
	//imshow("ԭʼͼƬ",img);
	}
	//���ؼ�����cascade��
	if (!face_cascade.load(face_cascade_name))
	{
		printf(" Face Error loading\n");//���·����Ҫ�ر�ע��
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

std::vector<Rect> faces;//�����������Ǿֲ������Ļ����ᱨ�ڴ����
/*
��Ҫ����Ϊ��֮ǰ�ֲ�����facesΪvector����faces���vector�ͷ�ʱ�������
_CrtIsValidHeapPointer��bug����������detectMultiScale������װ��opencv��
dll�У��ڼ�⵽��������face���vector���в��������ڸñ���ʹ�ý����ͷ�ʱ��
�ٴζ�����в���ʱ���ͻᱨ��
�ο���http://blog.csdn.net/u014365862/article/details/49907055
*/
void detectAndDisplay(Mat frame)
{
	//std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame,frame_gray,COLOR_BGR2GRAY);//��ɻҶ�ͼ
	equalizeHist(frame_gray,frame_gray);
	//imshow("�Ҷ�Ч��չʾ",frame_gray);
	//�������
	face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));//CV_HAAR_FIND_BIGGEST_OBJECT
	//face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_FIND_BIGGEST_OBJECT,Size(30,30));
	for (size_t i = 0; i < faces.size();i++)
	{
		//������Ŀ
		cout<<"Face count:"<<faces.size()<<endl;
		//���·��ʿ��ܴ������⣬vector�������û�У�
		//ָ�� �������
		//cout<<"Face re:"<<faces[0].area()<<endl;
		//cout<<"Face tl���꣺"<<faces[0].tl()<<endl;//��������
		//cout<<"Face br���꣺"<<faces[0].br()<<endl;//��������
		cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<"All the information of faces vector:"<<endl;
		for(vector<Rect>::iterator ibegin=faces.begin(),iend=faces.end();ibegin!=iend;ibegin++)
		{
			cout<<"This is vector of face"<<endl;
			cout<<"face re is :"<<ibegin->area()<<endl;
			cout<<"the iterator is a pointer to object!"<<endl;
			
		}

		Point center(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2);//�õ�����������
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 2, 8, 0);
	}
	//��ʾ���յ�Ч��ͼ
	imshow("���������",frame);

}