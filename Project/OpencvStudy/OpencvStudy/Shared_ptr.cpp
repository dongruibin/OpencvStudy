/*****************************************************
** ��дʱ�䣺  2018��9��7��
** ����ģ�飺  shared_ptrʹ��
** ������أ�
**	���գ�ָ�������ã�Ҳ�ǵ�����
**			C++���������ʹ�ö��ڴ��Ƿǳ�Ƶ���Ĳ������ѵ�
		������ͷŶ��ǳ���Ա�Լ�����������Ա�Լ��������ڴ�
		�����ṩ�����Ч�ʣ�����������˵���ڴ�Ĺ����ǽ��鷳��
		ʹ����ָͨ�룬������ɶ��ڴ�й¶�������ͷţ��������ͷ�
		�������쳣���ڴ�й¶�����⡣
	��������ָ����Դ�����������У�
	1����ǳ�㿴������ָ����������һ�ֽ�RAII����Դ��ȡ����ʼ������
		��������ͨ��ָ����з�װ����ʹ������ָ��ʵ��Ҳ��һ������
		��Ϊ����ȴ��һ��ָ�롣
	2������ָ��������Ƿ�ֹ���ǵ���delete�ͷ��ڴ�ͳ����쳣�Ľ���catch
		�������ͷ��ڴ棬����ָ����ͷ�ʱ��Ҳ�Ƿǳ��п����ģ�����ͷ�ͬһ
		��ָ�����ɳ����������������ͨ������ָ������
	3������ָ�뻹��һ�����ð�ֵ����ת�����������塣C++ JAVA��һ�����
		��������������岻�á�����ϸ��ֵ���壩

**			shard_ptr��һ����׼�Ĺ�������Ȩ������ָ�룬
	�������ָ��ָ��ͬһ�����󣬶�����memory�ļ���shard_ptrʹ�����ü�����ÿ
	һ��shared_ptr�Ŀ�����ָ����ͬ���ڴ棬ÿʹ��һ�Σ��ڲ������ü���+1��ÿ
	����һ�Σ��ڲ������ü���-1������0ʱ���Զ�ɾ����ָ��Ķ��ڴ档
		shard_ptr�ڲ������ü������̰߳�ȫ�ģ����Ƕ���Ķ�ȡ��Ҫ������
		1����ʼ��������ָ���Ǹ�ģ���࣬����ָ�����ͣ�����ָ��ͨ�����캯����ʼ����
			Ҳ����ʹ��make_shared������ʼ�������ܽ�һ��ָ��ֱ�Ӹ�ֵ��һ������ָ�룬
			һ����ָ�룬һ�����ࡣ
		2�������͸�ֵ��ÿ��shared_ptr������ָ����ͬ�ڴ棬����ʹ�ö�������ü���+1��....
		3��get������ȡԭʼָ��

	ע�����
		1������ʹ��һ��ԭʼָ���ʼ�����shared_ptr������ɶ������١�
		2����Ҫ�ں���ʵ���д���shared_ptr����ֹ���ڱ�������ͬ��ɼ���˳��ͬ���ȴ�����ʹ��
		3����ֹʹ��shared_from_this()����thisָ�룬����������ɶ�������
		4������ѭ�����ã�����ָ�����������ѭ�����ã���
** ��Ȩ������  ������ֻ��ѧϰʹ�ã�δ���������ɣ�������
** 			   �������κ���;����Ȩ���У�����ؾ���
����ο���https://www.cnblogs.com/wxquare/p/4759020.html
******************************************************/
#include "include.h"
#include <iostream>
#include <memory>//shared_ptrʹ��
//#include <thread>

#ifdef SHARED_PTR
using namespace std;

#if 0 //���ײ���
int main(int argc,char** argv)
{
	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	shared_ptr<int> ptra2(ptra);//copy1
	shared_ptr<int> ptra3(ptra);//copy2
	cout<<"ptra use_count:"<<ptra.use_count()<<endl;

	int b = 20;
	int *pb = &a;
	shared_ptr<int> ptrb = make_shared<int>(b);
	ptra2 = ptrb;//assign
	pb=ptrb.get();//��ȡԭʼָ��
	cout<<ptra.use_count()<<endl;
	cout<<ptrb.use_count()<<endl;
	return 0;
}
#else
//ȷ���ڶ��߳���ʹ�õ�����
//�ο���https://blog.csdn.net/infoworld/article/details/50738494
struct Base
{
	Base(){cout<<"Base construct!!"<<endl;}
	~Base(){cout<<"~Base!!"<<endl;}
};
struct Derived: public Base
{
	Derived(){cout<<"Derived construct!!"<<endl;}
	~Derived(){cout<<"~Derived!!"<<endl;}
};


int main(int argc,char** argv)
{
	cout<<"*****This is demo of shared_ptr********"<<endl;
	return 0;
}
#endif


#endif