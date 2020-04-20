#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{   
    Mat src = imread("C:\\Users\\Joey Lu\\Desktop\\clip.png",0);
    Mat binaryMat, labelMat, statsMat, centrMat,resultMat;

    threshold(src,binaryMat,0,255,THRESH_OTSU);

    bitwise_not(binaryMat,binaryMat);

    
    Mat kernel2 = getStructuringElement(MORPH_RECT,Size(3,3));
    
    morphologyEx(binaryMat,resultMat,MORPH_ERODE, kernel2);

    int nComp = connectedComponentsWithStats(resultMat, labelMat, statsMat, centrMat,8,CV_32S);

    int Flag = 0;

    for (int i = 0; i < nComp; i++)
    {
        cout << "connected Components NO." << i << endl;
        cout << "pixels = " << statsMat.at<int>(i,4) << endl;
        cout << "width = " << statsMat.at<int>(i,2) << endl;
        cout << "height = " << statsMat.at<int>(i,3) << endl;
        if (  statsMat.at<int>(i,4) <= 5000)
        {
            Flag ++;
            cout << "This is not a clip." << endl;
        }

    }

    cout << "the total of connected Components = " << nComp -1 -Flag << endl;
    
    getchar();
    return 0;

}