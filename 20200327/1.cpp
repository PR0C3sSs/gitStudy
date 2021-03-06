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
        Mat frame,result;

        cap >> frame;
        Size ResImgSiz = Size(frame.cols*scale,frame.rows*scale);
        Mat rFrame = Mat(ResImgSiz, frame.type());
        resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
        rFrame.copyTo(result);

        medianBlur(rFrame,result,3);

        imshow("result",result);
        imshow("frame",rFrame);
        waitKey(30);
    }
    return 0;
}
