#include <iostream>
#include <vector>//-----ʹ��vector��Ҫ�����ͷ�ļ�
#include <algorithm>
#include <stdio.h>
#include "include.h"


#ifdef USE_VECTOR
using namespace std;
//(1)ͷ�ļ�#include<vector>.
//(2)����vector����vector<int> vec;
//(3)β���������֣�vec.push_back(a);
//(4)ʹ���±����Ԫ�أ�cout << vec[0] << endl; ��ס�±��Ǵ�0��ʼ�ġ�
//(5)ʹ�õ���������Ԫ��.
	//vector<int>::iterator it;
	//for (it = vec.begin(); it != vec.end(); it++)
	//	cout << *it << endl;
//(6)����Ԫ�أ�    vec.insert(vec.begin() + i, a); �ڵ�i + 1��Ԫ��ǰ�����a;
//(7)ɾ��Ԫ�أ�    vec.erase(vec.begin() + 2); ɾ����3��Ԫ��
//	vec.erase(vec.begin() + i, vec.end() + j); ɾ������[i, j - 1]; �����0��ʼ
//(8)������С:vec.size();
//(9)��� : vec.clear();

//����һ��ȫ�ֽṹ��
typedef struct rect{
	int id;
	int length;
	int width;
	//��������Ԫ���ǽṹ��ģ������ڽṹ���ڲ�����ȽϺ��������水��id,length,width��������
	bool operator<(const rect &a) const
	{
		if (id != a.id)
			return id < a.id;
		else
		{
			if (length != a.length)
				return length < a.length;
			else
				return width < a.width;
		}
	}
}Rect;
//����һ�����飬���ȹ̶��������Ƿ���Խ���vector���ж�ȡ
int array[10] = { 0 };

//˵�� vector����ʹ�õ�Ԫ�ز���������int float double��Ҳ������ȫ�ֽṹ��
int main(int argc,char **argv)
{
	vector<Rect> vec;
	Rect rect;
	rect.id = 1;
	rect.length = 2;
	rect.width = 3;
	//����һ��vec
	int i = 0;
	vector<int> vec1;
	for (i = 0; i < 10;i++)
	{
		vec1.push_back(i);
	}
	//����������,ʹ��iteator�������
	for (vector<int>::iterator m = vec1.begin(); m != vec1.end();m++)//ʹ�õ�����iterator���������ע��m��һ��ָ������
	{
		cout << *m<< endl;//�������ֵ
	}
	vec.push_back(rect);
	vector<Rect>::iterator it = vec.begin();
	cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;
	

	//ִ������������0
	return 0;
}

#else
#endif