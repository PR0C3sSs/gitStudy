#include <opencv.hpp>

using namespace cv;

int main()
{   
    Mat result1;
    Mat result2;
    Mat srcMat = imread("C:\\Users\\Joey Lu\\Desktop\\_\\1.jpg",0);
    threshold(srcMat,result1,100,255,THRESH_OTSU);
    adaptiveThreshold(srcMat,result2,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,15,10);
    imshow("source",srcMat);
    imshow("threshold",result1);
    imshow("adaptiveThreshold",result2);
    waitKey(0);
    return 0;
} 