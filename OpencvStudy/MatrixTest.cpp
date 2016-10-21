//#include<opencv2/opencv.hpp> 
//#include <opencv2/core/core.hpp>
//#include <iostream>
#include "include.h"
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <stdio.h>


using namespace std;
using namespace cv;//-----û������Ļ�����ʹ��Mat�ȱ��Ҳ���


////�������ʹ��
//��������룺�����������Ҳ����Ϊ�ˣ������¼���ͼ���е�ÿ�����ص�ֵ����������е�ֵ��ʾ����
//����ֵ�����������������ֵ��������ʹ���Լ����õ�Ȩֵ�������������ڵ�ֵ���˸���Ȩƽ����
//����ʹ�ù�ʽ��
//		I��i,j��=5*I(i,j)-[I(i-1,j)+I(i+1,j)+I(i,j-1)+I(i,j+1)]
//һ�ַ����ǻ��������ط��ʷ�������һ�ַ�����filter2D

//��������
void Sharpen(const Mat& myImage, Mat& Result)//�������÷�ʽ���в����Ĵ���
{
	CV_Assert(myImage.depth()==CV_8U);//�����Ƿ��д���---������ucharͼ��

	//����ͼ���ͨ����������ʹ��ָ����ÿ��ͨ���Ͻ��е��������ͨ�����;�����
	//������Ԫ������

	Result.create(myImage.size(),myImage.type());
	const int nchannels = myImage.channels();

	//��ΪҪͬʱ���ʶ������أ��������ǻ�ȡ������ÿһ�����ص�ָ�루�ֱ���ǰһ�С���ǰ�к���һ�У���
	//���ǻ�Ҫһ��ָ��������洢λ�õ�ָ�롣
	//ʹ��[]���������������ɷ��ʵ�Ŀ��Ԫ�أ�Ϊ����ָ����ǰ�ƶ���������ÿһ�β���������ָ������˵������ƶ�һ���ֽڣ���
	for (int j = 1; j < myImage.rows - 1;++j)
	{
		const uchar* previous = myImage.ptr<uchar>(j-1);
		const uchar* current = myImage.ptr<uchar>(j);
		const uchar* next = myImage.ptr<uchar>(j+1);
		uchar* output = Result.ptr<uchar>(j);

		for (int i = nchannels; i < nchannels*(myImage.cols-1);++i)
		{
			*output++ = saturate_cast<uchar>(5 * current[i] - current[i - nchannels] - current[i + nchannels] - previous[i]
				- next[i]); 
		}
	}
	//��ͼ��ı߽��ϣ���������Ĺ�ʽ����ʲ����ڵ�����λ�ã����磨0��-1������������ǵĹ�ʽ�Ա߽����˵��δ�����
	//һ�ּ򵥵Ľ���������ǲ�����Щ�߽��ʹ�����룬��ֱ�Ӱ�������Ϊ0
	Result.row(0).setTo(Scalar(0));//�ϱ߽�
	Result.row(Result.rows - 1).setTo(Scalar(0));//�±߽�
	Result.col(0).setTo(Scalar(0));//��߽�
	Result.col(Result.cols - 1).setTo(Scalar(0));//�ұ߽�
}

//�˲�����ͼ������Ӧ�õĹ㷺��opencv�����и��˲������루Ҳ����Ϊ�ˣ���ʹ�øú��������ȶ���һ����ʾ�����Mat����
//Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
//							- 1, 5, -1,
//							0, -1, 0);

#ifdef USE_MATRIXTEST
int main(int argc, char argv)
{
	cout << "����ʹ��" << endl;
	return 0;
}
#else 
#endif
