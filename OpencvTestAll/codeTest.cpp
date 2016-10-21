#include <iostream>
#include"codeTest.h"
#include "include.h"

//本文件用于测试学习C++语言，后续使用方便
///VS进行相应的调试
//1.选择一行代码，按下F9就可以快速的设定一个断点
//F11为逐语句调试，如果遇到调用函数择进行调用函数内部逐语句执行
//F10为逐过程调试，不进入调用函数内部
//shift+F11为跳出调试，即执行当前执行点所在函数的剩下所有行


//引用的使用
void swapint(int &a,int& b)//注意一下写法---c使用指针形式（形参）--都可以正常使用
{//引用--相当于变量叫另外一个名字
	int temp;
	temp = a;
	a = b;
	b = temp;

}
void Dong::MyClass::Myfun()
{
	std::cout << "新方法的使用" << std::endl;
}


#ifdef USE_TEST
int main()
{
	Dong::MyClass t = Dong::MyClass();//建立对象
	Dong::MyClass *p=NULL;//（方法一）这里不进行初始化，会提示错误
	//p = NULL;//（方法二）也可以正常使用这种方式进行指针的初始化操作
	t.MyFunction();
	t.Myfun();
	p->Myfun();
	(*p).Myfun();
	Dong::funNon();
	return 0;
}
#else 
#endif