#include <opencv.hpp>

using namespace cv;

int main()
{   
    Mat srcMat = imread("C:\\Users\\Joey Lu\\Documents\\Code\\opencv\\gitStudy\\20200228\\1.jpg",0);
    imshow("src",srcMat);
    waitKey(0);
    return 0;
}