#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;


int main( )
{
	Mat src = imread("C:\\Users\\Joey Lu\\Desktop\\example.png");
	Mat canny,dst;
 
	Canny(src, canny, 110, 130);
    cvtColor(canny,dst, CV_GRAY2BGR);
 
	vector<Vec4i> lines;
	HoughLinesP(canny, lines, 1, CV_PI/180, 40,30,10);

    for (size_t i = 0; i < lines.size(); i++)
    {
        int x1 = lines[i][0]; 
        int y1 = lines[i][1];
        int x2 = lines[i][2];
        int y2 = lines[i][3];

        line (dst,  Point(x1, y1), Point(x2,y2), Scalar(0,0,255), 2, CV_AA);
    }

	imshow("src", src);  
	imshow("canny", canny);      
	imshow("dst", dst);  

	waitKey(0);  
	return 0;  
}