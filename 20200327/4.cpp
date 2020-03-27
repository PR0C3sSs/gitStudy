#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    double scale = 0.5;

    while(1)
    {
        Mat frame,result,abs_result;

        cap >> frame;
        Size ResImgSiz = Size(frame.cols*scale,frame.rows*scale);
        Mat rFrame = Mat(ResImgSiz, frame.type());
        resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
        rFrame.copyTo(result);

        Sobel(rFrame,result,CV_16SC1,1,0,3);
        convertScaleAbs(result,abs_result);

        imshow("result",abs_result);
        imshow("frame",rFrame);
        waitKey(30);
    }
    return 0;
}