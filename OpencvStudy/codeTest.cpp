#include <iostream>
#include"codeTest.h"
#include "include.h"

//���ļ����ڲ���ѧϰC++���ԣ�����ʹ�÷���
///VS������Ӧ�ĵ���
//1.ѡ��һ�д��룬����F9�Ϳ��Կ��ٵ��趨һ���ϵ�
//F11Ϊ�������ԣ�����������ú�������е��ú����ڲ������ִ��
//F10Ϊ����̵��ԣ���������ú����ڲ�
//shift+F11Ϊ�������ԣ���ִ�е�ǰִ�е����ں�����ʣ��������


//���õ�ʹ��
void swapint(int &a,int& b)//ע��һ��д��---cʹ��ָ����ʽ���βΣ�--����������ʹ��
{//����--�൱�ڱ���������һ������
	int temp;
	temp = a;
	a = b;
	b = temp;

}
void Dong::MyClass::Myfun()
{
	std::cout << "�·�����ʹ��" << std::endl;
}


#ifdef USE_TEST
int main()
{
	Dong::MyClass t = Dong::MyClass();//��������
	Dong::MyClass *p=NULL;//������һ�����ﲻ���г�ʼ��������ʾ����
	//p = NULL;//����������Ҳ��������ʹ�����ַ�ʽ����ָ��ĳ�ʼ������
	t.MyFunction();
	t.Myfun();
	p->Myfun();
	(*p).Myfun();
	Dong::funNon();
	return 0;
}
#else 
#endif