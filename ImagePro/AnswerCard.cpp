#include"include.h"
#include<iostream>
#include<opencv2\opencv.hpp>

//������ʹ�ô��⿨ʶ����Ϊ�ο�ʵ��
//���Ͳο���ַ��http://blog.csdn.net/cp562090732/article/details/47804003
/*
	1��ͼ���ȡ
	2��ͼƬת��Ϊ�Ҷ�ͼ
	3��ͼƬ�趨��ֵ
	4�������㣨�ȸ�ʴ�������ͣ�
	5��ָ����������
	6���ҵ�Ϳѡ��
	7������Ϳѡ�������ȷ����Ϳѡ��ѡ���Լ����
*/
using namespace std;
using namespace cv;

#ifdef ANSWER


int main(int argc,char** argv)
{
	Mat src;
	src=imread("D:\\2.jpg");
	imshow("Test",src);
	cout<<"This program is ok!"<<endl;
	waitKey(6000);
	return 0;
}

#else
#endif