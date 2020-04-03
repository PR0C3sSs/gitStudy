#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg",0);
    Mat dx,dy;
    Mat result1,result2;
    
    Sobel(source,dx,CV_16SC1,1,0,3);
    Sobel(source,dy,CV_16SC1,0,1,3);

    Canny(dx,dy,result1,30,90);

    Canny(source,result2,30,90);

    imshow("source",source);
    imshow("result1",result1);
    imshow("result2",result2);
    waitKey();
    return 0;
} 