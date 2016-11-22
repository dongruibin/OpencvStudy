#include<iostream>
#include "include.h"


//本文件主要作用是理解清楚函数指针和指针函数的概念

//1、指针函数
//	指针函数是指带指针的函数，即本质是一个函数。函数都有返回类型（如果没有返回值，则为无值型）
//指针函数返回类型是某一类型的指针（返回的是地址）
//返回类型标识符 *返回名称（形参）{函数体}
//	返回类型可以是任何基本类型和复合类型。函数本身就是一个入口地址。

//2、函数指针
//	函数指针是指向函数的指针变量，因此"函数指针"本身首先应该是指针变量，只不过该指针变量指向函数。
//每个函数都有一个入口地址，该入口地址就是函数指针所指向的地址。有了指向函数的指针变量后，可用该
//函数指针调用函数。函数指针有两个用途：调用函数和做函数的参数。

using namespace std;
#define FPPF 0 

#ifdef FunPointer

int main(int argc,char** argv)
{
#ifdef FPPF
	//使用一个指针函数
	float *find(float (*pionter)[4],int n);//声明指针函数，形参前一个为数组指针。
	static float score[][4]={{60,70,80,90},{56,89,34,45},{34,23,56,45}};//
	float *p;//定义一个存储float类型的指针，是为了缓存一个行地址
	int i,m;
	printf("Enter the number to be found:");
	scanf("%d",&m);
	printf("the score of NO,%d are:\n",m);
	p=find(score,m);//函数返回一个地址，放到p里面
	for(i=0;i<4;i++)
		printf("%5.2f\t",*(p+i));


#else
	int (*ptr)(int,int);//写一下参数类型
	int max(int x,int y);
	int a,b,c;
	ptr=max;//将函数地址传给ptr
	cin>>a>>b;
	c=(*ptr)(a,b);
	cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
	//ptr是指向函数的指针变量，所以可把函数max()赋给ptr作为ptr的值，
	//即将max()的入口地址赋给ptr。

#endif
	return 0;
}




#else
#endif

//******************************************************
//功 能：返回对应位置的指针
//输 入：一个是数组指针，一个是个数索引
//输 出：指向float类型的指针
float *find(float(*pionter)[4],int n)//定义一个指针函数，返回时一个指针
{
	float *pt;//指向float类型
	pt=*(pionter+n);
	return(pt);//返回是一个指向float的指针类型
}
//*****************************************************
//功 能：返回最大值
int max(int x,int y)
{
	return (x>y?x:y);
}