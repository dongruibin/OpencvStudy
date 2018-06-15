#ifndef INCLUDE_H_
#define INCLUDE_H_

//使用Ctrl+k,Ctrl+c进行大段的屏蔽工作
//使用ctrl+k,ctrl+k进行代码的去除屏蔽工作

//使用小技巧
//#pragma comment(lib,"ws2_32.lib")//使用代码的形式进行链接lib文件 

/////定义调试一些C++代码
//#define CodeArrayPointerAndPointerArray 1
//#define ClassTest 1//学习类的使用，指针对象
//#define TemplateDef 1//学习模板类的使用方式
//#define FunPointer 1


//定义使用调用哪个文件进行测试
//#define USE_TEST 1
//#define USE_VECTOR 1
//#define USE_DISPLAYIMAGE 1
//#define USE_ROI 1
//#define USE_WAYTOACCESSPIXEL 1
//#define USE_SURF_TEST 1

//#define USE_MATRIXTEST 1
//#define USE_FACE_DECT 1
//#define USE_HARRIS 1

//#define USE_SURFTEST 1

//#define USE_BASEDATA 1
//#define USE_CONST 1
//#define USE_OPERATOR 1

//图像处理
//#define LOCATION 1
//#define ANSWER 1

//#define ObjectDectUse 0


//#define USE_SEX_DECT 1
//#define USE_LinkList 1

//测试私有继承，公有继承，保护继承
#define USE_3P 1

//siezeof strlen区别
//#define USE_sizeof_strlen 1

//opencv实例使用车牌识别系统
//#define USE_car 1
//#define USE_ann 1//用来学习机器学习

//测试C++内存分布在哪里
//#define CODESTORE 1

//测试霍夫变换
//#define HoughDemo 1

//测试3d calibration
//#define Calibration 1

//mark object
//#define USE_markObject 1

//circinal	Queue
//#define USE_CirQueue 1


///////////程序释疑说明////
/*
一、命名空间问题
		所谓C++中的namespace，是指标识符的各种可见范围。C++标准程序库中的所有标识符都被定义于一个
	名为std的namespace中。
		<iostream>和<iostream.h>是不一样，前者无后缀，后缀为.h的头文件c++标准已经明确提出不支持了。
	早些的实现将标准库功能定义在全局空间里，声明在带.h后缀的头文件里。为了正确使用命名空间，规定
	头文件不使用后缀.h。
二、外部调用c函数
		C++程序有时需要调用其他语言编写的函数，最常见的就是调用C语言编写的函数。像所有其他名字一样
	其他语言中的函数名字也必须在C++中进行声明。
		这个就需要用到链接指示（linkage directive）指出任意非C++函数所用的语言。
	格式：
	extern "C" {}



*/


//////////快捷键说明////
/*
	1、快速设置断点 F9
	2、快速编译进入调试 F5
	3、逐语句F11 逐过程 F10 跳出shift+F11
*/

#endif

