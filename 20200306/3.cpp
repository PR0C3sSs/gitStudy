#include <opencv.hpp>

using namespace cv;

int main()
{
    Mat dispMat = imread("1.PNG");
    Point pt,pt1,pt2;
    pt.x = 280;
    pt.y = 280;
    pt1.x=0;
    pt1.y=0;
    pt2.x=585;
    pt2.y=580;
    circle(dispMat,pt,200,CV_RGB(255,0,0),3,8,0);
    line(dispMat,pt1,pt2,CV_RGB(255,0,0),5,8,0);
    Rect rect;
    rect.x = 300;
    rect.y = 500;
    rect.width;
    rect.height;
    rectangle(dispMat,rect,CV_RGB(255,0,0),5,8,0);
    imshow("dispMat",dispMat);
    waitKey(0);
    return 0;
}