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
 
	vector<Vec2f> lines;
	HoughLines(canny, lines, 1, CV_PI/180, 100);
 
    vector<cv::Vec2f>::iterator it = lines.begin();
	for(; it != lines.end(); ++it )
	{
		float rho = (*it)[0], theta = (*it)[1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		pt1.x = cvRound(x0 + 1000*(-b));
		pt1.y = cvRound(y0 + 1000*(a));
		pt2.x = cvRound(x0 - 1000*(-b));
		pt2.y = cvRound(y0 - 1000*(a));
		line( dst, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
	}
 
	imshow("src", src);  
	imshow("canny", canny);      
	imshow("dst", dst);  

	waitKey(0);  
	return 0;  
}