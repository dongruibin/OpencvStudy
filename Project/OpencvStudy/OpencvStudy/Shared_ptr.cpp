/*****************************************************
** 编写时间：  2018年9月7日
** 功能模块：  shared_ptr使用
** 功能相关：
**	科普：指针是天堂，也是地狱。
**			C++程序设计中使用堆内存是非常频繁的操作，堆的
		申请和释放都是程序员自己管理，程序员自己管理堆内存
		可以提供程序的效率，但是整体来说堆内存的管理是较麻烦。
		使用普通指针，容易造成堆内存泄露（忘记释放），二次释放
		程序发生异常是内存泄露等问题。
	理解智能指针可以从三个方面进行：
	1、从浅层看，智能指针是利用了一种叫RAII（资源获取即初始化）的
		技术对普通的指针进行封装，这使得智能指针实质也是一个对象
		行为表现却是一个指针。
	2、智能指针的作用是防止忘记调用delete释放内存和程序异常的进入catch
		块忘记释放内存，另外指针的释放时机也是非常有考究的，多次释放同一
		个指针会造成程序奔溃，这个都可以通过智能指针解决。
	3、智能指针还有一个作用把值语义转换成引用语义。C++ JAVA有一处最大
		区别就是在与语义不用。（详细看值语义）

**			shard_ptr是一个标准的共享所有权的智能指针，
	允许多个指针指向同一个对象，定义在memory文件，shard_ptr使用引用计数，每
	一个shared_ptr的拷贝都指向相同的内存，每使用一次，内部的引用计数+1，每
	析构一次，内部的引用计数-1，减到0时，自动删除所指向的堆内存。
		shard_ptr内部的引用计数是线程安全的，但是对象的读取需要加锁。
		1）初始化，智能指针是个模板类，可以指定类型，传入指针通过构造函数初始化，
			也可以使用make_shared函数初始化，不能将一个指针直接赋值给一个智能指针，
			一个是指针，一个是类。
		2）拷贝和赋值，每个shared_ptr拷贝都指向相同内存，拷贝使得对象的引用计数+1，....
		3）get函数获取原始指针

	注意事项：
		1）不用使用一个原始指针初始化多个shared_ptr，会造成二次销毁。
		2）不要在函数实参中传入shared_ptr，防止由于编译器不同造成计算顺序不同，先创建在使用
		3）禁止使用shared_from_this()返回this指针，这样可能造成二次析构
		4）避免循环引用，智能指针最大陷阱是循环引用！！
** 版权声明：  本程序只供学习使用，未经作者许可，不得用
** 			   于其他任何用途，版权所有，盗版必究。
程序参考：https://www.cnblogs.com/wxquare/p/4759020.html
******************************************************/
#include "include.h"
#include <iostream>
#include <memory>//shared_ptr使用

#ifdef SHARED_PTR
using namespace std;


int main(int argc,char** argv)
{
	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	shared_ptr<int> ptra2(ptra);//copy1
	shared_ptr<int> ptra3(ptra);//copy2
	cout<<"ptra use_count:"<<ptra.use_count()<<endl;

	int b = 20;
	int *pb = &a;
	shared_ptr<int> ptrb = make_shared<int>(b);
	ptra2 = ptrb;//assign
	pb=ptrb.get();//获取原始指针
	cout<<ptra.use_count()<<endl;
	cout<<ptrb.use_count()<<endl;
	return 0;
}


#endif