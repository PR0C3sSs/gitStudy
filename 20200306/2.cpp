#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap;

    cap.open(0);

    if(!cap.isOpened())
    {
        cout << "不能打开视频文件" << endl;
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS);

    cout << "fps" << fps << endl;
    while(1)
    {
        Mat frame;
        bool rSuccess = cap.read(frame);
        if (!rSuccess)
        {
            cout << "不能从视频文件中读取帧" << endl;
            break;
        }
        else
        {
            imshow("frame", frame);
        }
        waitKey(30);
        
    }
    return 0;
}
