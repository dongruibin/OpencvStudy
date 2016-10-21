////���ļ���Ҫ����������һ��Opencv�����ݽṹ
#include"include.h"
#include <opencv2/opencv.hpp>

#include<iostream>

using namespace cv;
using namespace std;


#if 0
//�ص��ǣ�
//  1--���ʹ��Point��ͼ���ж���2D��
//  2--����Լ�ʹ��Scalar
//  3--��Opencv�ĺ���Line��ֱ��
//  4--��Opencv�ĺ���ellipse������Բ
//  5--��Opencv��rectangle�����
//  6--��Opencv�ĺ���circle����Բ
//  7--��Opencv�ĺ���fillPoly�����������
//-----------------------Point

//		1.Point2f----��ά�����ȸ����͵���
//		2.Point2d----��ά˫���ȸ����͵���
//      3.Point3i----��ά���ε���

typedef Point_<int> Point2i;
typedef Point2i     Point;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point3_<int>   Point3i;
typedef Point3_<float> Point3f;
typedef Point3_<double> Point3d;

//1.��ά�ռ��У����ģ��
//2.����ඨ����һ����ά�ռ��еĵ㣬������������Ա���Ϊһ��ģ�������ָ��
//3.�����Ҳ��һЩ�Ƚ϶̵ı������Է����û���ʹ�ã����磺
//  cv::Point,cv::Point2i,cv::Point2f and cv::Point2d


//���͵���ģ��ʹ��
template<typedef _Tp> class Point_
{
public:
	typedef _Tp value_type;

	//various constructors  ���ֹ��캯��
	Point_();
	Point_(_Tp _x, _Tp _y);
	Point_(const Point_& pt);
	Point_(const CvPoint& pt);
	Point_(const CvPoint2D32f& pt);
	Point_(const Size_<_Tp>& sz);
	Point_(const Vec<_Tp, 2>& v);


	Point_& operator =(const Point_& pt);

	//conversion to another data type  ����ģ��--ת��Ϊ��һ������
	template<typedef _Tp2> operator Point_<_Tp2>() const;

	//conversion to the old-style C structures ת��Ϊ��ʽ�ָ��C�ṹ��

	operator CvPoint() const;
	operator CvPoint2D32f() const;
	operator Vec<_Tp, 2>() const;

	//dot product �������
	_Tp dot(const Point_& pt) const;
	//dot product computed in double-precision arithmetics
	double ddot(const Point_& pt) const;
	//cross-product 
	//����������
	double cross(const Point_& pt) const;
	//�жϵ�ǰ������Ƿ���ָ���ľ���֮��
	bool inside(const Rect<_Tp>& r) const;
	//�������Point��ģ������Ҫ��������Ϣ-----Point���x��y����
	_Tp x, y;//the point coordinates

};
////////����Sclar��ʹ��ģ������ʽ��
typedef Scalar_<double> Scalar;

//Sclar���--ģ����
//����һ��ʹ��4��Ԫ��ָ���������Vec������ģ�����ģ��
//ͨ��ʹ�õ���--cv::Scalar
//��ʵҲ����˵--Scalar��ɫ��---��һ�������----������
template<typename _Tp>class Scalar_ : public Vec<_Tp, 4>
{
public:
	//virous constructors  Ĭ�Ϲ��캯��
	Scalar_();
	//����Ҫ��һ��Ĭ�Ϲ��캯��
	//���Ĭ�Ϲ��캯�����ĸ������ֱ��ʾRGB+Alpha��ɫ�еģ�
	//v0--blue v1--green v2--red Alpha--͸��ɫ����
	Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, v3 = 0);
	Scalar_(const CvSalar& s);
	Saclar_(_Tp v0);

	//returnas  a scalar with all elements set to v0
	//����һ����v0����������ɫ��Scalar��
	static Scalar_<_Tp> all(_Tp v0);
	//conversion to the old-style CvScalar
	operator CvScalar() const;

	//conversion to another data type 
	template<typename T2> operator Scalar_<T2>() const;
	//per-element product
	Scalar_<_Tp> mul(const Scalar_<_Tp>& t, double scale = 1) const;

	//returns true if v1==v2==v3==0
	bool isReal() const;
};
	/*
	Point��
	 Point���ݽṹ��ʾ������ͼ������x��yָ����2D�㣬�ɶ���Ϊ��
	 Point pt;
	 pt.x=10;
	 pt.y=8;
	*/





#else

#endif