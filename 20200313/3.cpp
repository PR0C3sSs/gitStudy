#include <opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

string window_name = "heiheihei";

void threshold_Mat(int th, void* data)
{
    Mat src = *(Mat*)(data);
    Mat dst;
    threshold(src,dst,th,255,0);
    imshow(window_name,dst);
}

int main()
{   
    Mat srcMat;
    Mat gryMat;
    int lowTh = 10;
    int maxTh = 255;

    srcMat = imread("C:\\Users\\Joey Lu\\Desktop\\test.PNG");
    if (!srcMat.data)
    {
        cout << "Í¼ÏñÔØÈëÊ§°Ü£¡" << endl;
        return 0;
    }

    cvtColor(srcMat, gryMat,CV_BGR2GRAY);
    imshow(window_name,gryMat);
    createTrackbar("xixixi",
                   window_name,
                   &lowTh,
                   maxTh,
                   threshold_Mat,
                   &gryMat);
    waitKey(0);
    return 0;
} 