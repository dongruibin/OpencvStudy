#ifndef __GUICV_H_
#define __GUICV_H_

using namespace cv;
//创建一个名为DongCv的命名空间
namespace DongCv{
	void DrawEllipse(Mat &img, double angle);
	void DrawFillCircle(Mat &img, Point center);
	void DrawPolygon(Mat &img);
	void DrawLine(Mat &img, Point start, Point end);
}


#endif