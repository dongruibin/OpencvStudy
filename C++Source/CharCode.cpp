#include<iostream>
#include<assert.h>
#include<include.h>

#define CHARUSE 1

//练习使用char数组等
//字符拷贝
char* myStrcat(char *strDes,const char *strSrc)//mu
{
	assert((strDes!=NULL)&&(strSrc!=NULL));//断言一下传入参数是否为空
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


