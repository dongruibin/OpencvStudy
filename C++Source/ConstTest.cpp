#include <iostream>
#include "include.h"

using namespace std;
///////测试要点
	//const对象只能调用一些常量对象。
	//const对象的值不能被修改，在const成员函数中修改const对象数据成员的值
	//	是语法错误
//定义一个类
class Text
{
public:
	void printconst(void) const
	{
		cout<<"hello"<<endl;
	}
	void print(void)
	{
		cout<<"hello"<<endl;
	}
private:
	int k;
};
#ifdef USE_CONST

const Text a;//const类型的对象
int main(int argc,char** argv)
{

	a.printconst();
	//a.print();//It is an error!
	return 0;
}
#endif

