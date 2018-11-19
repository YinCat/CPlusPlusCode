#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){

	//Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	Mat src = imread("C:\\Users\\Tim\\Desktop\\test.png");
	if (src.empty()){
		cout << "load image filed..." << endl;
		return -1;
	}

	namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	imshow("src_window", src);

	namedWindow("dst_window", CV_WINDOW_AUTOSIZE);
	Mat dst;
	//3*3均值滤波模糊
	blur(src, dst, Size(3, 3), Point(-1, -1));
	//GaussianBlur(src, dst, Size(3, 3), 11, 11);//高斯滤波
	imshow("dst_window", dst);

	

	waitKey(0);
	return 0;
}