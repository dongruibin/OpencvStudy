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
	static int k2;//��֤��̬��Ա��˽���빫���Ƿ�������
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
		//a1=a1*obj.a1;//�޷�ʹ�ã���ʾ�ԷǾ�̬��Ա
		//cout<<"private data a1*a1 is:"<<a1<<endl;
		cout<<"This friend function:"<<f<<endl;
	}
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
	cout<<"Base �ྲ̬˽�г�Աk2��"<<k2<<endl;
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
//private construct
//��ע˵����
//�����캯��Ϊprivateʱ���������ڳ���������һ������ʱ��
//	������Ϊ���ù��캯��������еĻ�������������ý�ͨ����
//�ⲿ�ģ�Ҳ����˵��������class������ĵ��ã����繹��
//������˽�еģ�������class�ⲿ���������˽�г�Ա�������⽫����
//�������Ȼ��������class����������������static���г�Ա����Ϊ
//���Ƕ�����class����֮�⣬���ز�������Ҳ����ʹ�����ǡ�
/*
	�����Ϊ���캯����class˽�л�����������Ҫ���������󣬾ͱ����ܹ����ʵ�
	class��˽������һ��ֻ��class�ĳ�Ա�����������������Ǵ����������֮ǰ
	��ô���������ĳ�Ա��
	static���г�Ա�����Ƕ�����class��������ڵģ������ǡ����Է��ʵõ�������
	��ĳ��static�����д����˸�class�Ķ��󣬲������û���ָ�����ʽ���䷵�أ�
	���ﲻ�Զ��󷵻أ���Ҫ�ǹ��캯����˽�еģ��ⲿ���ܴ�����ʱ���󣩣���
	�����������ʹ��Ȩ��
	http://blog.csdn.net/koudaidai/article/details/7546661

*/
class PrivateClass
{
private://˽�й���
	PrivateClass(){
		cout<<"This is a private construct"<<endl;
	}
public:
	void printt(){
		cout<<"This is only a test!"<<endl;
	}
};
//��Ӷ�̳е�ѧϰ
class Base1
{
private:
	//a=5;//����û�и���������⣬
	//����ı�����Ϣ�ǣ�ֻ�о�̬����
	//�������ݳ�Ա�ſ��������г�ʼ��
	//int a=5;//һ����ʾ����
public:
	//int a=5;//��������ʾ��һ����
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
//��̳�ʹ��
class BaseMulti:public Base1,public Base2
{
public:
	BaseMulti(){}
	
};

//��̬��Ա�����ͳ�Ա�ܽ᣺
/*
	1����̬��Ա�������ܵ��÷Ǿ�̬��Ա
	2���Ǿ�̬��Ա�����п��Ե��þ�̬��Ա����Ϊ��̬��Ա�����౾��
		����Ķ������֮ǰ���Ѿ������ˣ������ڷǾ�̬��Ա��������
		���þ�̬��Ա
	3����̬��Ա����ʹ��ǰ�����ʼ����int myClass::m_nNumber=0;��,
		�������linkerʱ����
	�ο���http://blog.csdn.net/morewindows/article/details/6721430/
*/

int  Base::a=5;//a�Ǿ�̬������Ҫ����������ж��壬���췽���ǲ����Ե�
//���ɣ�
string arr[]={"dong1","dong2","dong3","dong4","dong5","dong6"};
string ar="I am a test string";
vector<string> vecstring(arr,arr+3);
vector<int> vec(10),veca(10),vecb(10),vecd(12);
vector< vector<int> >  vecc(3);//һ��vector������3��vector<int>
vector< vector<int> > martix(2,vector<int>(3));//2�У�3��
//private construct
//PrivateClass privateClass;//���캯��������ʹ��
//��ʼ��Base������ľ�̬��Ա
int Base::f=3;

//��֤���Ǿ�̬����ǰ���£����к�˽���Ƿ�������
int Base::k1=3;//���Ǿ�̬����
int Base::k2=33;//���Ǿ�̬˽��
//Base k;//Ϊʲô������Ӧ�ýж��壩����Ҳ����ù��캯��
Base *k;//�����ǲ����ù��캯�����ǣ���32λ����
	//һ��ָ��ռ4���ֽ�
////main founction

#ifdef USE_3P
//����˽�й���
//PrivateClass privateClass;//����ᱨ�����ù���Ҳ���ⲿ�ģ�˽���������޷����ʡ�
BaseMulti baseMulti;//�������ü̳еĸ���Ĺ��췽��
Base base,base1;//����������Ӧ�ýж��壩һ��Base����Ϊʲô����ù��췽��
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
	cout<<"vecd size:"<<vecd.size()<<endl;//��һ�γ�ʼ���͸���12����
	for(vector<int>::iterator vecdbegin=vecd.begin(),vecdend=vecd.end();vecdbegin!=vecdend;vecdbegin++)
	{
		cout<<"vecd data is"<<*vecdbegin<<endl;
	}
	for(vector<int>::iterator vecbegain=vec.begin(),vecend=vec.end();vecbegain!=vecend;vecbegain++)
	{//iterator �ǲ��Ǿ���ָ��Ԫ�ص�ָ�룿
		cout<<"This is the data:"<<*vecbegain<<endl;
		cout<<"This data address is:"<<&vecbegain<<endl;
	}
	cout<<"test string"<<ar<<endl;//Ҫ��ӡstring��Ҫ����ͷ�ļ�#include<string>
	//vector of string
	for(vector<string>::iterator vbegin=vecstring.begin(),vend=vecstring.end();vbegin!=vend;vbegin++)
	{
		cout<<"This is the string:"<<*vbegin<<endl;
	}
	cout<<"<<<<<<<<<<<<Use vecc<<<<<<<<<"<<endl;
	vecc.push_back(veca);//��һ����ά��vector,���ǵ��ĸ�����
	//cout<<"vecc�����"<<vecc[3].v
	cout<<"��άvector ��vecc is :"<<vecc[3][0]<<endl;
	//cout<<"��άvector����һ��Ԫ��"<<(*vecc[3])[0]<<endl;
	//��ȷ��ָ�� ��ͨ����ʹ��
	cout<<"ʹ�����Ƶ�����ʽ��"<<endl;
	//cout<<"vector ���ʣ�"<<vecc[3]->v<<endl;
	cout<<"This chapter the vector is not clearly"<<endl;
	cout<<"ERROR! ERROR!"<<endl;

	////////////////////
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"<<<<<<<<<<<<<<Friend function test<<<<<<<<<<<"<<endl;
	addSum(base);
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	///////////
	cout<<"��֤���Ǿ�̬����ǰ���£����к�˽���Ƿ�������"<<endl;
	cout<<"��̬���б���k1��"<<base.k1<<endl;//��̬ʹ���������Ͷ����һ��
	cout<<"��̬���б���k1����������"<<Base::k1<<endl;
	//cout<<"��̬˽�б���k2��"<<base.k2<<endl;//�������޷����ʵ�
	//cout<<"��̬˽�б���k2����������"<<Base::k2<<endl;
	base.PrintInfo();
	base1.PrintInfo();

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
