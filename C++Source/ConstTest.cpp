#include <iostream>
#include "include.h"

using namespace std;
///////����Ҫ��
	//const����ֻ�ܵ���һЩ��������
	//const�����ֵ���ܱ��޸ģ���const��Ա�������޸�const�������ݳ�Ա��ֵ
	//	���﷨����
//����һ����
class Text
{
public:
	void printconst(void) const
	{
		cout<<"hello"<<endl;
	}
	void print(void)
	{
		cout<<"hello"<<endl;
	}
private:
	int k;
};
#ifdef USE_CONST

const Text a;//const���͵Ķ���
int main(int argc,char** argv)
{

	a.printconst();
	//a.print();//It is an error!
	return 0;
}
#endif

