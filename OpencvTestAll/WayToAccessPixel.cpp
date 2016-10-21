#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include.h"
using namespace std;
using namespace cv;

//�����Ƿ�ʹ�ø��ļ�

void help()
{
	cout << CV_VERSION << endl;
}

//����ǳīд��14�з�����ͼ�����صķ��ʷ�����ʵ���Ϸ�Ϊ3�֣���һ��ʹ���������ָ���
//��ʽ��һ��ָ���������Щ�����ڶ���ʹ�õ�����������������ʹ�ö�̬��ַ���㡣

//ʹ�õķ���һ�������ָ�뷽ʽ
void function_1(Mat &image,int div=64)//ʹ��������֪ʶ
{
	int nl=image.rows;//����
	int nc=image.cols*image.channels();//ÿ��Ԫ�ص�Ԫ���ܺ�
	//����ʹ��
	for(int j=0;j<nl;j++)//������
	{
		uchar* data=image.ptr<uchar>(j);//data��һ��ָ��uchar��ָ��
		for(int i=0;i<nc;i++)
		{
			//��ʼ�����ص���д���
			//ʹ��������ʽ����
			data[i]=data[i]/div*div+div/2;
			//����ʹ��ָ��
			//*data++= *data/div*div + div/2;
		}
	}
}
//��������ʹ�õ�����
	void function_2(Mat &image,int div=64)
	{
		//��ȡ������
		Mat_<Vec3b>::iterator it= image.begin<Vec3b>();
		Mat_<Vec3b>::iterator itend=image.end<Vec3b>();
		for(;it!=itend;++it){
			//��ʼ����ÿһ��Ԫ��
			(*it)[0]= (*it)[0]/div*div + div/2;
			(*it)[1]= (*it)[1]/div*div + div/2;
		    (*it)[2]= (*it)[2]/div*div + div/2;
			//�������ش���
		}
	}
//����������̬��ַ�ļ���
	void function_3(Mat &image ,int div=64)
	{
		int nl=image.rows;//����
		int nc=image.cols;
	for (int j=0; j<nl; j++) 
	{
		for (int i=0; i<nc; i++) 
		{
			//-------------��ʼ����ÿ������-------------------
			image.at<Vec3b>(j,i)[0]=image.at<Vec3b>(j,i)[0]/div*div + div/2;
			image.at<Vec3b>(j,i)[1]=image.at<Vec3b>(j,i)[1]/div*div + div/2;
			image.at<Vec3b>(j,i)[2]=image.at<Vec3b>(j,i)[2]/div*div + div/2;
			//-------------�������ش���------------------------
			//��ע˵����
			//image.at<uchar>(i,j)��ȡ���Ҷ�ͼ����i��j�еĵ㡣
			//image.at<Vec3b>(i,j)[k]��ȡ����ɫͼ����i��j�е�kͨ������ɫ�㡣
			//����uchar,Vec3b����ͼ������ֵ�����ͣ���Ҫ��Vec3b�������͸о����£�
			//��ʵ��core������ͨ��typedef Vec<T,N>������ģ�N����Ԫ�صĸ�����T�������͡�
		} //���д������                 
	}
	}

#ifdef USE_WAYTOACCESSPIXEL
int main()
{
	//ʹ��Ctrl+k,Ctrl+c���д�ε����ι���

	//���ж�εļ��㣬����ȶ�ʱ��Ĳ���
	//���û�о����ͼƬ�ͻᱨ��---��ʾassertʧ��
	Mat img=imread("D:\\4.jpg");
	help();
	function_1(img);
	imshow("chuli",img);
	waitKey(6000);
	return 0;
}
#else

#endif


