#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg");
    Mat result;

    if (source.empty())return -1;

    float angle = -10.0, scale = 1;

    Point2f center(source.cols*0.5, source.rows*0.5);

    const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);

    warpAffine(source, result, affine_matrix, source.size());

    imshow("source",source);
    imshow("result",result);
    waitKey();
    return 0;
} 