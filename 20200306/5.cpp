#include <opencv.hpp>

using namespace cv;

int main()
{
    float histogram[256]={0};
    Mat srcMat = imread("1.PNG");
    int height = srcMat.rows;
    int width = srcMat.cols;
    for (int j = 0; j < height; j++ )
    {
        for (int i = 0; i < width; i++)
        {
            uchar gray = (   0.1140*srcMat.at<Vec3b>(j,i)[0]+
                             0.5870*srcMat.at<Vec3b>(j,i)[1]+
                             0.2989*srcMat.at<Vec3b>(j,i)[2]);
            srcMat.at<Vec3b>(j,i)[0]=gray;
            srcMat.at<Vec3b>(j,i)[1]=gray;
            srcMat.at<Vec3b>(j,i)[2]=gray;
            histogram[gray]++;
        }
    }
    Mat histImage(256, 256, CV_8UC3, Scalar(0, 0, 0));
    for (int i = 0;i <= 255; i++)
    {   histogram[i]/= 256;
        Point pt1,pt2;
        pt1.x = i;
        pt1.y = 255;
        pt2.x = i;
        pt2.y = 255-histogram[i];
        line(histImage,pt1,pt2,CV_RGB(255,0,0),1,8,0);
    }
    imshow("histogram",histImage);
    waitKey(0);
    return 0;
}