#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg");
    Mat result;

    if (source.empty())return -1;

    Point2f pts1[] = {
                        Point2f(150,150),
                        Point2f(150,300),
                        Point2f(350,300),
                        Point2f(350,150)};

    Point2f pts2[] = {
                        Point2f(200,150),
                        Point2f(200,300),
                        Point2f(340,270),
                        Point2f(340,180)};

    Mat perspective_matrix = getPerspectiveTransform(pts1,pts2);

    warpPerspective(source, result, perspective_matrix, source.size());

    imshow("source",source);
    imshow("result",result);
    waitKey();
    return 0;
} 