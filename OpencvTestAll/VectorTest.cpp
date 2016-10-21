#include <iostream>
#include <vector>//-----使用vector需要引入的头文件
#include <algorithm>
#include <stdio.h>
#include "include.h"


#ifdef USE_VECTOR
using namespace std;
//(1)头文件#include<vector>.
//(2)创建vector对象，vector<int> vec;
//(3)尾部插入数字：vec.push_back(a);
//(4)使用下标访问元素，cout << vec[0] << endl; 记住下标是从0开始的。
//(5)使用迭代器访问元素.
	//vector<int>::iterator it;
	//for (it = vec.begin(); it != vec.end(); it++)
	//	cout << *it << endl;
//(6)插入元素：    vec.insert(vec.begin() + i, a); 在第i + 1个元素前面插入a;
//(7)删除元素：    vec.erase(vec.begin() + 2); 删除第3个元素
//	vec.erase(vec.begin() + i, vec.end() + j); 删除区间[i, j - 1]; 区间从0开始
//(8)向量大小:vec.size();
//(9)清空 : vec.clear();

//创建一个全局结构体
typedef struct rect{
	int id;
	int length;
	int width;
	//对于向量元素是结构体的，可以在结构体内部定义比较函数，下面按照id,length,width升序排序
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
//建立一个数组，长度固定，测试是否可以进行vector进行读取
int array[10] = { 0 };

//说明 vector可以使用的元素不仅可以是int float double，也可以是全局结构体
int main(int argc,char **argv)
{
	vector<Rect> vec;
	Rect rect;
	rect.id = 1;
	rect.length = 2;
	rect.width = 3;
	//建立一个vec
	int i = 0;
	vector<int> vec1;
	for (i = 0; i < 10;i++)
	{
		vec1.push_back(i);
	}
	//输出这个区域,使用iteator进行输出
	for (vector<int>::iterator m = vec1.begin(); m != vec1.end();m++)//使用迭代器iterator进行输出，注意m是一个指针类型
	{
		cout << *m<< endl;//输出整个值
	}
	vec.push_back(rect);
	vector<Rect>::iterator it = vec.begin();
	cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;
	

	//执行正常，返回0
	return 0;
}

#else
#endif