#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	if (src.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}

	namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	imshow("src_window", src);

	Mat src_gray;
	cvtColor(src, src_gray, CV_BGR2GRAY);

	int height = src_gray.rows;
	int width = src_gray.cols;

	//三通道
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;
	width = src.cols;

	//获取通道数
	int cn = src.channels();

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (cn == 1) {
				int gray = src_gray.at<uchar>(row, col);
				src_gray.at<uchar>(row, col) = 255 - gray;
			}
			else  if(cn == 3){
				//从原图中读取
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				//写入目标图像
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;

				src_gray.at<uchar>(row, col) = min(r, min(g, b));
				//src_gray.at<uchar>(row, col) = max(r, max(g, b));
			}
		}
	}
	//使用API进行操作
	//bitwise_not(src, dst);

	namedWindow("gray_window",CV_WINDOW_AUTOSIZE);
	imshow("gray_window", src_gray);
	//imshow("gray_window", dst);
	waitKey(0);
	return 0;
}