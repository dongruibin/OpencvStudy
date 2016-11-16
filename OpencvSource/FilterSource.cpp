#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;//��������ռ���#include<opencv2/opencv.hpp>����


//////���ļ���������Դ���ʵ�֣�Ϊ��֤���̱����������������ּ��»��ߡ�

//boxFilter()��������modules/imgproc/src/smooth.cpp

//�ҷ�����
void _boxFilter(InputArray _src,OutputArray _dst,int ddepth,Size ksize,Point anchor,bool normalize,int borderType)
{
	Mat src=_src.getMat();//ʵ�ֿ�������
	int sdepth=src.depth(),cn=src.channels();//������ʱ����������Դͼ���sdepth,Դͼͨ��������cn��
	//����ddepthС��0�����
	if(ddepth<0)
		ddepth=sdepth;
	_dst.create(src.size(),CV_MAKETYPE(ddepth,cn));//��ʼ��Ŀ��ͼ
	Mat dst=_dst.getMat();//����Ŀ��ͼ����̬Mat���ݵ���ʱ�����������Ժ�Ĳ���

	//����borderType��ΪBORDER_CONSTANT��normalizeΪ������
	if(borderType!=BORDER_CONSTANT && normalize)
	{
		if(src.rows==1)
			ksize.height=1;
		if(src.cols==1)
			ksize.width=1;
	}
	//�����HAVA_TRGRA_OPTIMIZATION�Ż�ѡ��Ķ��壬��ִ�к����е�trgra�Ż��溯��������
#ifdef HAVA_TEGRA_OPTIMIZATION

#else
	//����FilterEngine�˲����棬��ʽ��ʼ�˲�����
	/*
	Prt<FilterEngine> f=createBoxFilter(src.type(),dst.type(),
										ksize,anchor,normalize,borderType);
	f->apply(src,dst);
	*/
	/*
	���е�Ptr��������̬����Ķ��������ָ��ģ�塣FilterEngine��opencvͼ���˲����ܵĺ������档



	*/
#endif
}