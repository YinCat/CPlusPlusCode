#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

int main(int argc,char* argv[])
{
	Mat src;
	Mat dst;

	src = imread("C:/Users/Tim/Desktop/Image/e.jpg");
	if (!src.data)
	{
		std::cout << "load iamge filed..." << std::endl;
		return -1;
	} 

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//��ȡͼ�������,һ����Ҫ����ͼ���ͨ����
	int cols = (src.cols-1) * src.channels();
	int rows = src.rows;

	//��ȡͨ����Ŀ
	int offsetx = src.channels();

	//����һ����Դͼ���С���������ͬ��ȫ0����
	dst = Mat::zeros(src.size(),src.type());

	//��ȡ��ʼʱ��
	double start = getTickCount();
	
	//for (int row = 1; row < (rows - 1); row++)
	//{
	//	//��ȡÿһ��ͨ��������ָ��
	//	const uchar* prev = src.ptr<uchar>(row - 1);
	//	const uchar* cur = src.ptr<uchar>(row);
	//	const uchar* next = src.ptr<uchar>(row + 1);

	//	uchar* output = dst.ptr<uchar>(row);

	//	for (int col = offsetx; col < cols; col++){
	//		//output[col] = (5 * cur[col] - (cur[col - offsetx] + cur[col + offsetx] + prev[col] + next[col]));
	//		output[col] = saturate_cast<uchar>(5 * cur[col] - (cur[col - offsetx] + cur[col + offsetx] + prev[col] + next[col]));
	//	}
	//}

	//����һ����ģ
	//Mat kernal = (Mat_<char>(3, 3) << 0, 1, 0, -1, 5, -1, 0, -1, 0);//�Աȶ���ǿ
	Mat kernal = (Mat_<char>(3, 3) << 0, -1, 0, -1, 6, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernal);

	//��ȡ����ʱ��
	double run_time = (cvGetTickCount() - start)/getTickFrequency();
	std::cout << run_time<< std::endl;

	namedWindow("output image", CV_WINDOW_AUTOSIZE);
	imshow("output image", dst);
	waitKey(0);
	return 0;
}