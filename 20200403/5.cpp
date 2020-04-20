#include <opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{
    Mat source = imread("C:\\Users\\Joey Lu\\Desktop\\lena_rot.jpg");
    Mat gray = imread("C:\\Users\\Joey Lu\\Desktop\\lena_rot.jpg",0);
    Mat binaryMat; 
    Mat compare = imread("C:\\Users\\Joey Lu\\Desktop\\lena.jpg");
    Mat result;
    if (source.empty())return -1;

    threshold(gray,binaryMat,250,255,THRESH_BINARY);
    
    // imshow(" ",binaryMat);

    int height = source.rows;
    int width = source.cols;

    int x = 0;
    int y = 0;

    for (int i = 0; i < width; i++)
    {
        if(binaryMat.at<uchar>(0,i) == 0)
        {
            x = i;
            break;
        }
    }

    for (int j = 0; j < height; j++)
    {
        if(binaryMat.at<uchar>(j,0) == 0)
        {
            y = j;
            break;
        } 
   }
    

    // cout << "x = " << x << "y = " << y << endl;

    double tan = (double)x/(double)y;

    // cout << "tan :" << tan << endl;

    double angle = atan2(x,y)/3.14*180;

    // cout << "angle" << angle << endl;

    double width0 = sqrt(x*x+y*y);

    // cout << "width0: " << width0 << endl;

    double scale = width/width0;

    // cout << "scale: " << scale <<endl;

    Point2f center(source.cols*0.5, source.rows*0.5);

    const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);

    warpAffine(source, result, affine_matrix, source.size());

    imshow("source",source);
    imshow("result",result);
    waitKey();
    return 0;
} 