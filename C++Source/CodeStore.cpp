#include "include.h"
#include <iostream>

using namespace std;
//1��4�ֽڶ���
//2��c++������ַ
/*
	�ڳ����У����ݽṹ���б����ȶ���Ҫռ�ڴ棬�ںܶ�ϵͳ�У�����Ҫ���ڴ�����
ʱ��Ҫ���룬�������ĺô����ǿ�����߷����ڴ���ٶȡ�
����ο���http://www.cppblog.com/cc/archive/2006/08/01/10765.html
*/
/*
��ջ�ڴ����
	1������ʽ��ͬ
		ջ���б������Զ����������ֶ�������memory leak
	2���ռ��С
		һ��������32Ϊϵͳ�����ڴ���Դﵽ4G�ռ䣬ջһ���С��һ����1M
	3����Ƭ����
		���ڶѣ�new��deleteƵ��������ڴ�ռ䲻�������Ӷ�������Ƭ
		����ջ�����Ƚ�����Ķ���
	4����������
		�������������ģ�Ҳ�����ڴ��ַ���ӵķ���
		ջ�����µģ��������ڴ��ַ��С�ķ�������
	5�����䷽��
		���Ƕ�̬����ģ�û�о�̬����Ķѣ�ջ��2�ַ��䷽ʽ��
		��̬����Ͷ�̬���䣬��̬�����Ǳ�������ɵģ�����ֲ�
		�����ķ��䣬��̬��������alloca�������з��䣬����ջ�Ķ�̬
		����˽�б����������ͷš�
�ο���http://blog.csdn.net/a185446828/article/details/50899887
���ۣ�
*/


//ȫ�ֳ�ʼ������
int g_i=100;
int g_j=200;
int g_k,g_h;

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
char* p_init_null=NULL;
char * p_init="dong";

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

	cout<<"<<<<<<<<<<<�ڴ��ַʵ��ֵ<<<<<<<<<<<<:"<<endl;
	const int MAX=100;
	int *HeapAddress=(int*)malloc(MAX*sizeof(int));
	int *HeapAddress1=(int*)malloc(MAX*sizeof(int));
	static int s_i=5;
	static int s_j=10;
	static int s_k;
	static int s_h;
	const int s_f=10;
	int i=5;
	int j=10;
	int k=20;
	int f,h;
	char sc[]="dongdong1";
	char *pstr1="dongdong2";
	char *pstr2="dongdong2";
	char *pstr3="dong";
	
	cout<<"�������ݵ�ַ:"<<HeapAddress<<endl;//HeapAddress��һ��ָ�룬��ָ��������ݵ�ַ
	cout<<"�������ݵ�ַ1��"<<HeapAddress1<<endl;//HeapAddress�ǵڶ���ָ�룬ָ��������ݵĵ�ַ
	cout<<"������Կ������е�ַ������������"<<endl;
	cout<<"�������ݵ�ַ��ŵ�ַ����ֵ��ջ�У�&k: "<<&HeapAddress<<endl;//���ָ�루��ֵַ����ŵ�ַ--�����ַ��ջ��
	cout<<"�������ݵ�ַ��ŵ�ַ����ֵ��ջ�У�& : "<<&HeapAddress1<<endl;

	//cout<<"���ʹ̶���ַ��ֵ:"<<*((int *)(0x0044f298))<<endl;//��ֵַ��
	//cout<<"ջ�ϵ�ַp:"<<p<<endl;//�����ʾ���󣺳��Զ�ȡ��д���ܱ������ڴ�
	//cout<<"ջ�ϵ�ַp_init_null:"<<p_init_null<<endl;//��ʾ����������һ����

	cout<<"ջ���г�ֵ��ַi��"<<&i<<endl;
	cout<<"ջ���г�ֵ��ַj��"<<&j<<endl;
	cout<<"ջ���г�ֵ��ַk��"<<&k<<endl;
	cout<<"����ջ��ַ�����С������С�������Ϊʲô��0x0c?"<<endl;
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"��̬�����г�ֵs_i:"<<&s_i<<endl;
	cout<<"��̬�����г�ֵs_j:"<<&s_j<<endl;
	cout<<"��̬������ʼ���ĵ�ַ������"<<endl;
	cout<<"��̬�����޳�ֵs_k:"<<&s_k<<endl;
	cout<<"��̬�����޳�ֵs_h:"<<&s_h<<endl;
	cout<<"��̬������ʼ���ĺͷǳ�ʼ���Ĳ���һ��"<<endl;
	cout<<"const������ַ:"<<&s_f<<endl;
	cout<<"����ĵ�ַ����:"<<endl;
	cout<<"����sc[]��ֵΪ��"<<sc<<endl;//sc�������׵�ַ,�����������飿cout<<��ַ��ֱ�Ӿ��Ǳ���
	cout<<"����sc[]�ĵ�ַΪ��"<<&sc<<endl;//Ӧ������ջ��
	cout<<"����sc[]�е�һ����ַΪ:"<<&sc[0]<<endl;
	cout<<"����sc[]�ĵ�һ��Ԫ����"<<*sc<<endl;

	cout<<"ָ��pstr1:"<<&pstr1<<endl;
	cout<<"ָ��pstr2:"<<&pstr2<<endl;
	cout<<"ָ��pstr3:"<<&pstr3<<endl;

	
	return 0;
}

#endif
