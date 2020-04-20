#include <opencv.hpp>

using namespace cv;

int main()
{
    Mat srcMat = imread("C:\\Users\\Joey Lu\\Documents\\Code\\opencv\\gitStudy\\20200228\\1.jpg");
    Mat deepMat = srcMat.clone();
    Mat shallowMat = srcMat;
    uchar threshold = 100;
    int height = srcMat.rows;
    int width = srcMat.cols;
    for (int j = 0; j < height; j++ )
    {
        for (int i = 0; i < width; i++)
        {
            uchar average = (   srcMat.at<Vec3b>(j,i)[0]+
                                srcMat.at<Vec3b>(j,i)[1]+
                                srcMat.at<Vec3b>(j,i)[2])/3;
            if (average > threshold)
            {
                average = 255;
            }else
            {
                average = 0;
            }
            srcMat.at<Vec3b>(j,i)[0]=average;
            srcMat.at<Vec3b>(j,i)[1]=average;
            srcMat.at<Vec3b>(j,i)[2]=average;
        }
    }
    imshow("src",srcMat);
    imshow("deep",deepMat);
    imshow("shallow",shallowMat);
    waitKey(0);
    return 0;
}