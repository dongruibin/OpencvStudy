#ifndef __CODETEST_H_
#define __CODETEST_H_


namespace Dong{
	class MyClass
	{
	public:
		MyClass();
		~MyClass();
		void MyFunction(void);
		void Myfun(void);//ֻ��������û��ʵ��
		//������Ϊ���õĺ�������
		

	private:

	};

	MyClass::MyClass()
	{
		std::cout << "����ʹ��"<<std::endl;
	}

	MyClass::~MyClass()
	{
	}
	void MyClass::MyFunction()
	{
		std::cout << "����MyClass����ķ���" << std::endl;
	}

	//�½����Ĳ������κ���ķ���
	void funNon()
	{
		std::cout << "this method is not belong anyone!" << std::endl;
	}

}


#endif

