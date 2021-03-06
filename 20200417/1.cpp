#include <iostream>
#include<cmath>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

double Distance(Point pt1, Point pt2);

int main()
{
	Mat binMat;
	Mat gryMat = imread("C:\\Users\\Joey Lu\\Desktop\\rim.png", 0);
	Mat srcMat = imread("C:\\Users\\Joey Lu\\Desktop\\rim.png");
    
	Mat dstMat;
	srcMat.copyTo(dstMat);

	threshold(gryMat, binMat, 100, 255, THRESH_BINARY_INV);

	vector<vector<Point>>contours;
	findContours(binMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);


	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rbox = minAreaRect(contours[i]);

		Point2f vtx[4];
		rbox.points(vtx);
		double bLR = Distance(vtx[0], vtx[1])/Distance(vtx[1],vtx[2]);
		double area = Distance(vtx[0], vtx[1]) * Distance(vtx[1], vtx[2]);

		if (bLR > 0.9&&bLR < 1.1)
		{
			if (area > 50)
			{
				drawContours(dstMat, contours, i, Scalar(0, 255, 255), -1, 8);
			}
		}
	}

	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
    return 0;
}

double Distance(Point pt1, Point pt2)
{
	return sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
}