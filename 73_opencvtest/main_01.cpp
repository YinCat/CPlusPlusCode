#include <iostream>
#include <opencv2\opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//����ͼ��Ĭ��IMREAD_UNCHANGED
	//Mat src = imread("C:/Users/Tim/Desktop/Image/a.jpg");
	Mat src = imread("C:/Users/Tim/Desktop/Image/a.jpg", IMREAD_GRAYSCALE);  //�ԻҶ�ͼ��ȡ

	//�ж��Ƿ���سɹ�
	if (src.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}

	//�½�һ��OpenCV���ڣ���С����ͼƬ�Զ�����
	namedWindow("Test Opencv", CV_WINDOW_AUTOSIZE);
	//��ʾͼ��
	imshow("Test Opencv", src);

	namedWindow("Output Window", CV_WINDOW_AUTOSIZE);
	Mat outImg;
	//ɫ�ʿռ�װ��
	//cvtColor(src, outImg, CV_BGR2HLS);
	cvtColor(src, outImg, COLOR_BGR2GRAY);
	imshow("Output Window", outImg);

	//��Mat����д���ļ�
	imwrite("C:/Users/Tim/Desktop/Image/a2.png",outImg);
	waitKey(0);
	return 0;
}