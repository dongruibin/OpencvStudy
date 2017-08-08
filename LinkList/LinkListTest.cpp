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
	string name;//����һ�� char* name??
	int id;
};
struct Node//�����������ڵ�
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
//�����ӡ
void LinkList::Print()
{

}
#ifdef USE_LinkList
/*
������Ǵ����ݺ�ָ����һ���ڵ��ָ��
*/
LinkList linkList;
Info bob;//,alice;
//struct Info many;
//Info many;

int main(int argc,char** argv)
{
	cout<<"This is a LinkList test demo"<<endl;
	cout<<"This is demo of struct init."<<endl;
	//�ṹ��ο���http://blog.csdn.net/github_26672553/article/details/50382188
	//1���ṹ���ʼ��
	bob.name="bob";
	bob.id=79;
	//2�������ڳ�ʼ����ǰ���Ѿ�����[û���Գɹ�]��
	struct Info alice={"alice",80};
	//3��ʹ��ָ�����ݸ�ֵ��ָ������
	//struct Info many={ .name="many"; .id=81};//ע������c���ԣ�c++Ҳͨ�ã�
	//struct Info many={name:"many",id:81};
	//struct Info jine={name:"",id:82};

	//<<<<<<<<<<<<<<<<<<<<<<<<
	cout<<"sizeof the struct or Info:"<<sizeof(Info)<<endl;
	cout<<"sizeof the object of Info:"<<sizeof(alice)<<endl;


}
#endif