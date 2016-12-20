#include <opencv2/opencv.hpp>
#include "include.h"
#include <iostream>
//surf检测定义所在路径
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>

using namespace cv;
//using namespace std;


#ifdef USE_SURFTEST
//#if 0
int main(int argc,char** argv)
{
	Mat img1=imread("D:\\4.jpg");
	Mat img2=imread("D:\\5.jpg");
	//检测surf特征点
	vector<KeyPoint> keypoints1,keypoints2;
	SurfFeatureDetector detector(400);
	detector.detect(img1,keypoints1);
	detector.detect(img2,keypoints2);
	//描述surf特征点
	SurfDescriptorExtractor surfDesc;
	Mat descriptros1,descriptros2;
	surfDesc.compute(img1,keypoints1,descriptros1);
	surfDesc.compute(img2,keypoints2,descriptros2);
	//计算匹配的点数
	BruteForceMatcher<L2<float>>matcher;
	vector<DMatch> matches;
	matcher.match(descriptros1,descriptros2,matches);
	std::nth_element(matches.begin(),matches.begin()+24,matches.end());
	matches.erase(matches.begin()+25,matches.end());
	//画出匹配图
	Mat imageMatches;
	drawMatches(img1,keypoints1,img2,keypoints2,matches,imageMatches,Scalar(255,0,0));
	//namedWindow("img2");
	imshow("img2",img2);
	waitKey(600000);

	return 0;
}

#else
#if 0
int main(int argc,char** argv)
{
    Mat image1=imread("../b1.png");
    Mat image2=imread("../b2.png");
    // 检测surf特征点
    vector<KeyPoint> keypoints1,keypoints2;   
    SurfFeatureDetector detector(400);
    detector.detect(image1, keypoints1);
    detector.detect(image2, keypoints2);
    // 描述surf特征点
    SurfDescriptorExtractor surfDesc;
    Mat descriptros1,descriptros2;
    surfDesc.compute(image1,keypoints1,descriptros1);
    surfDesc.compute(image2,keypoints2,descriptros2);
    // 计算匹配点数
    BruteForceMatcher<L2<float>>matcher;
    vector<DMatch> matches;
    matcher.match(descriptros1,descriptros2,matches);
    std::nth_element(matches.begin(),matches.begin()+24,matches.end());
    matches.erase(matches.begin()+25,matches.end());
    // 画出匹配图
    Mat imageMatches;
    drawMatches(image1,keypoints1,image2,keypoints2,matches,
		imageMatches,Scalar(255,0,0));
    namedWindow("image2");
    imshow("image2",image2);
    waitKey();
       
    return 0;
}
#endif
#endif