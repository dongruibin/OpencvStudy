#include "include.h"//�����Ҫ�����Ӧ��·����vs����������


//ָ������ ��array of pointers,�����ڴ洢ָ������飬Ҳ��������Ԫ�ض���ָ��
//����ָ�� ��a pointer to an array,��ָ�������ָ��

//int* a[4] ָ������  ����a�е�Ԫ�ض���int��ָ��
//				*a[i] ��*(a[i])��һ����

//int (*a)[4] ����ָ��  ָ������a��ָ��
//					

#include<iostream>

using namespace std;

//#ifdef CodeArrayPointerAndPointerArray
#if 0

int main(int argc, char** argv)
{
	int c[4] = { 1, 2, 3, 4 };
	int *a[4];//ָ������
	int(*b)[4];//����ָ��
	b = &c;
	//������c��Ԫ�ظ�������a
	for (int i = 0; i < 4; i++)
	{
		a[i] = &c[i];
		//�������:
		//a[i]Ҳ��һ��ָ�룬�ŵ��ǵ�ַ�������ǰ�&c[i]�����ַ���룬ʵ���ϵ�����ʱ*a[i]
	}
	//���������£�
	cout << *a[1] << endl;//���Ӧ����2
	cout << (*b)[1] << endl;//���Ӧ����2
	return 0;
}
#else
#endif
