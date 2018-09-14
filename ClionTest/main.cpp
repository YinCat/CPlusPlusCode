#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main() {

    std::cout << "Hello, World!" << std::endl;
    Mat mat = imread("D:\\VSworkspace\\Image\\a.jpg");
    if(mat.empty()){
        cout<<"load filed..."<<endl;
        return -1;
    }
    namedWindow("src",CV_WINDOW_AUTOSIZE);
    imshow("src",mat);

    waitKey(0);
    return 0;
}