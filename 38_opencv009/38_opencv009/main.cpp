#include <opencv2/opencv.hpp>

using namespace cv;
int main(){
	Mat src = imread("C:\\VSworkspace\\Image\\img.jpg");
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	waitKey(0);
	return 0;
}