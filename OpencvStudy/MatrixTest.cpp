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
using namespace cv;//-----没有这个的话，会使得Mat等报找不到


////矩阵操作使用
//矩阵的掩码：根据掩码矩阵（也被称为核），重新计算图像中的每个像素的值。掩码矩阵中的值表示近邻
//像素值（包括该像素自身的值）。我们使用自己设置的权值，对像素邻域内的值做了个加权平均。
//像素使用公式：
//		I（i,j）=5*I(i,j)-[I(i-1,j)+I(i+1,j)+I(i,j-1)+I(i,j+1)]
//一种方法是基本的像素访问方法，另一种方法是filter2D

//基本方法
void Sharpen(const Mat& myImage, Mat& Result)//采用引用方式进行参数的传递
{
	CV_Assert(myImage.depth()==CV_8U);//断言是否有错误---仅接受uchar图像

	//根据图像的通道数，我们使用指针在每个通道上进行迭代，因此通道数就决定了
	//需计算的元素总数

	Result.create(myImage.size(),myImage.type());
	const int nchannels = myImage.channels();

	//因为要同时访问多行像素，所以我们获取了其中每一行像素的指针（分别是前一行、当前行和下一行）。
	//我们还要一个指向计算结果存储位置的指针。
	//使用[]操作符，可以轻松访问到目标元素，为了让指针向前移动，我们在每一次操作后对输出指针进行了递增（移动一个字节）。
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
	//在图像的边界上，上面给出的公式会访问不存在的像素位置（比如（0，-1））。因此我们的公式对边界点来说是未定义的
	//一种简单的解决方法，是不对这些边界点使用掩码，而直接把它们设为0
	Result.row(0).setTo(Scalar(0));//上边界
	Result.row(Result.rows - 1).setTo(Scalar(0));//下边界
	Result.col(0).setTo(Scalar(0));//左边界
	Result.col(Result.cols - 1).setTo(Scalar(0));//右边界
}

//滤波器在图像处理中应用的广泛，opencv里面有个滤波器掩码（也被称为核），使用该函数必须先定义一个表示掩码的Mat对象
//Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
//							- 1, 5, -1,
//							0, -1, 0);

#ifdef USE_MATRIXTEST
int main(int argc, char argv)
{
	cout << "测试使用" << endl;
	return 0;
}
#else 
#endif
