#include "include.h"
#include <iostream>

using namespace std;
/*
	�ڳ����У����ݽṹ���б����ȶ���Ҫռ�ڴ棬�ںܶ�ϵͳ�У�����Ҫ���ڴ�����
ʱ��Ҫ���룬�������ĺô����ǿ�����߷����ڴ���ٶȡ�
����ο���http://www.cppblog.com/cc/archive/2006/08/01/10765.html
*/
struct X1
{
	int i;//4�ֽ�
	char c1;//1�ֽ�
	char c2;//1�ֽ�
};
struct X2
{
	char c1;//1�ֽ�
	int i;//4�ֽ�
	char c2;//1�ֽ�
};
struct X3
{
	char c1;//1�ֽ�
	char c2;//2�ֽ�
	int i;//4�ֽ�
};
#ifdef CODESTORE
char* p;//4���ֽ�
/*
�������壺����Ϊ��������洢�ռ䣬������Ϊ����ָ����ʶֵ���ڳ���
	�б�������ֻ��һ������
�������������������������������ͺ����֡�
	�ڴ���һ�������Ŀ飬������4�ֽ�Ϊһ�����뵥λ��
	x1�е�һ��int�ͣ�ռ��4���ֽڣ�Ȼ��ڶ�����char���ͣ���������ֻ
	ռ��һ���ֽڣ�����ռ�еڶ���4�ֽ����еĵ�һ�񣬵���Ҳ��char����
	������Ҳռһ���ֽڣ��������ڵڶ������ĵڶ���
*/
int main(int argc,char** argv)
{
	cout<<"float:"<<sizeof(float)<<endl;//sizeof�ǹؼ���
	cout<<"long:"<<sizeof(long)<<endl;
	cout<<"int:"<<sizeof(int)<<endl;
	cout<<"pointer:"<<sizeof(p)<<endl;//pointer is 4 byte

	X1 x1;
	X2 x2;
	X3 x3;
	cout<<"x1�Ĵ�С��"<<sizeof(x1)<<endl;
	cout<<"x2�Ĵ�С��"<<sizeof(x2)<<endl;
	cout<<"x3�Ĵ�С��"<<sizeof(x3)<<endl;

	return 0;
}

#endif
