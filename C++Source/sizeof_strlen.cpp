#include "include.h"
#include <iostream>//�ļ���




#ifdef USE_sizeof_strlen
using namespace std;

int main(int argc,char** argv)
{
	char* str="dong";
	char stt[]="dong";//����д�����ַ�����ʹ�ò�������������---2017-12-24


-	cout<<"Use sizeof measure the char*:"<<sizeof(str)<<endl;
	cout<<"Use strlen measure the char*:"<<strlen(str)<<endl;
	

	return 0;
}

#else

std::cout<<"This log come from siezof_strlen.cpp\n"<<std::endl;

#endif




