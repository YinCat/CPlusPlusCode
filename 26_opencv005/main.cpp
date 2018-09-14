#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	Mat src = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	Mat dst;
	if (src.empty())
	{
		cout << "load image filed..." << endl;
		return -1;
	}
	char *input_win = "input_win";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	imshow("input_win", src);

	int height = src.rows;
	int wight = src.cols;

	//构建与src同等大小的空白图
	dst = Mat::zeros(src.size(), src.type());

	//差异倍数
	float alpha = 1.0f;
	//增益变量
	float beta = 50.0f;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < wight; col++) {
			//根据通道数目来判断处理方式
			if (src.channels() == 3){
				float b = src.at<Vec3b>(row, col)[0];
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b*alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g*alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r*alpha + beta);
			}
			else if (src.channels() == 1) {
				float v = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(v*alpha + beta);
			}
		}
	}

	//输出图像
	char *output_win = "output_win";
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow(output_win, dst);

	waitKey(0);
	return 0;
}