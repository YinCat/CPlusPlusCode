#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
	
	Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\book.png");


	namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	imshow("src_window", src);

	Mat dst = Mat::zeros(src.size(), src.type());

	//¶¨Òå¾í»ýºË

	//±ßÔµ¼ì²â
	//Mat C = (Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1); // SobelËã×Ó ºáÏò±ßÔµ¼ì²â
	//Mat C = (Mat_<double>(3, 3) << -1,  0, 1, -2, 0, 2, -1, 0, 1); // SobelËã×Ó ×ÝÏò±ßÔµ¼ì²â
	//Mat C = (Mat_<double>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1); // PrewittËã×Ó ºáÏò±ßÔµ¼ì²â
	//Mat C = (Mat_<double>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1); // PrewittËã×Ó ×ÝÏò±ßÔµ¼ì²â
	//Mat C = (Mat_<double>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1); // LaplacianËã×Ó ±ßÔµ¼ì²â

	//Í¼ÏñÈñ»¯
	//Mat C = (Mat_<double>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
	//Mat C = (Mat_<double>(3, 3) << 1, 1, 1, 1, -7, 1, 1, 1, 1);//¸ü¼ÓÇ¿µ÷±ßÔµµÄÈñ»¯

	//¸¡µñ
	Mat C = (Mat_<double>(3, 3) << -6, -3, 0, -3, 1, 3, 0, 3, 6);
	filter2D(src, dst, src.depth(), C, Point(-1, -1));


	namedWindow("dst_window", CV_WINDOW_AUTOSIZE);
	imshow("dst_window", dst);

	moveWindow("src_window", 1, 1);
	moveWindow("dst_window", 1, 1);
	waitKey(0);
	return 0;
}