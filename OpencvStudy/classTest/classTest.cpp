/////���ļ���Ҫ����Ϥһ��c++��������˼��
#include<iostream>
#include"include.h"
#include<string.h>
using namespace std;
//C++�����Կ���������̵�Ӧ�ó���Ҳ���Կ�����������Ӧ�ó���
//////����һ������

class CPerson
{
	//���ݳ�Ա
	////ע���۵����ݳ�Ա������������ֱ�ӳ�ʼ��
	int m_iIndex;
	char m_cName[25];
	short m_shAge;
	double m_dSalary;
	//��Ա����
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
//���ʵ�ּ�������h�ļ��е������棬Ҳ������cpp����ʵ��
//��ʵ�ַ�ʽ��
short CPerson::getAge()
{
	return m_shAge;
}
int CPerson::setAge(short sAge)
{
	m_shAge = sAge;
	return 0;//ִ�гɹ�����0
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
//////һ���ϻ�������ŵ�h�ļ����棬����ʵ�ַŵ�cpp�ļ�����
#ifdef ClassTest
int main(int argc, char** argv)
{
	//�����ʹ��
	CPerson p;
	//�����ָ������ָ��
	CPerson *h=NULL;//����ָ�룬ָ��CPerson���͵Ķ��󡣣���һ��ָ�룬����Ҫָ�����
	h = &p;/////ָ�����---

	p.setName("dong");//Ҫ����������Ϊpublic������Ĭ�ϵ����޷�����
	cout << p.getName() << endl;
	h->setName("zhang");
	cout << h->getName() << endl;
	return 0;
}
#else
#endif