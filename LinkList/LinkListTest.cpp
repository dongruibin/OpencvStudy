//学习参考链接：http://blog.csdn.net/kevin_zhai/article/details/50494020
#include "include.h"
#include <iostream>
#include <string>//之前一直没有加入过该头文件，导致string之类的cout有问题

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
	Node* head;//链表里面的头？第一节点？
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
	//cout<<"LinkList Insert"<<endl;
	if(pos<0)//位置不存在
	{
		cout<<"pos must be greater than zero"<<endl;
		return;
	}
	int index=1;
	Node *temp=head;//指向节点的指针，先让temp指向第一个节点
	Node *node=new Node(val);//调用有参构造，构造节点，也就是将要
	//插入数据变成节点形式
	if(pos==0)
	{
		//这里没有搞明白。关键
		node->next=temp;//要插入的node节点的指针，指向下一个节点
		head=node;//将当前添加的node变成头节点
		length++;
		return;
	}
	while(temp!=NULL&&index<pos)//原来链表就有数据，先将temp指到头
	{
		temp=temp->next;
		index++;

	}
	if(temp==NULL)//链表头就是空的
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
	int i;
	Node * temp=head;//先来一个临时指针指向头
	//如何把节点一个一个打印出来
	if(length==0)
	{
		cout<<"This linkList is NULL."<<endl;
		return ;
	}
	for(i=0;i<length;i++)//这里是不是可以使用while(temp!=NULL)
	{
	//先从头开始打印
		cout<<(temp->val).name<<temp->val.id<<endl;//temp->val是一个结构体指针了？
	//将temp指向下一个吧
	temp=temp->next;//我是认为把next的地址赋值给temp
		//temp->next=temp;//这个意思是将temp的next又指向自己，死循环了
	}
}

//链表的长度
int  LinkList::Length()
{
	return length;
}
//链表的反转
void LinkList::Reverse()
{
	Node* temp=head;//先建立一个临时的节点，从头开始使用
	if(temp==NULL)
	{
		cout<<"The linkList is empty."<<endl;
		return ;
	}
#if 0
	//循环一下链表内容
	while(temp!=NULL)//只要链表不为空
	{
		cout<<temp->val.name<<temp->val.id<<endl;
		temp=temp->next;
	}
#endif
	//先到一下链表的尾部去--下面方法使temp变成了NULL
	//while(temp!=NULL)
	//	temp=temp->next;
	//现在temp已经指向最后的节点,temp已经变成空了
	//cout<<temp->val.name<<temp->val.id<<endl;
	//开始反转
	
	while(temp!=NULL)
	{
	head=temp->next;
	}

}


#ifdef USE_LinkList
/*
链表就是存数据和指向下一个节点的指针
*/
LinkList linkList;
Info bob;//,alice;
//struct Info many;
//Info many;
//结构体初始化
//test the cout output the string 
string name="dong";
int main(int argc,char** argv)
{
	cout<<name<<endl;
	cout<<"This is a LinkList test demo"<<endl;
	cout<<"This is demo of struct init."<<endl;
	//结构体参考：http://blog.csdn.net/github_26672553/article/details/50382188
	//1、结构体初始化
	bob.name="bob";
	bob.id=79;
	//2、定义在初始化（前面已经定义[没有试成功]）
	struct Info alice={"alice",80};
	//3、使用指定数据赋值给指定属性
	//struct Info many={ .name="many",.id=81};//注意这是c语言？c++也通用？
	//struct Info many={name:"many",id:81};
	//struct Info jine={name:"jine",id:82};

	struct Info many={"many",82};
	struct Info jine={"jine",83};
	struct Info kit={"kit",84};
	//<<<<<<<<<<<<<<<<<<<<<<<<
	cout<<"sizeof the struct or Info:"<<sizeof(Info)<<endl;
	cout<<"sizeof the object of Info:"<<sizeof(alice)<<endl;
	//
	cout<<"LinkList Init.<<<<<<<<<<<<<<<<<<<<<"<<endl;
	linkList.Insert(alice,0);
	linkList.Insert(bob,1);
	linkList.Insert(many,2);
	linkList.Insert(jine,3);
	//linkList.Insert(kit,10);//这个插入没有成功
	//cout<<linkList.length<<endl;//内部私有成员不可访问

	linkList.Print();
	cout<<"This is reverse"<<endl;
	linkList.Reverse();


}
#endif