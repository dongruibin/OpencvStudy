#include "include.h"
#include <iostream>

using namespace std;
//1、4字节对齐
//2、c++变量地址
/*
	在程序中，数据结构还有变量等都需要占内存，在很多系统中，它都要求内存分配的
时候要对齐，这样做的好处就是可以提高访问内存的速度。
代码参考：http://www.cppblog.com/cc/archive/2006/08/01/10765.html
*/
/*
堆栈内存管理
	1、管理方式不同
		栈是有编译器自动管理，堆是手动，容易memory leak
	2、空间大小
		一般来讲，32为系统，堆内存可以达到4G空间，栈一般较小，一般有1M
	3、碎片问题
		对于堆，new、delete频繁会造成内存空间不连续，从而会有碎片
		对于栈，是先进后出的队列
	4、生长方向
		堆是向上生长的，也就是内存地址增加的方向
		栈是向下的，是向着内存地址减小的方向增长
	5、分配方向
		堆是动态分配的，没有静态分配的堆，栈有2种分配方式：
		静态分配和动态分配，静态分配是编译器完成的，比如局部
		变量的分配，动态分配是由alloca函数进行分配，但是栈的动态
		分配私有编译器进行释放。
参考：http://blog.csdn.net/a185446828/article/details/50899887
结论：
*/


//全局初始化变量
int g_i=100;
int g_j=200;
int g_k,g_h;

struct X1
{
	int i;//4字节
	char c1;//1字节
	char c2;//1字节
};
struct X2
{
	char c1;//1字节
	int i;//4字节
	char c2;//1字节
};
struct X3
{
	char c1;//1字节
	char c2;//2字节
	int i;//4字节
};
#ifdef CODESTORE
char* p;//4个字节
char* p_init_null=NULL;
char * p_init="dong";

/*
变量定义：用于为变量分配存储空间，还可以为变量指定初识值，在程序
	中变量有且只有一个定义
变量声明：用于向程序表明变量的类型和名字。
	内存是一个连续的块，它是以4字节为一个对齐单位，
	x1中第一是int型，占有4个字节，然后第二个是char类型，这种类型只
	占有一个字节，所以占有第二个4字节组中的第一格，第三也是char类型
	所以它也占一个字节，它就排在第二个组块的第二格。
*/
int main(int argc,char** argv)
{
	cout<<"float:"<<sizeof(float)<<endl;//sizeof是关键字
	cout<<"long:"<<sizeof(long)<<endl;
	cout<<"int:"<<sizeof(int)<<endl;
	cout<<"pointer:"<<sizeof(p)<<endl;//pointer is 4 byte

	X1 x1;
	X2 x2;
	X3 x3;
	cout<<"x1的大小："<<sizeof(x1)<<endl;
	cout<<"x2的大小："<<sizeof(x2)<<endl;
	cout<<"x3的大小："<<sizeof(x3)<<endl;

	cout<<"<<<<<<<<<<<内存地址实际值<<<<<<<<<<<<:"<<endl;
	const int MAX=100;
	int *HeapAddress=(int*)malloc(MAX*sizeof(int));
	int *HeapAddress1=(int*)malloc(MAX*sizeof(int));
	static int s_i=5;
	static int s_j=10;
	static int s_k;
	static int s_h;
	const int s_f=10;
	int i=5;
	int j=10;
	int k=20;
	int f,h;
	char sc[]="dongdong1";
	char *pstr1="dongdong2";
	char *pstr2="dongdong2";
	char *pstr3="dong";
	
	cout<<"堆中数据地址:"<<HeapAddress<<endl;//HeapAddress是一个指针，是指向堆中数据地址
	cout<<"堆中数据地址1："<<HeapAddress1<<endl;//HeapAddress是第二个指针，指向堆中数据的地址
	cout<<"上面可以看出堆中地址是向上生长的"<<endl;
	cout<<"堆中数据地址存放地址（该值在栈中）&k: "<<&HeapAddress<<endl;//这个指针（地址值）存放地址--这个地址在栈上
	cout<<"堆中数据地址存放地址（该值在栈中）& : "<<&HeapAddress1<<endl;

	//cout<<"访问固定地址的值:"<<*((int *)(0x0044f298))<<endl;//地址值？
	//cout<<"栈上地址p:"<<p<<endl;//这个提示错误：尝试读取或写入受保护的内存
	//cout<<"栈上地址p_init_null:"<<p_init_null<<endl;//提示错误，与上面一样的

	cout<<"栈中有初值地址i："<<&i<<endl;
	cout<<"栈中有初值地址j："<<&j<<endl;
	cout<<"栈中有初值地址k："<<&k<<endl;
	cout<<"上面栈地址是向减小方向进行。。。。为什么是0x0c?"<<endl;
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"静态变量有初值s_i:"<<&s_i<<endl;
	cout<<"静态变量有初值s_j:"<<&s_j<<endl;
	cout<<"静态变量初始化的地址是向下"<<endl;
	cout<<"静态变量无初值s_k:"<<&s_k<<endl;
	cout<<"静态变量无初值s_h:"<<&s_h<<endl;
	cout<<"静态变量初始化的和非初始化的不在一起"<<endl;
	cout<<"const变量地址:"<<&s_f<<endl;
	cout<<"数组的地址测试:"<<endl;
	cout<<"数组sc[]的值为："<<sc<<endl;//sc是数组首地址,代表整个数组？cout<<地址，直接就是变量
	cout<<"数组sc[]的地址为："<<&sc<<endl;//应该是在栈中
	cout<<"数组sc[]中第一个地址为:"<<&sc[0]<<endl;
	cout<<"数组sc[]的第一个元素是"<<*sc<<endl;

	cout<<"指针pstr1:"<<&pstr1<<endl;
	cout<<"指针pstr2:"<<&pstr2<<endl;
	cout<<"指针pstr3:"<<&pstr3<<endl;

	
	return 0;
}

#endif
