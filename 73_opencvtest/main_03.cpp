#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
#if 0
	Mat src = imread("C:/Users/Tim/Desktop/Image/a.jpg");

	if (src.empty())
	{
		std::cout << "load image filed" << std::endl;
		return -1;
	}

	namedWindow("input window",CV_WINDOW_AUTOSIZE);
	imshow("input window", src);

	
	Mat m;
	m.create(4, 4, CV_8UC2);
	cout << m << endl;

	//定义了一个dst对象的时候只是创建了Mat对象的头部
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(127, 0, 255);

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("output window", dst);


	//都是深拷贝
	dst = src.clone();
	src.copyTo(dst);

	//获取通道数
	cvtColor(src, dst, CV_BGR2GRAY);
	cout << "src.channels():" << src.channels() << endl;
	cout << "dst.channels():" << dst.channels() << endl;

	//获取首行像素指针
	const uchar* firstRow = dst.ptr<uchar>(0);

	//获取行像素、列像素
	int row = dst.rows;
	int col = dst.cols;

	//创建行数为 rows，列数为 col，类型为 type 的图像，并将所有元素初始化为值s
	Mat m(5, 5, CV_8UC3, Scalar(0, 0, 255));
	cout << m << endl;

	namedWindow("smail", CV_WINDOW_AUTOSIZE);
	imshow("smail", m);
# endif
	Mat M;
	M.create(4, 3, CV_8UC2);
	M = Scalar(127, 127);
	cout << "M = " << endl << " " << M << endl << endl;
	uchar* firstRow = M.ptr<uchar>(0);
	printf("%d\n", *firstRow);

	//定义小数组
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout <<  C  << endl;

	while (1);
	waitKey(0);
	return 0;
}
