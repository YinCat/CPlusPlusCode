#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
#if 1
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

	//������һ��dst�����ʱ��ֻ�Ǵ�����Mat�����ͷ��
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(127, 0, 255);//�����̡���

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("output window", dst);


	////�������
	//dst = src.clone();
	//src.copyTo(dst);

	////��ȡͨ����
	//cvtColor(src, dst, CV_BGR2GRAY);
	//cout << "src.channels():" << src.channels() << endl;
	//cout << "dst.channels():" << dst.channels() << endl;

	////��ȡ��������ָ��
	//const uchar* firstRow = dst.ptr<uchar>(0);

	////��ȡ�����ء�������
	//int row = dst.rows;
	//int col = dst.cols;

	////��������Ϊ rows������Ϊ col������Ϊ type ��ͼ�񣬲�������Ԫ�س�ʼ��Ϊֵs
	//Mat m(5, 5, CV_8UC3, Scalar(0, 0, 255));
	//cout << m << endl;

	//namedWindow("smail", CV_WINDOW_AUTOSIZE);
	//imshow("smail", m);
#endif
#if 0
	Mat M;
	M.create(4, 3, CV_8UC2);
	M = Scalar(127, 127);
	cout << "M = " << endl << " " << M << endl << endl;
	uchar* firstRow = M.ptr<uchar>(0);
	printf("%d\n", *firstRow);

	//����С����
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout <<  C  << endl;


#endif

	
	waitKey(0);
	return 0;
}
