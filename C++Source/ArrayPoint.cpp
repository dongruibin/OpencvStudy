#include "include.h"//这个是要添加相应的路径到vs编译器里面


//指针数组 ：array of pointers,即用于存储指针的数组，也就是数组元素都是指针
//数组指针 ：a pointer to an array,即指向数组的指针

//int* a[4] 指针数组  数组a中的元素都是int型指针
//				*a[i] 和*(a[i])是一样的

//int (*a)[4] 数组指针  指向数组a的指针
//					

#include<iostream>

using namespace std;

//#ifdef CodeArrayPointerAndPointerArray
#if 0

int main(int argc, char** argv)
{
	int c[4] = { 1, 2, 3, 4 };
	int *a[4];//指针数组
	int(*b)[4];//数组指针
	b = &c;
	//将数组c中元素赋给数组a
	for (int i = 0; i < 4; i++)
	{
		a[i] = &c[i];
		//自主理解:
		//a[i]也是一个指针，放的是地址，这里是把&c[i]这个地址放入，实际上的数据时*a[i]
	}
	//输出结果如下：
	cout << *a[1] << endl;//输出应该是2
	cout << (*b)[1] << endl;//输出应该是2
	return 0;
}
#else
#endif
