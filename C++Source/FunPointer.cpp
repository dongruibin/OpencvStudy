#include<iostream>
#include "include.h"


//���ļ���Ҫ�����������������ָ���ָ�뺯���ĸ���

//1��ָ�뺯��
//	ָ�뺯����ָ��ָ��ĺ�������������һ���������������з������ͣ����û�з���ֵ����Ϊ��ֵ�ͣ�
//ָ�뺯������������ĳһ���͵�ָ�루���ص��ǵ�ַ��
//�������ͱ�ʶ�� *�������ƣ��βΣ�{������}
//	�������Ϳ������κλ������ͺ͸������͡�������������һ����ڵ�ַ��

//2������ָ��
//	����ָ����ָ������ָ����������"����ָ��"��������Ӧ����ָ�������ֻ������ָ�����ָ������
//ÿ����������һ����ڵ�ַ������ڵ�ַ���Ǻ���ָ����ָ��ĵ�ַ������ָ������ָ������󣬿��ø�
//����ָ����ú���������ָ����������;�����ú������������Ĳ�����

using namespace std;
//#define FPPF 0 

#ifdef FunPointer

int main(int argc,char** argv)
{
#ifdef FPPF
	//ʹ��һ��ָ�뺯��
	float *find(float (*pionter)[4],int n);//����ָ�뺯��
	static float score[][4]={{60,70,80,90},{56,89,34,45},{34,23,56,45}};
	float *p;
	int i,m;
	printf("Enter the number to be found:");
	scanf("%d",&m);
	printf("the score of NO,%d are:\n",m);
	p=find(score,m);//��������һ����ַ���ŵ�p����
	for(i=0;i<4;i++)
		printf("%5.2f\t",*(p+i));


#else
	int (*ptr)(int,int);//дһ�²�������
	int max(int x,int y);
	int a,b,c;
	ptr=max;//��������ַ����ptr
	cin>>a>>b;
	c=(*ptr)(a,b);
	cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
	//ptr��ָ������ָ����������ԿɰѺ���max()����ptr��Ϊptr��ֵ��
	//����max()����ڵ�ַ����ptr��

#endif
	return 0;
}




#else
#endif

float *find(float(*pionter)[4],int n)//����һ��ָ�뺯��
{
	float *pt;
	pt=*(pionter+n);
	return(pt);
}

int max(int x,int y)
{
	return (x>y?x:y);
}