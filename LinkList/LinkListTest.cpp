//ѧϰ�ο����ӣ�http://blog.csdn.net/kevin_zhai/article/details/50494020
#include "include.h"
#include <iostream>

using namespace std;
//���ļ�֮ǰ��һ����ubuntu�ϴ����ģ��ṹ�����ʼ����ʾ
//ȱ��һ��"}"��ʵ���ϲ�û��ȱ�٣�����ԭ�����ڻ�û�з��֡�
/*
�����У�ÿ���ڵ�����洢����Ԫ�ص���������һ����ָ��
��һ���ڵ��ַ��ָ����
*/
struct Info
{
	string name;
	int id;
};
struct Node
{
	Info val;//��Ϣ����
	Node* next;//��ַ����
	Node(Info x):val(x),next(NULL){}//just construct
};
class LinkList
{
public:
	LinkList();//���캯��
	void InsertHead(Info val);
	void Insert(Info val,int pos);
	void Remove(Info val);
	int Length();//������
	void Reverse();//������
	int Find(Info val);
	void Print();//��ӡ����
	~LinkList();
private:
	Node* head;//���������ͷ��
	int length;//��������ĳ���
};
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
	Node *temp=head;//ָ��ڵ��ָ��
	Node *node=new Node(val);//�����вι��죬����ڵ㣬Ҳ���ǽ�Ҫ
	//�������ݱ�ɽڵ���ʽ
	if(pos==0)
	{
		node->next=temp;//���ﻹ���Ǹ�ֵ������ָ��ָ��ͷ
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

#ifdef USE_LinkList
int main(int argc,char** argv)
{
	cout<<"This is a LinkList test demo"<<endl;
}
#endif