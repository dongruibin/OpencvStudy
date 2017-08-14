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
	static int k2;//验证静态成员，私有与公有是否有区别
protected:
	int a2;
public:
	int a3;
public:
	static int f;
	static int k1;
	friend void addSum(Base& obj)
	{
		f+=obj.f;
		//a1=a1*obj.a1;//无法使用，提示对非静态成员
		//cout<<"private data a1*a1 is:"<<a1<<endl;
		cout<<"This friend function:"<<f<<endl;
	}
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
	cout<<"Base 类静态私有成员k2："<<k2<<endl;
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
//private construct
//备注说明：
//当构造函数为private时，当我们在程序中声明一个对象时，
//	编译器为调用构造函数（如果有的话），而这个调用将通常是
//外部的，也就是说它不属于class对象本身的调用，假如构造
//函数是私有的，由于在class外部不允许访问私有成员，所有这将导致
//编译出错。然而，对于class本身，可以利用它的static公有成员，因为
//它们独立于class对象之外，不必产生对象也可以使用它们。
/*
	因此因为构造函数被class私有化，所以我们要创建出对象，就必须能够访问到
	class的私有域，这一点只有class的成员可以做到，但是我们创建出其对象之前
	怎么能利用它的成员？
	static公有成员，它是独立于class对象而存在的，“我们”可以访问得到。假如
	在某个static函数中创建了该class的对象，并以引用或者指针的形式将其返回（
	这里不以对象返回，主要是构造函数是私有的，外部不能创建临时对象），就
	获得这个对象的使用权。
	http://blog.csdn.net/koudaidai/article/details/7546661

*/
class PrivateClass
{
private://私有构造
	PrivateClass(){
		cout<<"This is a private construct"<<endl;
	}
public:
	void printt(){
		cout<<"This is only a test!"<<endl;
	}
};
//添加多继承的学习
class Base1
{
private:
	//a=5;//还是没有搞清这个问题，
	//上面的报错信息是：只有静态常量
	//整型数据成员才可以在类中初始化
	//int a=5;//一样提示错误
public:
	//int a=5;//与上面提示是一样的
public:
	Base1(){
		cout<<"This a the Base1!"<<endl;
	}

};
//new class2
class Base2
{
public:
	Base2(){cout<<"This construct is Base2!"<<endl;}
	int  Base2Value(){return aa2;}
	void Base2Set(int _aa2){aa2=_aa2;}
private:
	int aa2;
};
//多继承使用
class BaseMulti:public Base1,public Base2
{
public:
	BaseMulti(){}
	
};

//静态成员函数和成员总结：
/*
	1、静态成员函数不能调用非静态成员
	2、非静态成员函数中可以调用静态成员，因为静态成员属于类本身，
		在类的对象产生之前就已经存在了，所以在非静态成员函数可以
		调用静态成员
	3、静态成员变量使用前必须初始化（int myClass::m_nNumber=0;）,
		否则会在linker时出错。
	参考：http://blog.csdn.net/morewindows/article/details/6721430/
*/

int  Base::a=5;//a是静态变量，要在类体外进行定义，构造方法是不可以的
//理由：
string arr[]={"dong1","dong2","dong3","dong4","dong5","dong6"};
string ar="I am a test string";
vector<string> vecstring(arr,arr+3);
vector<int> vec(10),veca(10),vecb(10),vecd(12);
vector< vector<int> >  vecc(3);//一个vector里面有3个vector<int>
vector< vector<int> > martix(2,vector<int>(3));//2行，3列
//private construct
//PrivateClass privateClass;//构造函数不可以使用
//初始化Base类里面的静态成员
int Base::f=3;

//验证都是静态变量前提下，公有和私有是否有区别
int Base::k1=3;//这是静态公有
int Base::k2=33;//这是静态私有
//Base k;//为什么声明（应该叫定义）对象也会调用构造函数
Base *k;//这样是不调用构造函数的是，在32位机上
	//一个指针占4个字节
////main founction

#ifdef USE_3P
//测试私有构造
//PrivateClass privateClass;//这里会报错，调用构造也是外部的，私有在类外无法访问。
BaseMulti baseMulti;//这里会调用继承的父类的构造方法
Base base,base1;//这里声明（应该叫定义）一下Base对象为什么会调用构造方法
//test multi extend
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
	veca.push_back(10);
	veca.push_back(12);
	for(int i=0;i<100;i++)
	{
		//vecd[i]=i;
		vecd.push_back(i);
	}
	cout<<"vecd size:"<<vecd.size()<<endl;//第一次初始化就给了12个数
	for(vector<int>::iterator vecdbegin=vecd.begin(),vecdend=vecd.end();vecdbegin!=vecdend;vecdbegin++)
	{
		cout<<"vecd data is"<<*vecdbegin<<endl;
	}
	for(vector<int>::iterator vecbegain=vec.begin(),vecend=vec.end();vecbegain!=vecend;vecbegain++)
	{//iterator 是不是就是指向元素的指针？
		cout<<"This is the data:"<<*vecbegain<<endl;
		cout<<"This data address is:"<<&vecbegain<<endl;
	}
	cout<<"test string"<<ar<<endl;//要打印string，要加入头文件#include<string>
	//vector of string
	for(vector<string>::iterator vbegin=vecstring.begin(),vend=vecstring.end();vbegin!=vend;vbegin++)
	{
		cout<<"This is the string:"<<*vbegin<<endl;
	}
	cout<<"<<<<<<<<<<<<Use vecc<<<<<<<<<"<<endl;
	vecc.push_back(veca);//是一个二维的vector,这是第四个参数
	//cout<<"vecc里面的"<<vecc[3].v
	cout<<"二维vector ：vecc is :"<<vecc[3][0]<<endl;
	//cout<<"二维vector：第一个元素"<<(*vecc[3])[0]<<endl;
	//明确下指针 普通对象使用
	cout<<"使用类似迭代方式："<<endl;
	//cout<<"vector 访问："<<vecc[3]->v<<endl;
	cout<<"This chapter the vector is not clearly"<<endl;
	cout<<"ERROR! ERROR!"<<endl;

	////////////////////
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"<<<<<<<<<<<<<<Friend function test<<<<<<<<<<<"<<endl;
	addSum(base);
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	///////////
	cout<<"验证都是静态变量前提下，公有和私有是否有区别"<<endl;
	cout<<"静态公有变量k1："<<base.k1<<endl;//静态使用类名调和对象调一样
	cout<<"静态公有变量k1：类名调用"<<Base::k1<<endl;
	//cout<<"静态私有变量k2："<<base.k2<<endl;//错误，是无法访问的
	//cout<<"静态私有变量k2：类名调用"<<Base::k2<<endl;
	base.PrintInfo();
	base1.PrintInfo();

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
