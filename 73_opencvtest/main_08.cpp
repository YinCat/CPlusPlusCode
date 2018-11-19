#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){

	Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	if (src.empty()){
		cout << "load image filed..." << endl;
		return -1;
	}

	namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	imshow("src_window", src);

	namedWindow("dst_window", CV_WINDOW_AUTOSIZE);
	Mat dst;
	//3*3¾ùÖµÂË²¨Ä£ºý
	blur(src, dst, Size(3, 3), Point(-1, -1));
	//GaussianBlur(src, dst, Size(3, 3), 11, 11);
	imshow("dst_window", dst);

	

	waitKey(0);
	return 0;
}