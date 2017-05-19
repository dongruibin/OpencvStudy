#include<iostream>
#include<assert.h>
#include<include.h>

//#define CHARUSE 1

//练习使用char数组等
//字符拷贝
//传入的是地址，传出的也是地址
//说明：两个处于同一优先级，结合方向是自右向左
//例如：*p++ 就是*(p++),先进行*p运算，运行完后再进行++运算
char* myStrcat(char *strDes,const char *strSrc)//mu
{
		char* address=strDes;
	assert((strDes!=NULL)&&(strSrc!=NULL));//断言一下传入参数是否为空

	while(*strDes!='\0')//重大失误，确认好是'\0'还是'/0'(前者)
		strDes++;
	while((*strDes++= *strSrc++)!='\0')
		NULL;
	return address;
}
//字符串长度计算
int myStrlen(const char* str)
{
	assert(str!=NULL);
	int len=0;
	while(*str++!='\0')
		len++;//确认是++len还是len++
	return len;
}
//字符拷贝
char* myStrcpy(char* strDes,const char* strSrc)
{
	assert((strDes!=NULL)&&(strSrc!=NULL));
	char* address=strDes;
	while(*strSrc++)
		*strDes++=*strSrc++;
	return address;
}
//////ASCII和HEX的相互转换
unsigned char CharToHex(unsigned char bHex)
{
	if((bHex>=0)&&(bHex<=9))
	{
		bHex+=0x30;
	}
	else if((bHex>=10)&&(bHex<=15))//Capital
	{
		bHex+=0x37;
	}
	else
	{
		bHex=0xff;
	}
	return bHex;
}
unsigned char HexToChar(unsigned char bChar)
{
	if((bChar>=0x30)&&(bChar<=0x39))
	{
		bChar-=0x30;
	}
	 else if((bChar>=0x41)&&(bChar<=0x46)) // Capital  
    {  
        bChar -= 0x37;  
    }  
    else if((bChar>=0x61)&&(bChar<=0x66)) //littlecase  
    {  
        bChar -= 0x57;  
    }  
    else   
    {  
        bChar = 0xff;  
    }  
    return bChar;  
}
#ifdef CHARUSE
char *test;
int len;
//char *des="cat";//这里使用这个是会报错的，字符串内存分配不足
char des[20]="cat";
char *src="dog";
int main(int argc,char** argv)
{
	std::cout<<"This is a Demo of CharCode!"<<std::endl;

	//test=myStrcat("cat","dog");
	test=myStrcat(des,src);
	len=myStrlen(src);
	std::cout<<"Point address of test is: "<<test<<"The code of it is:"<<*test<<std::endl;
	std::cout<<"This str length is:"<<len<<std::endl;
	return 0;
}
#endif


