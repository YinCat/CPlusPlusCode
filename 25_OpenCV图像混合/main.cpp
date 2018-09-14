#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	Mat src1 = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	Mat src2 = imread("C:\\Users\\Tim\\Desktop\\Image\\b.jpg");
	Mat ret;//输出图像
	if (src1.empty() || src2.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}

	namedWindow("src1", CV_WINDOW_AUTOSIZE);
	imshow("src1", src1);
	namedWindow("src2", CV_WINDOW_AUTOSIZE);
	imshow("src2", src2);

	double alpha = 0.5;
	//两张图片大小一致、类型一致
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()){
		addWeighted(src1, alpha, src2, (1.0 - alpha), 0, ret);
		//add(src1, src2, dst, Mat());
		//multiply(src1, src2, dst, 1.0);
		namedWindow("ret", CV_WINDOW_AUTOSIZE);
		imshow("ret", ret);
	}else {
		cout << "Images vary in size or type!" << endl;
		return -1;
	}

	waitKey(0);
	return 0;
}