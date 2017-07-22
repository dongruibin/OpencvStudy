#include "include.h"
#include <iostream>
#include <vector>
#include<string>//没有这个cout无法打印出string类型
using namespace std;
//create a base class
class Base
{
public:
	Base();
	void PrintInfo();
	static void ChangeMember();
private:
	int a1;
	static int a;//静态 私有变量。
protected:
	int a2;
public:
	int a3;
};//always forget

Base::Base():a2(5),a1(5),a3(5)//,a(5)---静态类数据无法通过构造函数初始化---理由是什么？
	//---静态数据时全局的？调用可以使用类名，也可以使用类对象？
{
	cout<<"This is the Base construct!"<<endl;
}
void Base::PrintInfo()
{
	cout<<"a1 is a private vari"<<endl;
	cout<<"a1 is :"<<a1<<endl;
	cout<<"a2 is :"<<a2<<endl;
	cout<<"a3 is :"<<a3<<endl;
	//Base::a=4;
}
void Base::ChangeMember()
{
	//注意这是一个静态方法，里面可以操作静态成员，但是不可以
	//操作普通成员:
	//静态成员函数属于整个类，在实例化对象之前就已经分配空间了，
	//而类的非静态成员必须在类实例化对象后才有内存空间。
	

}

//private implement
class BasePrivate:private Base
{
public:
	BasePrivate()
	{
		cout<<"This is the BasePrivate construct!"<<endl;
	}
	void PrintInfo()
	{
		cout<<"This BasePrivate class is overlap Base!"<<endl;
		//cout<<"a1 is :"<<a1<<endl;//错误，不能访问
		cout<<"a2 is :"<<a2<<endl;//基类保护成员，变成了BasePrivate里面的私有变量？
		cout<<"a3 is :"<<a3<<endl;//
	}
};

//public implement
class BasePublic:public Base
{
public:
	void PrintInfo()
	{
	}
};
//protected implement
class BaseProtected: protected Base
{

};


////main founction
#ifdef USE_3P
int  Base::a=5;//a是静态变量，要在类体外进行定义，构造方法是不可以的
//理由：
string arr[]={"dong1","dong2","dong3","dong4","dong5","dong6"};
string ar="I am a test string";
vector<string> vecstring(arr,arr+3);
vector<int> vec(10),veca(10),vecb(10),vecd(12);
vector<vector<int>>  vecc(3);//一个vector里面有3个vector<int>
int main(int argc,char** argv)
{
	cout<<"This program is test the private pulic protected"<<endl;
	cout<<"The argv[0] is :"<<argv[0]<<endl;//Is it the exe file?

	/////vector use
	cout<<"<<<<<<<<<<<<<<<<<Demo of test vector<<<<<<<<<<<<<<<<"<<endl;
	for(int i=0;i<10;i++)
	{
		vec[i]=i;
	}
	for(vector<int>::iterator vecbegain=vec.begin(),vecend=vec.end();vecbegain!=vecend;vecbegain++)
	{//iterator 是不是就是指向元素的指针？
		cout<<"This is the data:"<<*vecbegain<<endl;
	}
	cout<<"test string"<<ar<<endl;//要打印string，要加入头文件#include<string>
	//vector of string
	for(vector<string>::iterator vbegin=vecstring.begin(),vend=vecstring.end();vbegin!=vend;vbegin++)
	{
		cout<<"This is the string:"<<*vbegin<<endl;
	}

	////////////////////
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	BasePrivate basePrivate;//创建继承对象，原来的父类对象构造方法一样会调用
	BasePublic basePublic;

	basePrivate.PrintInfo();
	//cout<<"basePrivate里面的a2为:"<<basePrivate.a2<<endl;//不能访问，私有继承
	Base base;
	//测试基类private的调用
	//cout<<"Base class private a1:"<<base.a1<<endl;//错误，类外无法访问
	//测试基类里面的静态私有变量
	//cout<<"Base class static private a:"<<Base::a<<endl;

	//cout<<"Base private a1:"<<basePrivate.a1<<endl;//错误，无法在类外面访问私有变量(私有继承)
	cout<<"BasePublic a3:"<<basePublic.a3<<endl;//公有继承，可以正常访问

	return 0;
}

#endif
