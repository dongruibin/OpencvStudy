////本文件主要作用是熟练一下Opencv的数据结构
#include"include.h"
#include <opencv2/opencv.hpp>

#include<iostream>

using namespace cv;
using namespace std;


#if 0
//重点是：
//  1--如何使用Point在图像中定义2D点
//  2--如何以及使用Scalar
//  3--用Opencv的函数Line绘直线
//  4--用Opencv的函数ellipse绘制椭圆
//  5--用Opencv的rectangle绘矩形
//  6--用Opencv的函数circle绘制圆
//  7--用Opencv的函数fillPoly绘制填充多边形
//-----------------------Point

//		1.Point2f----二维单精度浮点型点类
//		2.Point2d----二维双精度浮点型点类
//      3.Point3i----三维整形点类

typedef Point_<int> Point2i;
typedef Point2i     Point;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point3_<int>   Point3i;
typedef Point3_<float> Point3f;
typedef Point3_<double> Point3d;

//1.二维空间中，点的模板
//2.这个类定义了一个二维空间中的点，这个点的坐标可以被作为一个模板参数被指定
//3.这个类也有一些比较短的别名可以方便用户的使用，比如：
//  cv::Point,cv::Point2i,cv::Point2f and cv::Point2d


//典型的类模板使用
template<typedef _Tp> class Point_
{
public:
	typedef _Tp value_type;

	//various constructors  各种构造函数
	Point_();
	Point_(_Tp _x, _Tp _y);
	Point_(const Point_& pt);
	Point_(const CvPoint& pt);
	Point_(const CvPoint2D32f& pt);
	Point_(const Size_<_Tp>& sz);
	Point_(const Vec<_Tp, 2>& v);


	Point_& operator =(const Point_& pt);

	//conversion to another data type  函数模板--转换为另一种类型
	template<typedef _Tp2> operator Point_<_Tp2>() const;

	//conversion to the old-style C structures 转换为旧式分格的C结构体

	operator CvPoint() const;
	operator CvPoint2D32f() const;
	operator Vec<_Tp, 2>() const;

	//dot product 点积运算
	_Tp dot(const Point_& pt) const;
	//dot product computed in double-precision arithmetics
	double ddot(const Point_& pt) const;
	//cross-product 
	//向量积运算
	double cross(const Point_& pt) const;
	//判断当前这个点是否在指定的矩形之内
	bool inside(const Rect<_Tp>& r) const;
	//这是这个Point类模板最重要的两个信息-----Point点的x和y坐标
	_Tp x, y;//the point coordinates

};
////////下面Sclar类使用模板类形式进
typedef Scalar_<double> Scalar;

//Sclar类的--模板类
//这是一个使用4个元素指定的特殊的Vec向量类模板的类模板
//通常使用的是--cv::Scalar
//其实也就是说--Scalar颜色类---是一个特殊的----向量类
template<typename _Tp>class Scalar_ : public Vec<_Tp, 4>
{
public:
	//virous constructors  默认构造函数
	Scalar_();
	//很重要的一个默认构造函数
	//这个默认构造函数的四个参数分别表示RGB+Alpha颜色中的：
	//v0--blue v1--green v2--red Alpha--透明色分量
	Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, v3 = 0);
	Scalar_(const CvSalar& s);
	Saclar_(_Tp v0);

	//returnas  a scalar with all elements set to v0
	//返回一个用v0设置所有颜色的Scalar类
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
	Point类
	 Point数据结构表示了由其图像坐标x和y指定的2D点，可定义为：
	 Point pt;
	 pt.x=10;
	 pt.y=8;
	*/





#else

#endif