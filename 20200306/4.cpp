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
    for (int i = 0;i <= 255; i++)
    {
        std::cout << i << ": " << histogram[i] << std::endl;
    }
    imshow("src",srcMat);
    waitKey(0);
    return 0;
}