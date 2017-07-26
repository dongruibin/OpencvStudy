#include "include.h"
#include <iostream>

using namespace std;
/*
	在程序中，数据结构还有变量等都需要占内存，在很多系统中，它都要求内存分配的
时候要对齐，这样做的好处就是可以提高访问内存的速度。
代码参考：http://www.cppblog.com/cc/archive/2006/08/01/10765.html
*/
struct X1
{
	int i;//4字节
	char c1;//1字节
	char c2;//1字节
};
struct X2
{
	char c1;//1字节
	int i;//4字节
	char c2;//1字节
};
struct X3
{
	char c1;//1字节
	char c2;//2字节
	int i;//4字节
};
#ifdef CODESTORE
char* p;//4个字节
/*
变量定义：用于为变量分配存储空间，还可以为变量指定初识值，在程序
	中变量有且只有一个定义
变量声明：用于向程序表明变量的类型和名字。
	内存是一个连续的块，它是以4字节为一个对齐单位，
	x1中第一是int型，占有4个字节，然后第二个是char类型，这种类型只
	占有一个字节，所以占有第二个4字节组中的第一格，第三也是char类型
	所以它也占一个字节，它就排在第二个组块的第二格。
*/
int main(int argc,char** argv)
{
	cout<<"float:"<<sizeof(float)<<endl;//sizeof是关键字
	cout<<"long:"<<sizeof(long)<<endl;
	cout<<"int:"<<sizeof(int)<<endl;
	cout<<"pointer:"<<sizeof(p)<<endl;//pointer is 4 byte

	X1 x1;
	X2 x2;
	X3 x3;
	cout<<"x1的大小："<<sizeof(x1)<<endl;
	cout<<"x2的大小："<<sizeof(x2)<<endl;
	cout<<"x3的大小："<<sizeof(x3)<<endl;

	return 0;
}

#endif
