#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include.h"
using namespace std;
using namespace cv;

//定义是否使用该文件

void help()
{
	cout << CV_VERSION << endl;
}

//根据浅墨写的14中方法对图像像素的访问方法，实质上分为3种，第一种使用数组或者指针的
//方式（一般指针会比数组快些），第二种使用迭代器方法，第三种使用动态地址计算。

//使用的方法一：数组和指针方式
void function_1(Mat &image,int div=64)//使用了引用知识
{
	int nl=image.rows;//行数
	int nc=image.cols*image.channels();//每行元素的元素总和
	//遍历使用
	for(int j=0;j<nl;j++)//先来行
	{
		uchar* data=image.ptr<uchar>(j);//data是一个指向uchar的指针
		for(int i=0;i<nc;i++)
		{
			//开始对像素点进行处理
			//使用数组形式处理
			data[i]=data[i]/div*div+div/2;
			//或者使用指针
			//*data++= *data/div*div + div/2;
		}
	}
}
//方法二：使用迭代器
	void function_2(Mat &image,int div=64)
	{
		//获取迭代器
		Mat_<Vec3b>::iterator it= image.begin<Vec3b>();
		Mat_<Vec3b>::iterator itend=image.end<Vec3b>();
		for(;it!=itend;++it){
			//开始处理每一个元素
			(*it)[0]= (*it)[0]/div*div + div/2;
			(*it)[1]= (*it)[1]/div*div + div/2;
		    (*it)[2]= (*it)[2]/div*div + div/2;
			//结束像素处理
		}
	}
//方法三：动态地址的计算
	void function_3(Mat &image ,int div=64)
	{
		int nl=image.rows;//行数
		int nc=image.cols;
	for (int j=0; j<nl; j++) 
	{
		for (int i=0; i<nc; i++) 
		{
			//-------------开始处理每个像素-------------------
			image.at<Vec3b>(j,i)[0]=image.at<Vec3b>(j,i)[0]/div*div + div/2;
			image.at<Vec3b>(j,i)[1]=image.at<Vec3b>(j,i)[1]/div*div + div/2;
			image.at<Vec3b>(j,i)[2]=image.at<Vec3b>(j,i)[2]/div*div + div/2;
			//-------------结束像素处理------------------------
			//备注说明：
			//image.at<uchar>(i,j)：取出灰度图像中i行j列的点。
			//image.at<Vec3b>(i,j)[k]：取出彩色图像中i行j列第k通道的颜色点。
			//其中uchar,Vec3b都是图像像素值的类型，不要对Vec3b这种类型感觉害怕，
			//其实在core里它是通过typedef Vec<T,N>来定义的，N代表元素的个数，T代表类型。
		} //单行处理结束                 
	}
	}

#ifdef USE_WAYTOACCESSPIXEL
int main()
{
	//使用Ctrl+k,Ctrl+c进行大段的屏蔽工作

	//进行多次的计算，方便比对时间的差异
	//如果没有具体的图片就会报错---显示assert失败
	Mat img=imread("D:\\4.jpg");
	help();
	function_1(img);
	imshow("chuli",img);
	waitKey(6000);
	return 0;
}
#else

#endif


