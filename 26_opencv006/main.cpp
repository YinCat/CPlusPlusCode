#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

Mat bgImage;
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolyon();
void Random();
int main(int argc, char **argv){

	bgImage = imread("C:\\Users\\Tim\\Desktop\\Image\\a.jpg");
	if (bgImage.empty()){
		cout << "load image filed..." << endl;
		return -1;
	}
	/*MyLines();

	MyRectangle();

	MyEllipse();

	MyCircle();

	MyPolyon();*/

	//绘制文字
	//背景图、文字、起始点、字体（前提是系统必须支持设定的字体）、字体放大倍数、颜色、线粗、线条类型
	//putText(bgImage, "HelloWorld", Point(30, 50), CV_FONT_HERSHEY_COMPLEX, 2.0, Scalar(0, 0, 255), 2, 8);
	//namedWindow("src_window", CV_WINDOW_AUTOSIZE);
	//imshow("src_window", bgImage);

	Random();

	waitKey(0);
	return 0;
}

//绘制线条
void MyLines(){
	Point p1 = Point(0, 0);
	Point p2 = Point(410, 624);
	Scalar color = Scalar(0, 0, 255);
	//背景图、直线两头坐标、颜色、线粗、
	//line(bgImage, p1, p2, color, 4, LINE_8);
	//line(bgImage, p1, p2, color, 4, LINE_4);
	line(bgImage, p1, p2, color, 4, LINE_AA);//LINE_AA是无锯齿
}

//绘制矩形
void MyRectangle(){
	//起始坐标点，宽和高
	Rect rect = Rect(120, 20, 200, 200);
	Scalar color = Scalar(0, 255, 0);
	rectangle(bgImage, rect, color, 2, LINE_AA);
}

//绘制椭圆
void MyEllipse(){
	Scalar color = Scalar(255, 0, 0);
	//背景图、中心点坐标、长轴和短轴、椭圆的倾斜度、（0-360就是绘制完整椭圆）、颜色、线粗、无锯齿
	ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(bgImage.cols / 4, bgImage.rows / 8), 45, 0, 180, color, 2, LINE_AA);
}

//绘制圆
void MyCircle(){
	Scalar color = Scalar(255, 255, 0);
	//背景图、圆心、半径
	Point center = Point(bgImage.cols / 2, bgImage.rows / 2);
	circle(bgImage, center, 150, color, 2, LINE_8);
}

//绘制多边形
void MyPolyon(){
	//定义好多边形顶点的二维数组
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(120, 180);
	pts[0][2] = Point(220, 200);
	pts[0][3] = Point(150, 80);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = { pts[0] };
	int npt[] = { 5 };
	Scalar color = Scalar(0, 255, 255);
	fillPoly(bgImage, ppts, npt, 1, color, 8);
}

//绘制随机线条
void Random(){
	RNG rng(12345);//设置随机种子
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(bgImage.size(), bgImage.type());
	namedWindow("random", CV_WINDOW_AUTOSIZE);

	for (size_t i = 0; i <10000; i++)
	{
		//确保随机数的范围
		pt1.x = rng.uniform(0, bg.cols);
		pt2.x = rng.uniform(0, bg.cols);
		pt1.y = rng.uniform(0, bg.rows);
		pt2.y = rng.uniform(0, bg.rows);

		waitKey(100);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random", bg);
	}
}