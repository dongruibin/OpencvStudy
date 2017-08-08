//学习参考链接：http://blog.csdn.net/kevin_zhai/article/details/50494020
#include "include.h"
#include <iostream>

using namespace std;
//本文件之前有一版在ubuntu上创建的，结构体编译始终显示
//缺少一个"}"，实际上并没有缺少，具体原因现在还没有发现。
/*
链表中，每个节点包括存储数据元素的数据域，另一个是指向
下一个节点地址的指针域
*/
struct Info
{
	string name;//区分一下 char* name??
	int id;
};
struct Node//这个就是链表节点
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
	Node* head;//链表里面的头？
	int length;//整个链表的长度
};
//construct of 
LinkList::LinkList()
{
	cout<<"This is the construct of LinkList."<<endl;
	head=NULL;
	length=0;

}
//
LinkList::~LinkList()
{
	
}
//@param 
void LinkList::Insert(Info val,int pos)
{
	cout<<"LinkList Insert"<<endl;
	if(pos<0)
	{
		cout<<"pos must be greater than zero"<<endl;
		return;
	}
	int index=1;
	Node *temp=head;//指向节点的指针
	Node *node=new Node(val);//调用有参构造，构造节点，也就是将要
	//插入数据变成节点形式
	if(pos==0)
	{
		node->next=temp;//这里还不是赋值，是让指针指向头
		head=node;
		length++;
		return;
	}
	while(temp!=NULL&&index<pos)
	{
		temp=temp->next;
		index++;

	}
	if(temp==NULL)
	{
		cout<<"Insert failed"<<endl;
		return;
	}
	node->next=temp->next;
	temp->next=node;
	length++;
}
//链表打印
void LinkList::Print()
{

}
#ifdef USE_LinkList
/*
链表就是存数据和指向下一个节点的指针
*/
LinkList linkList;
Info bob;//,alice;
//struct Info many;
//Info many;

int main(int argc,char** argv)
{
	cout<<"This is a LinkList test demo"<<endl;
	cout<<"This is demo of struct init."<<endl;
	//结构体参考：http://blog.csdn.net/github_26672553/article/details/50382188
	//1、结构体初始化
	bob.name="bob";
	bob.id=79;
	//2、定义在初始化（前面已经定义[没有试成功]）
	struct Info alice={"alice",80};
	//3、使用指定数据赋值给指定属性
	//struct Info many={ .name="many"; .id=81};//注意这是c语言？c++也通用？
	//struct Info many={name:"many",id:81};
	//struct Info jine={name:"",id:82};

	//<<<<<<<<<<<<<<<<<<<<<<<<
	cout<<"sizeof the struct or Info:"<<sizeof(Info)<<endl;
	cout<<"sizeof the object of Info:"<<sizeof(alice)<<endl;


}
#endif