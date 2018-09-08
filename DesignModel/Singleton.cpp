#include "Singleton.h"
#include "include.h"
#include <iostream>


using namespace std;
//说明：单例模式的使用


#if SingleMode

class singleton
{
private:
	singleton();//私有构造方法，只能内部调用（是类内部？？）
public:
	//静态变量
	static singleton* singleobject;//应该需要一个外部对象！！

public:
	singleton *getInstance(void)//getInstance肯定要bublic，否则无法跑到外面调用
	{
		return (new singleton);
	}

};
#if 0
//This method will be error?!!!，难道这个是属于外部调用？？
singleton* singleton::getInstance()
{
	return (new singleton);
}
#endif

//开始创建singleton对象
static singleton* singleObj = NULL;
char a[]="Hello world!";
char *p=a;
int *k=NULL;
int i=56;
int main(int argc,char** argv)
{
#if 1
	cout<<"The pointer sizeof(p):"<<sizeof(p)<<endl;
	cout<<"The pointer sizeof(*p):"<<sizeof(*p)<<endl;
	cout<<"The a[] sizeof():"<<sizeof(a)<<endl;
	cout<<"The k add is:"<<k<<endl;
	cout<<"600%1000="<<600%1000<<endl;
	cout<<"900%1000="<<900%1000<<endl;
	cout<<"0%1000="<<0%1000<<endl;
	cout<<"521/1000="<<521/1000<<endl;
	cout<<"i address is :"<<&i<<endl;
#else
#endif
	cout<<"singleton class sizeof is:"<<sizeof(singleton)<<endl;
	cout<<"This is test singleton!!\n"<<endl;
	return 0;
}
#endif



