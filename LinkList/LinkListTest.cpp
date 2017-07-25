#include "include.h"
#include <iostream>

using namespace std;
//���ļ�֮ǰ��һ����ubuntu�ϴ����ģ��ṹ�����ʼ����ʾ
//ȱ��һ��"}"��ʵ���ϲ�û��ȱ�٣�����ԭ�����ڻ�û�з��֡�
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
	Node* head;//ָ��ڵ��ָ��
	int length;//��������ĳ���
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