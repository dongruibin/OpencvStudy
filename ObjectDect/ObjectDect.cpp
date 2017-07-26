#include<iostream>
#include"MultipleImageWindow.h"
//#include "utility.hpp"//what is the function of utility.hpp
//#include"opencv2/core/utility.hpp"
#include"include.h"

//本文件主要练习物体检测
//1、熟悉一下预处理作用
//2、熟悉图像目标分割和检测（之前是一片空白）
//预处理步骤分为三个或者更多的子步骤：
//1、去噪
//2、去除光亮
//3、二值化

using namespace cv;

Mat calculateLightPattern(Mat _img);
//opencv command line parser functions
//keys accecpted by command line parser
const char* keys=
{
	"{help h usage?| | print this message}"
	"{@image || Image to process}"
	"{file|dong.txt|dd}"
};

//Remove the light and return new image without light
//@param img Mat image to remove the light pattern
//@param pattern Mat image with liht pattern
Mat removeLight(Mat img,Mat pattern,int method)
{
Mat aux;
//if the method is normalization
if(method==1)
{
	//First change our image to 32 float for division
	Mat img32,pattern32;
	img.convertTo(img32,CV_32F);
	pattern.convertTo(pattern32,CV_32F);
	//Divide the image by the pattern
	aux=1-(img32/pattern32);
	//Scale it to convert to 8bit
	aux=aux*255;
	//Convert 8 bits format 
	aux.convertTo(aux,CV_8U);
}
else
{
	aux=pattern-img;
}
return aux;
}


void MymediaBlur(InputArray _src0,OutputArray _dst,int ksize);//It cann't use

#ifdef ObjectDectUse

int main(int argc,char** argv)
{
	//早期的图片
	IplImage *image;
	Mat mat;//这个就是类，对象
	//Mat convert to IplImage
	image=&IplImage(mat);

	cout<<"This a demo test ocr"<<endl;
	string s="This is a big";
	string file;
	int fsm;
	//MultipleImageWindow multipleImageWindow(s,1200,700,1);
	std::cout<<"This project is belong to ObjectDect.cpp file!"<<std::endl;
	//There the program is starting
	CommandLineParser parser(argc,argv,keys);
	//file=parser.get<string>("file");
	//cout<<"The Param file is:"<<file<<endl;
	//parser.about("Chapter 5. PhotoTool v1.0.0");
	//if(parser.has("help"))
	//{
	//	parser.printParams();
	//	return 0;
	//}
	cout<<"This is parser is passing!"<<endl;
	//read the image
	//Mat img=imread("D:\\OpencvStudy\\img\\timg.jpg");//remember the format of  image path 
	Mat img=imread("D:\\OpencvStudy\\img\\blackU.jpg");
	imshow("timg.jpg",img);
	Mat img_noise,img_box_smooth;
	medianBlur(img,img_noise,3);//This function is locate smooth.cpp
	//imshow("img_noise",img);
	//blur处理
	blur(img,img_box_smooth,Size(3,3));
	//imshow("img_box_smooth",img_box_smooth);
	//load back(no light) image 
	Mat img_no_light;
	img_noise.copyTo(img_no_light);
	//Mat light_pattern=imread("D:\\OpencvStudy\\img\\back.jpg");
	//Mat lightBack=imread("D:\\OpencvStudy\\img\\blackWhite.jpg");
	Mat lightBack=calculateLightPattern(img);
	//img_no_light=removeLight(img_noise,img,2);
	img_no_light=removeLight(img,lightBack,1);
	imshow("img_no_light",img_no_light);
	Mat img_thr;
	threshold(img_no_light, img_thr, 30, 255, THRESH_BINARY);
	//imshow("img_thr",img_thr);

	//medianBlur(light_pattern,light_pattern,3);
	cv::waitKey(600000);
#ifdef DEBUG
	////test switch case
	while(1)
	{
	cout<<"please input the fsm:"<<endl;
	//cin>>fsm;
	fsm=0;
	switch(fsm)
	{
	case 0:
		cout<<"This is 0"<<endl;
		break;
	case 1:
		cout<<"This is 1"<<endl;
		break;
	default :
		cout<<"This is default"<<endl;
		break;
	}
	cout<<"this is beside the switch"<<endl;
	}
#endif
	return 0;
}
#endif
//MediaBlur function 
//MediaBlur 是典型非线性滤波技术，用像素点领域灰度值的中值来代替该像素
//点的灰度值，主要是去除脉冲噪声、椒盐噪声（怎么区分的？）时有能保留图像边缘细节
void MymediaBlur(InputArray _src0,OutputArray _dst,int ksize)
{
	Mat src0=_src0.getMat();
	_dst.create(_src0.size(),_src0.type());
	Mat dst=_dst.getMat();
	if(ksize<=-1)
	{
		src0.copyTo(dst);
	}
	CV_Assert(ksize%2==1);//If there is even number,it will be assert failed
	//There need odd number,we will sort the ksize X ksize first.
	bool useSortNet=ksize==3||(ksize==5);
}
Mat calculateLightPattern(Mat _img)
{
	Mat pattern;
	blur(_img,pattern,Size(_img.cols/3,_img.cols/3));
	//imshow("calculateLightPattern",pattern);
	return pattern;
}