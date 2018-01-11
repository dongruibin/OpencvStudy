#include "include.h"
#include <opencv2/core/core.hpp>    
#include <opencv2/highgui/highgui.hpp>    
#include <opencv2/ml/ml.hpp>    
#include <iostream> 




#ifdef USE_ann

#define method 1

using namespace std;  
using namespace cv;  

int main(int argc,char** argv)  
{
	//参考：http://blog.csdn.net/jhszh418762259/article/details/60143152
	CvANN_MLP bp; //bp网络  
	CvANN_MLP_TrainParams params; //bp网络参数  
	params.train_method = CvANN_MLP_TrainParams::BACKPROP;//使用简单的BP算法，还可使用RPROP  
	params.bp_dw_scale = 0.1;  
	params.bp_moment_scale = 0.1;  

	float labels[4][2] = { { 0,0 },{ 0,0 },{ 1,1 },{ 1,1 } }; //训练标签数据，前两个表示男生，后两个表示女生  
	Mat labelsMat(4, 2, CV_32FC1, labels);  

	float trainingData[4][2] = { {186,80},{185,81},{160,50},{161,48} }; //训练数据，两个维度，表示身高和体重  
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);  

	Mat layerSizes = (Mat_<int>(1, 4) << 2, 2, 2, 2);//含有两个隐含层的网络结构，输入、输出层各两个节点，每个隐含层含两个节点  
	bp.create(layerSizes, CvANN_MLP::SIGMOID_SYM);//激活函数为SIGMOID函数，还可使用高斯函数(CvANN_MLP::GAUSSIAN)，阶跃函数(CvANN_MLP::IDENTITY)    
	bp.train(trainingDataMat, labelsMat, Mat(), Mat(), params);  

	bp.save("bp.xml");//存储模型  
	//bp.load("bp.xml");//读取模型  

	Mat sampleMat = (Mat_<float>(1, 2) << 160, 52); //测试数据，为一男生  
	Mat responseMat;  
	bp.predict(sampleMat, responseMat);  
	Point maxLoc;  
	minMaxLoc(responseMat, NULL, NULL, NULL, &maxLoc); //response为1行（1个测试数据），2列（共两种类别），每列表示该数据与该类相似的可能性，这里取最大的一类  
	if (maxLoc.x == 0)  
		cout << "Boy" << endl;  
	if (maxLoc.x == 1)  
		cout << "Girl" << endl;  

	waitKey(6000);
	return 0;  
} 


#endif