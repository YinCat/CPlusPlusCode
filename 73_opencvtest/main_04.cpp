#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc,char **argv)
{
	Mat monochrome = imread("C:/Users/Tim/Desktop/Image/单色.bmp", IMREAD_UNCHANGED);
	Mat sixteen = imread("C:/Users/Tim/Desktop/Image/16色.bmp", IMREAD_UNCHANGED);
	Mat twofivesix= imread("C:/Users/Tim/Desktop/Image/256色.bmp", IMREAD_UNCHANGED);
	Mat twentyfour = imread("C:/Users/Tim/Desktop/Image/a.jpg", IMREAD_UNCHANGED);

	std::cout << "monochrome.channels:" << monochrome.channels() << std::endl;
	std::cout << "sixteen.channels:" << sixteen.channels() << std::endl;
	std::cout << "twofivesix.channels:" << twofivesix.channels() << std::endl;
	std::cout << "twentyfour.channels:" << twentyfour.channels() << std::endl;

	std::cout << "monochrome.depth:" << twofivesix.depth() << std::endl;
	printf("%d\n", twentyfour.depth());

	waitKey(0);
	while (1);
	return 0;
}