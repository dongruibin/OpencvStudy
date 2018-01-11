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
	//�ο���http://blog.csdn.net/jhszh418762259/article/details/60143152
	CvANN_MLP bp; //bp����  
	CvANN_MLP_TrainParams params; //bp�������  
	params.train_method = CvANN_MLP_TrainParams::BACKPROP;//ʹ�ü򵥵�BP�㷨������ʹ��RPROP  
	params.bp_dw_scale = 0.1;  
	params.bp_moment_scale = 0.1;  

	float labels[4][2] = { { 0,0 },{ 0,0 },{ 1,1 },{ 1,1 } }; //ѵ����ǩ���ݣ�ǰ������ʾ��������������ʾŮ��  
	Mat labelsMat(4, 2, CV_32FC1, labels);  

	float trainingData[4][2] = { {186,80},{185,81},{160,50},{161,48} }; //ѵ�����ݣ�����ά�ȣ���ʾ��ߺ�����  
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);  

	Mat layerSizes = (Mat_<int>(1, 4) << 2, 2, 2, 2);//�������������������ṹ�����롢�����������ڵ㣬ÿ�������㺬�����ڵ�  
	bp.create(layerSizes, CvANN_MLP::SIGMOID_SYM);//�����ΪSIGMOID����������ʹ�ø�˹����(CvANN_MLP::GAUSSIAN)����Ծ����(CvANN_MLP::IDENTITY)    
	bp.train(trainingDataMat, labelsMat, Mat(), Mat(), params);  

	bp.save("bp.xml");//�洢ģ��  
	//bp.load("bp.xml");//��ȡģ��  

	Mat sampleMat = (Mat_<float>(1, 2) << 160, 52); //�������ݣ�Ϊһ����  
	Mat responseMat;  
	bp.predict(sampleMat, responseMat);  
	Point maxLoc;  
	minMaxLoc(responseMat, NULL, NULL, NULL, &maxLoc); //responseΪ1�У�1���������ݣ���2�У���������𣩣�ÿ�б�ʾ��������������ƵĿ����ԣ�����ȡ����һ��  
	if (maxLoc.x == 0)  
		cout << "Boy" << endl;  
	if (maxLoc.x == 1)  
		cout << "Girl" << endl;  

	waitKey(6000);
	return 0;  
} 


#endif