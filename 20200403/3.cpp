#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg");
    Mat result;

    if (source.empty())return -1;

    const Point2f src_pt[] = {
                                Point2f(200,200),
                                Point2f(250,200),
                                Point2f(200,100)};
    const Point2f dst_pt[] = {
                                Point2f(300,100),
                                Point2f(300,50),
                                Point2f(200,100)};

    const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);

    warpAffine(source, result, affine_matrix, source.size());

    imshow("source",source);
    imshow("result",result);
    waitKey();
    return 0;
} 