#ifndef __CODETEST_H_
#define __CODETEST_H_


namespace Dong{
	class MyClass
	{
	public:
		MyClass();
		~MyClass();
		void MyFunction(void);
		void Myfun(void);//只有声明，没有实现
		//其它较为有用的函数工具
		

	private:

	};

	MyClass::MyClass()
	{
		std::cout << "测试使用"<<std::endl;
	}

	MyClass::~MyClass()
	{
	}
	void MyClass::MyFunction()
	{
		std::cout << "测试MyClass里面的方法" << std::endl;
	}

	//新建立的不属于任何类的方法
	void funNon()
	{
		std::cout << "this method is not belong anyone!" << std::endl;
	}

}


#endif

