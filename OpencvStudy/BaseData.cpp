#include"include.h"
#include<opencv2/opencv.hpp>
#include<string.h>
#include<iostream>

using namespace cv;
using namespace std;

#ifdef USE_BASEDATA 

int main(int argc,char** argv)
{
	cout<<"Demo is runing !"<<endl;
//������Rect��ʹ�ã���������rect(100,50,50,100)
	Rect rect(100,50,50,100);
	cout<<"rect������ǣ�"<<rect.area()<<endl;//����rect�����5000
	cout<<"rect�Ĵ�Сʱ��"<<rect.size()<<endl;
	cout<<"rect�����϶���������ǣ�"<<rect.tl()<<endl;//����rect�����϶�������꡾100,50��
	cout<<"rect�����¶���������ǣ�"<<rect.br()<<endl;//����rect�����¶�������꡾150,150��
	//cout<<"rect�Ŀ���ǣ�"<<rect.width()<<endl;
	//cout<<"rect�ĸ߶��ǣ�"<<rect.height()<<endl;
	cout<<"rect�Ƿ����Point��x,y):"<<rect.contains(Point(1,5))<<endl;
//�򵥵ĵ��߻���
	return 0;
}
#else
#endif

namespace dong
{


//************************************
// ��  ��:  ��ȡ�������ĵ�����
// ��  ��:    
// ��  ��:	dong
// ��  ��: 
//************************************
Point getCenterPoint(Rect rect)
{
	Point cpt;
	cpt.x=rect.x+cvRound(rect.width/2.0);
	cpt.y=rect.y+cvRound(rect.height/2.0);
	return cpt;
}

	//
}