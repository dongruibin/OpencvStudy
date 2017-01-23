#include "include.h"
#include<iostream>

//���ļ���Ҫ��ѧϰ�˽����ص�ʹ��
using namespace std;
//c++������ͬһ���������е�ĳ�������������ָ��������壬�ֱ��Ϊ
//�������غ���������ء�����������ָһ����֮ǰ�ڸ�����������������
//�����򷽷�������ͬ���Ƶ��������������ǵĲ����б�Ͷ��壨ʵ�֣���
//��ͬ����������һ�����غ��������������ʱ��������ͨ��������ʹ�õ�
//�������ͽ��бȽϣ�����ѡ������ʵĶ��壬�����ؾ��ߡ�

//���������
//���ص�������Ǵ����������Ƶĺ��������������ɹؼ���operator
//�����Ҫ���ص���������Ź��ɡ�����������һ���������������
//һ���������ͺ�һ�������б�
#define opeatorTest 1
//�����������ж��Ƿ�ʹ��thisָ��
#define ThisUse 0

class Box{
public:
	//���캯��
	Box()
	{
		cout<<"This is Box"<<endl;
	}
	//����һ���вι��캯��
	Box(double len,double bre,double hei)
	{
		length=len;
		breadth=bre;
		height=hei;
	}
	double getVolume(void)
	{
		return length*breadth*height;
	}
	void setLength(double len)
	{
		length=len;
	}
	void setBreadth(double bre)
	{
		breadth=bre;
	}
	void setHeight(double hei)
	{
		height=hei;
	}
	double getLength()
	{
		return length;
	}
	double getBreadth()
	{
		return breadth;
	}
	double getHeight()
	{
		return height;
	}
	//дһ����Ա����
	void doSomething()
	{

		cout<<"This is a method of Box"<<endl;
	}
	//дһ����̬����
	static void doFunction()
	{
		cout<<"This is a static method of Box"<<endl;

	}
//���ط���
#ifdef ThisUse
	
	//ʹ��thisָ���������
	Box& operator+(const Box& b)
	{
		this->length=this->length+b.length;
		this->breadth=this->breadth+b.breadth;
		this->height=this->height+b.height;
		return *this;
	}
#else
	//������Ӧ���������㣬���ڰ�����Box�������
	Box operator+(const Box& b)
	{
		//C++ thisָ��ĵ���
		Box box;
		box.length=this->length+b.length;
		box.breadth=this->breadth+b.breadth;
		box.height=this->height+b.height;
		return box;
	}
#endif

private:
	double length;
	double breadth;
	double height;
};//��������д�ϡ�;���ᵼ��һ������⣬һ��Ҫ��ס����ֺţ�����������ڽṹ��
///////�½���һ����̳�ԭ������---ȷ�Ϸ�����д
class newBox:Box
{
public:
	newBox()
	{
		cout<<"This is newBox"<<endl;
	}
	void doSomething()
	{
		//˵����ע������
		cout<<"����ʹ��Box::doSomething()�����ø���ķ���\
			��������ʽ�ǲ��еġ���ͬ��java��super()\
			,C++֧�ֶ�̳У�ֱ������д�޷���ȡ������һ������"<<endl;
		Box::doSomething();//��������ķ���
		cout<<"This is a method of newBox"<<endl;
	}
};

#ifdef USE_OPERATOR

int main(int argc,char** argv)
{
#ifdef opeatorTest
	//��һ������
	Box  box1;
	box1.setLength(15);
	box1.setBreadth(15);
	box1.setHeight(15);

	//�ڶ�������
	Box box2(16,16,16);
	Box box3;
	box3=box1.operator+(box2);
	cout<<"box3��Length:"<<box3.getLength()<<endl;

	//����ʹ��һ�¾�̬����
	box3.doFunction();//It is ok
	Box::doFunction();//It is also ok!
	//��̬��������˵��
	//������.��̬����() ����::��̬����()------���ǿ���
	//����.��̬����()---------������
	
	//�½���һ���µ�newBox
	newBox newbox;
	newbox.doSomething();//�̳��ڸ���ķ���



#endif
	return 0;
}


#else


#endif