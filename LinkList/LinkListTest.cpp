#include "include.h"
#include <iostream>

using namespace std;
//本文件之前有一版在ubuntu上创建的，结构体编译始终显示
//缺少一个"}"，实际上并没有缺少，具体原因现在还没有发现。
struct Info
{
	string name;
	int id;
};
struct Node
{
	Info val;//信息部分
	Node* next;//地址部分
	Node(Info x):val(x),next(NULL){}//just construct
};
class LinkList
{
public:
	LinkList();//构造函数
	void InsertHead(Info val);
	void Insert(Info val,int pos);
	void Remove(Info val);
	int Length();//链表长度
	void Reverse();//链表反序
	int Find(Info val);
	void Print();//打印链表
	~LinkList();
private:
	Node* head;//指向节点的指针
	int length;//整个链表的长度
};
//@param 
void LinkList::Insert(Info val,int pos)
{
	cout<<"LinkList Insert"<<endl;
}

#ifdef USE_LinkList
int main(int argc,char** argv)
{
	cout<<"This is a LinkList test demo"<<endl;
}
#endif