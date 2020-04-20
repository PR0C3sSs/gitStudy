#include <opencv.hpp>
#include <iostream>
#include <math.h>

// #define pi 3.14 

using namespace std;
using namespace cv;



int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg");
    Mat result;

    if (source.empty())return -1;

    float angle = -10.0;

    // double sin0 = sin(abs(angle)/180*pi);
    // double cos0 = cos(abs(angle)/180*pi);

    // float scale = 1/(sin0+cos0);
    float scale = 1;

    Point2f center(source.cols*0.5, source.rows*0.5);

    // const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);

    // warpAffine(source, result, affine_matrix, source.size());

    Mat rot = getRotationMatrix2D(center, angle, scale);
    Rect bbox = RotatedRect(center, source.size(), angle).boundingRect();

    rot.at<double>(0,2) += bbox.width / 2.0 - center.x;
    rot.at<double>(1,2) += bbox.height / 2.0 - center.y;;

    warpAffine(source, result, rot, bbox.size());

    imshow("source",source);
    imshow("result",result);
    waitKey();
    return 0;
}   