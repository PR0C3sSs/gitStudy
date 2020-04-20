#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{   
    Mat src = imread("C:\\Users\\Joey Lu\\Desktop\\coin.png",0);
    Mat erode, dilate, open, close,binary;

    threshold(src,binary,0,255,THRESH_OTSU);

    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));

    morphologyEx(binary, erode,MORPH_ERODE, kernel);
    morphologyEx(binary, dilate,MORPH_DILATE, kernel);
    morphologyEx(binary, open,MORPH_OPEN, kernel);
    morphologyEx(binary, close,MORPH_CLOSE, kernel);

    imshow("source",src);
    imshow("binary",binary);
    imshow("erode",erode);
    imshow("dilate",dilate);
    imshow("open",open);    
    imshow("close",close);


    waitKey(0);
    return 0;
} 