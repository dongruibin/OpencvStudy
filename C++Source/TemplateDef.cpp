//////////���ļ���Ҫ�Ƕ���ģ�����
#include<iostream>
#include"include.h"
#include<string.h>

using namespace std;
//1������һ����ģ�壺
//template<class ģ�����>
//class ����{
//	//�ඨ��.....
//};
//���У�template��������ģ��Ĺؼ��֣���ʾ����һ��ģ�壬ģ�����������һ����Ҳ�����Ƕ����
//���������Ͳ�����Ҳ�����Ƿ����Ͳ��������Ͳ����ɹؼ���class��typename�������ı�ʶ�����ɡ�
//����ģ�嶨���е�һ��������
//���磺
//template<class type, int width>
////typeΪ���Ͳ�����widthΪ�����Ͳ���

//����һ��ģ����
//��ģ�壺�����û�Ϊ�ඨ��һ��ģʽ��ʹ�����е�ĳЩ���ݳ�Ա��Ĭ�ϳ�Ա�����Ĳ�����ĳЩ��Ա�����ķ���ֵ���ܹ�ȡ�������͡�
template<class _Tp>//���Ͳ����ɹؼ���class��typename����
class dongClass
{
public:
	int index;
	_Tp a[25];
	void putName();
	_Tp DoAdd(_Tp a, _Tp b);
	void  putname(_Tp da);

};
template<class _Tp>
void dongClass<_Tp>::putName()
{
	cout << "I AM A TEST!" << endl;
}
template<class _Tp>
_Tp dongClass<_Tp>::DoAdd(_Tp a, _Tp b)
{
	cout << a + b << endl;
	return a + b;
}


template<class _Tp>
void dongClass<_Tp>::putname(_Tp da)
{
	cout << da << endl;
}

#ifdef TemplateDef
int main(int argc, char** argv)
{
////��ģ���ʵ��������ͨ�õ���ģ�嶨����������Ĺ��̳�Ϊģ��ʵ������
	dongClass<int>  p;//��ģ��ʹ�ã�����ģ��ʵ������һ��������࣬���ĸ�ʽΪ������<ʵ�ʵ�����>
	dongClass<float> h;
	p.putname(54.12);
	h.putname(54.121);
	h.DoAdd(12, 13);
	p.putName();
}
#else
#endif