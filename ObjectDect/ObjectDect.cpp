#include<iostream>
#include"MultipleImageWindow.h"
//#include "utility.hpp"//what is the function of utility.hpp
//#include"opencv2/core/utility.hpp"

//本文件主要练习物体检测
//1、熟悉一下预处理作用
//2、熟悉图像目标分割和检测（之前是一片空白）
//预处理步骤分为三个或者更多的子步骤：
//1、去噪
//2、去除光亮
//3、二值化
#define ObjectDectUse 1
using namespace cv;
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




#ifdef ObjectDectUse

int main(int argc,char** argv)
{
	string s="This is a big";
	string file;
	//MultipleImageWindow multipleImageWindow(s,1200,700,1);
	std::cout<<"This project is belong to ObjectDect.cpp file!"<<std::endl;
	//There the program is starting
	CommandLineParser parser(argc,argv,keys);
	file=parser.get<string>("file");
	cout<<"The Param file is:"<<file<<endl;
	//parser.about("Chapter 5. PhotoTool v1.0.0");
	//if(parser.has("help"))
	//{
	//	parser.printParams();
	//	return 0;
	//}
	return 0;
}
#endif