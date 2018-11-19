#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\notbeautify1.png");
	//Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\AI.png");

	Mat dst;
	if (src.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}

	namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	imshow("src_window", src);


	//中值滤波去掉椒盐噪声
	//medianBlur(src, dst, 3);

	//双边滤波
	bilateralFilter(src, dst, 15, 100, 3);
	namedWindow("medianBlur_dst", CV_WINDOW_AUTOSIZE);
	imshow("medianBlur_dst", dst);


	Mat gblur;
	GaussianBlur(src, gblur, Size(15, 15), 3, 3);
	namedWindow("HelloWorld",CV_WINDOW_AUTOSIZE);
	namedWindow("bglur_dst", CV_WINDOW_AUTOSIZE);
	imshow("bglur_dst", gblur);

	//通过掩模提升对比度
	Mat retImg;
	Mat kernal = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, retImg, dst.depth(), kernal, Point(-1, -1), 0);

	namedWindow("retImg", CV_WINDOW_AUTOSIZE);
	imshow("retImg", retImg);

	waitKey(0);
	return 0;
}