#include "include.h"
#include <iostream>
#include <vector>
#include<string>//û�����cout�޷���ӡ��string����
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
	static int a;//��̬ ˽�б�����
protected:
	int a2;
public:
	int a3;
};//always forget

Base::Base():a2(5),a1(5),a3(5)//,a(5)---��̬�������޷�ͨ�����캯����ʼ��---������ʲô��
	//---��̬����ʱȫ�ֵģ����ÿ���ʹ��������Ҳ����ʹ�������
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
	//ע������һ����̬������������Բ�����̬��Ա�����ǲ�����
	//������ͨ��Ա:
	//��̬��Ա�������������࣬��ʵ��������֮ǰ���Ѿ�����ռ��ˣ�
	//����ķǾ�̬��Ա��������ʵ�������������ڴ�ռ䡣
	

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
		//cout<<"a1 is :"<<a1<<endl;//���󣬲��ܷ���
		cout<<"a2 is :"<<a2<<endl;//���ౣ����Ա�������BasePrivate�����˽�б�����
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
int  Base::a=5;//a�Ǿ�̬������Ҫ����������ж��壬���췽���ǲ����Ե�
//���ɣ�
string arr[]={"dong1","dong2","dong3","dong4","dong5","dong6"};
string ar="I am a test string";
vector<string> vecstring(arr,arr+3);
vector<int> vec(10),veca(10),vecb(10),vecd(12);
vector<vector<int>>  vecc(3);//һ��vector������3��vector<int>
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
	{//iterator �ǲ��Ǿ���ָ��Ԫ�ص�ָ�룿
		cout<<"This is the data:"<<*vecbegain<<endl;
	}
	cout<<"test string"<<ar<<endl;//Ҫ��ӡstring��Ҫ����ͷ�ļ�#include<string>
	//vector of string
	for(vector<string>::iterator vbegin=vecstring.begin(),vend=vecstring.end();vbegin!=vend;vbegin++)
	{
		cout<<"This is the string:"<<*vbegin<<endl;
	}

	////////////////////
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	BasePrivate basePrivate;//�����̳ж���ԭ���ĸ�������췽��һ�������
	BasePublic basePublic;

	basePrivate.PrintInfo();
	//cout<<"basePrivate�����a2Ϊ:"<<basePrivate.a2<<endl;//���ܷ��ʣ�˽�м̳�
	Base base;
	//���Ի���private�ĵ���
	//cout<<"Base class private a1:"<<base.a1<<endl;//���������޷�����
	//���Ի�������ľ�̬˽�б���
	//cout<<"Base class static private a:"<<Base::a<<endl;

	//cout<<"Base private a1:"<<basePrivate.a1<<endl;//�����޷������������˽�б���(˽�м̳�)
	cout<<"BasePublic a3:"<<basePublic.a3<<endl;//���м̳У�������������

	return 0;
}

#endif
