#include <iostream>
#include <opencv2\opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//加载图像，默认IMREAD_UNCHANGED
	//Mat src = imread("C:/Users/Tim/Desktop/Image/a.jpg");
	Mat src = imread("C:/Users/Tim/Desktop/Image/a.jpg", IMREAD_GRAYSCALE);  //以灰度图读取

	//判断是否加载成功
	if (src.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}

	//新建一个OpenCV窗口，大小根据图片自动调节
	namedWindow("Test Opencv", CV_WINDOW_AUTOSIZE);
	//显示图像
	imshow("Test Opencv", src);

	namedWindow("Output Window", CV_WINDOW_AUTOSIZE);
	Mat outImg;
	//色彩空间装换
	//cvtColor(src, outImg, CV_BGR2HLS);
	cvtColor(src, outImg, COLOR_BGR2GRAY);
	imshow("Output Window", outImg);

	//将Mat对象写入文件
	imwrite("C:/Users/Tim/Desktop/Image/a2.png",outImg);
	waitKey(0);
	return 0;
}