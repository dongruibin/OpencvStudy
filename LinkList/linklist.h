//linklist.h:定义链表结点和方法
//参考地址：http://blog.csdn.net/kevin_zhai/article/details/50494020
#include<string>
#include<include.h>
using namespace std;


struct Info
{
	string name;
	int id;
};
//define list
//这个就是结点 
struct Node
{
	Info val;//信息部分
	Node* next;//地址部分
	Node(Info x):val(x),next(NULL){}//直接带构造方法
};

class LinkList
{
public:
//构造函数
	LinkList();
	void InsertHead(Info val);//链表头部插入结点
	void Insert(Info val,int pos);
	void Remove(Info val);//删除结点
	int Length();//链表长度
	void Reverse();//链表反序
	int Find(Info val);//查找结点位置
	void Print();//打印链表
	~LinkList();
private:
	Node* head;//指向结点的指针
	int length;//整个链表的长度
};
