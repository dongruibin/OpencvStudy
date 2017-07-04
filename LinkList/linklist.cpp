//linklist.cpp:链表实现的方法
#include"stdafx.h"
#include<iostream>
#include "linklist.h"
using namespace std;
//写一下Node
/*
struct Node{
	Info val;//Info 亦是结构体，带string int
	Node* next;
	.....
};
struct LinkList{
};



*/





//构造函数
LinkList::LinkList()
{
//初始化链表
	head=NULL;//head是LinkList类私有变量成员，是一个指针指向Node
	length=0;
}
void LinkList::InsertHead(Info val)//要插入数据
{
//插入头部


}
//插入结点
void LinkList::Insert(Info val,int pos)
{
//在指定位置插入

}


