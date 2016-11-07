/////本文件主要是熟悉一下c++面向对象的思想
#include<iostream>
#include"include.h"
#include<string.h>
using namespace std;
//C++即可以开发面向过程的应用程序，也可以开发面向对象的应用程序。
//////建立一个父类

class CPerson
{
	//数据成员
	////注意累的数据成员不可以在类中直接初始化
	int m_iIndex;
	char m_cName[25];
	short m_shAge;
	double m_dSalary;
	//成员函数
public:
	short getAge();
	int setAge(short sAge);
	int getIndex();
	int setIndex(int iIndex);
	char* getName();
	int setName(char cName[25]);
	double getSalary();
	int setSalary(double dSalary);
};
//类的实现即可以在h文件中的类里面，也可以在cpp里面实现
//类实现方式：
short CPerson::getAge()
{
	return m_shAge;
}
int CPerson::setAge(short sAge)
{
	m_shAge = sAge;
	return 0;//执行成功返回0
}
int CPerson::getIndex()
{
	return m_iIndex;
}
int CPerson::setIndex(int iIndex)
{
	m_iIndex = iIndex;
	return 0;
}
char* CPerson::getName()
{
	return m_cName;
}
int CPerson::setName(char cName[25])
{
	strcpy(m_cName, cName);
	return 0;
}
double CPerson::getSalary()
{
	return m_dSalary;
}
int CPerson::setSalary(double dSalary)
{
	m_dSalary = dSalary;
	return 0;
}
//////一般上会把声明放到h文件里面，具体实现放到cpp文件里面
#ifdef ClassTest
int main(int argc, char** argv)
{
	//对象的使用
	CPerson p;
	//定义好指向对象的指针
	CPerson *h=NULL;//定义指针，指向CPerson类型的对象。（是一个指针，必须要指向对象）
	h = &p;/////指向对象---

	p.setName("dong");//要将函数声明为public，否则默认的是无法访问
	cout << p.getName() << endl;
	h->setName("zhang");
	cout << h->getName() << endl;
	return 0;
}
#else
#endif