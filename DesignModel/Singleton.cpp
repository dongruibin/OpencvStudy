#include "Singleton.h"
#include "include.h"
#include <iostream>


using namespace std;
//˵��������ģʽ��ʹ��


#if SingleMode

class singleton
{
private:
	singleton();//˽�й��췽����ֻ���ڲ����ã������ڲ�������
public:
	//��̬����
	static singleton* singleobject;//Ӧ����Ҫһ���ⲿ���󣡣�

public:
	singleton *getInstance(void)//getInstance�϶�Ҫbublic�������޷��ܵ��������
	{
		return (new singleton);
	}

};
#if 0
//This method will be error?!!!���ѵ�����������ⲿ���ã���
singleton* singleton::getInstance()
{
	return (new singleton);
}
#endif

//��ʼ����singleton����
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



