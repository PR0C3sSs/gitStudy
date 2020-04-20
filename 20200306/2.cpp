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
        cout << "���ܴ���Ƶ�ļ�" << endl;
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
            cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << endl;
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
