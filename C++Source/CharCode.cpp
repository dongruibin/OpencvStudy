#include<iostream>
#include<assert.h>
#include<include.h>

//#define CHARUSE 1

//��ϰʹ��char�����
//�ַ�����
//������ǵ�ַ��������Ҳ�ǵ�ַ
//˵������������ͬһ���ȼ�����Ϸ�������������
//���磺*p++ ����*(p++),�Ƚ���*p���㣬��������ٽ���++����
char* myStrcat(char *strDes,const char *strSrc)//mu
{
		char* address=strDes;
	assert((strDes!=NULL)&&(strSrc!=NULL));//����һ�´�������Ƿ�Ϊ��

	while(*strDes!='\0')//�ش�ʧ��ȷ�Ϻ���'\0'����'/0'(ǰ��)
		strDes++;
	while((*strDes++= *strSrc++)!='\0')
		NULL;
	return address;
}
//�ַ������ȼ���
int myStrlen(const char* str)
{
	assert(str!=NULL);
	int len=0;
	while(*str++!='\0')
		len++;//ȷ����++len����len++
	return len;
}
//�ַ�����
char* myStrcpy(char* strDes,const char* strSrc)
{
	assert((strDes!=NULL)&&(strSrc!=NULL));
	char* address=strDes;
	while(*strSrc++)
		*strDes++=*strSrc++;
	return address;
}
//////ASCII��HEX���໥ת��
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
//char *des="cat";//����ʹ������ǻᱨ��ģ��ַ����ڴ���䲻��
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


