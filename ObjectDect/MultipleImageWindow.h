#include<iostream>
#include<string>
#include<vector>
//opencv库加入
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class MultipleImageWindow
{
private:
	int cols;
	int rows;
	int canvas_width;
	int canvas_height;
	//Remember the string is belong to the namespace of std;
	std::string window_title;//这里光使用string是会提示错误的，因为它是在std命名空间
	vector<string> titles;
	vector<Mat> images;
	Mat canvas;
public:
	MultipleImageWindow(string window_title,int cols,int rows,int flags);
	//Add new image to stack of window
	int addImage(string title,Mat image,bool render=false);
	//Remove a image from position n
	void removeImage(int pos);
	//Render/redraw/update window
	void render();
};//Remember there has a ";"