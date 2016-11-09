//////////本文件主要是定义模板类等
#include<iostream>
#include"include.h"
#include<string.h>

using namespace std;
//1、定义一个类模板：
//template<class 模板参数>
//class 类名{
//	//类定义.....
//};
//其中，template是声明类模板的关键字，表示声明一个模板，模板参数可以是一个，也可以是多个，
//可以是类型参数，也可以是非类型参数。类型参数由关键字class或typename及其后面的标识符构成。
//代表模板定义中的一个常量。
//例如：
//template<class type, int width>
////type为类型参数，width为非类型参数

//定义一个模板类
//类模板：允许用户为类定义一种模式，使得类中的某些数据成员、默认成员函数的参数、某些成员函数的返回值，能够取任意类型。
template<class _Tp>//类型参数由关键字class或typename构成
class dongClass
{
public:
	int index;
	_Tp a[25];
	void putName();
	_Tp DoAdd(_Tp a, _Tp b);
	void  putname(_Tp da);

};
template<class _Tp>
void dongClass<_Tp>::putName()
{
	cout << "I AM A TEST!" << endl;
}
template<class _Tp>
_Tp dongClass<_Tp>::DoAdd(_Tp a, _Tp b)
{
	cout << a + b << endl;
	return a + b;
}


template<class _Tp>
void dongClass<_Tp>::putname(_Tp da)
{
	cout << da << endl;
}

#ifdef TemplateDef
int main(int argc, char** argv)
{
////类模板的实例化，从通用的类模板定义中生成类的过程称为模板实例化。
	dongClass<int>  p;//类模板使用，将类模板实例化成一个具体的类，它的格式为：类名<实际的类型>
	dongClass<float> h;
	p.putname(54.12);
	h.putname(54.121);
	h.DoAdd(12, 13);
	p.putName();
}
#else
#endif