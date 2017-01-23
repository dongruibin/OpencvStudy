#include "include.h"
#include<iostream>

//本文件主要是学习了解重载的使用
using namespace std;
//c++允许在同一个作用域中的某个函数和运算符指定多个定义，分别称为
//函数重载和运算符重载。重载声明是指一个与之前在该作用域内声明过的
//函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不
//相同。当您调用一个重载函数或重载运算符时，编译器通过把您所使用的
//参数类型进行比较，决定选用最合适的定义，即重载决策。

//运算符重载
//重载的运算符是带有特殊名称的函数，函数名是由关键字operator
//和其后要重载的运算符符号构成。与其他函数一样，重载运算符有
//一个返回类型和一个参数列表。
#define opeatorTest 1
//符号重载中判断是否使用this指针
#define ThisUse 0

class Box{
public:
	//构造函数
	Box()
	{
		cout<<"This is Box"<<endl;
	}
	//设置一个有参构造函数
	Box(double len,double bre,double hei)
	{
		length=len;
		breadth=bre;
		height=hei;
	}
	double getVolume(void)
	{
		return length*breadth*height;
	}
	void setLength(double len)
	{
		length=len;
	}
	void setBreadth(double bre)
	{
		breadth=bre;
	}
	void setHeight(double hei)
	{
		height=hei;
	}
	double getLength()
	{
		return length;
	}
	double getBreadth()
	{
		return breadth;
	}
	double getHeight()
	{
		return height;
	}
	//写一个成员函数
	void doSomething()
	{

		cout<<"This is a method of Box"<<endl;
	}
	//写一个静态方法
	static void doFunction()
	{
		cout<<"This is a static method of Box"<<endl;

	}
//重载符号
#ifdef ThisUse
	
	//使用this指针进行重载
	Box& operator+(const Box& b)
	{
		this->length=this->length+b.length;
		this->breadth=this->breadth+b.breadth;
		this->height=this->height+b.height;
		return *this;
	}
#else
	//进行相应的重载运算，用于把两个Box对象相加
	Box operator+(const Box& b)
	{
		//C++ this指针的调用
		Box box;
		box.length=this->length+b.length;
		box.breadth=this->breadth+b.breadth;
		box.height=this->height+b.height;
		return box;
	}
#endif

private:
	double length;
	double breadth;
	double height;
};//这里忘记写上“;”会导致一大堆问题，一定要记住这个分号，类理解类似于结构体
///////新建立一个类继承原来的类---确认方法重写
class newBox:Box
{
public:
	newBox()
	{
		cout<<"This is newBox"<<endl;
	}
	void doSomething()
	{
		//说明备注方法：
		cout<<"这里使用Box::doSomething()来调用父类的方法\
			，其它方式是不行的。不同于java的super()\
			,C++支持多继承，直接这样写无法获取调用哪一个父类"<<endl;
		Box::doSomething();//父类里面的方法
		cout<<"This is a method of newBox"<<endl;
	}
};

#ifdef USE_OPERATOR

int main(int argc,char** argv)
{
#ifdef opeatorTest
	//第一个对象
	Box  box1;
	box1.setLength(15);
	box1.setBreadth(15);
	box1.setHeight(15);

	//第二个对象
	Box box2(16,16,16);
	Box box3;
	box3=box1.operator+(box2);
	cout<<"box3的Length:"<<box3.getLength()<<endl;

	//测试使用一下静态方法
	box3.doFunction();//It is ok
	Box::doFunction();//It is also ok!
	//静态方法调用说明
	//对象名.静态函数() 类名::静态函数()------都是可以
	//类名.静态函数()---------不可以
	
	//新建立一个新的newBox
	newBox newbox;
	newbox.doSomething();//继承于父类的方法



#endif
	return 0;
}


#else


#endif