#include"include.h"
#include<opencv2\opencv.hpp>

//本例程使用答题卡识别作为参考实例
//博客参考地址：http://blog.csdn.net/cp562090732/article/details/47804003
/*
	1、图像读取
	2、图片转化为灰度图
	3、图片设定阈值
	4、开运算（先腐蚀、后膨胀）
	5、指定答题区域
	6、找到涂选框
	7、根据涂选框的坐标确定所涂选的选项以及题号
*/
using namespace std;
using namespace cv;

#ifdef ANSWER


int main(int argc,char** argv)
{

	return 0;
}

#else
#endif