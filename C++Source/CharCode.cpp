#include<iostream>
#include<assert.h>
#include<include.h>

#define CHARUSE 1

//��ϰʹ��char�����
//�ַ�����
char* myStrcat(char *strDes,const char *strSrc)//mu
{
	assert((strDes!=NULL)&&(strSrc!=NULL));//����һ�´�������Ƿ�Ϊ��
	char* address=strDes;
	while(*strDes!='/0')
		++strDes;
	while((*strDes++=*strSrc++)!='/0')
		NULL;
	return address;
}
#ifdef CHARUSE
char *test;
char *des="cat";
char *src="dog";
int main(int argc,char** argv)
{
	std::cout<<"This is a Demo of CharCode!"<<std::endl;

	//test=myStrcat("cat","dog");
	test=myStrcat(des,src);
	std::cout<<"Point address of test is: "<<test<<"The code of it is:"<<*test<<std::endl;
	return 0;
}
#endif


