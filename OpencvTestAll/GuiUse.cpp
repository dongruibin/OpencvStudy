///����ʹ����Ӧ��ui���߽�����صĲ���
//�½����ķ���������DongCv��������ռ�����ķ���


#include<iostream>
#include<opencv2/opencv.hpp>
#include"include.h"

#include"GuiCv.h"

using namespace std;
#define WINDOWS_SIZE 500

//�������ܣ�
//	����һ����Բ
//��������:
//	1---��Բ��������imgͼ����
//  2---��Բ���ĵ�ΪPoint(WINDOWS_SIZE/2.0,WINDOWS_SIZE/2.0��,���Ҵ�Сλ�ھ���
//		Size(WINDOWS_SIZE/4.0,WINDOWS_SIZE/16.0),
//	3---��Բ����ת�Ƕ�Ϊangle
//	4---��Բ��չ�Ļ���Ϊ0��360��
//	5---ͼ����ɫΪScalar��255,0,255)
//	6---��Բ�Ĵֶ�Ϊthickness
//	7---����������ΪlineType
void DongCv::DrawEllipse(Mat &img,double angle)
{
	int thickness = 2;
	int lineType = 8;
	ellipse(img,
		Point(WINDOWS_SIZE / 2.0, WINDOWS_SIZE / 2.0),
		Size(WINDOWS_SIZE / 4.0, WINDOWS_SIZE / 16.0),
		angle,
		0,
		360,
		Scalar(255, 0, 255),
		thickness,
		lineType
		);
}
///��������
//	����һ��Բ
//����������
//	1---Բ��������imgͼ����
//	2---Բ����center����
//	3---Բ�İ뾶Ϊ��WINDOWS_SIZE/32.0
//	4---Բ����ɫScalar(0,0,255)
//	5---�ߵĴ�ϸΪthinkness=-1,���Բ�����
//��������ֵ
//	��
void DongCv::DrawFillCircle(Mat& img,Point center)
{
	int thickness = -1;
	int lineType = 8;
	circle(img,
		center,
		WINDOWS_SIZE / 32.0,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}