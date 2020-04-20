#include <opencv.hpp>

using namespace cv;

int main()
{
    Mat src_color = imread("1.PNG");
    std::vector<Mat> channels;
    split(src_color, channels);
    Mat B = channels.at(0);
    Mat G = channels.at(1);
    Mat R = channels.at(2);
    imshow("red", R);
    imshow("blue", B);
    imshow("green", G);
    waitKey(0);
    return 0;
}