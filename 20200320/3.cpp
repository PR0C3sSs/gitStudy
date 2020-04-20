#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{   
    Mat src = imread("C:\\Users\\Joey Lu\\Desktop\\IMG_1989.JPG",0);
    Mat binaryMat, labelMat, statsMat, centrMat,resultMat;

    threshold(src,binaryMat,0,255,THRESH_OTSU);

    bitwise_not(binaryMat,binaryMat);

    Mat kernel = getStructuringElement(MORPH_RECT,Size(9,9));
    
    morphologyEx(binaryMat,resultMat,MORPH_OPEN, kernel);

    int nComp = connectedComponentsWithStats(resultMat, labelMat, statsMat, centrMat,8,CV_32S);

    for (int i = 0; i < nComp; i++)
    {
        cout << "connected Components NO." << i << endl;
        cout << "pixels = " << statsMat.at<int>(i,4) << endl;
        cout << "width = " << statsMat.at<int>(i,2) << endl;
        cout << "height = " << statsMat.at<int>(i,3) << endl;
    }

    cout << "the total of connected Components = " << nComp -1 << endl;

    for (int i = 1; i < nComp; i++)
    {
        Rect bndbox;
        bndbox.x = statsMat.at<int>(i,0);
        bndbox.y = statsMat.at<int>(i,1);
        bndbox.width = statsMat.at<int>(i,2);
        bndbox.height = statsMat.at<int>(i,3);
        rectangle(resultMat, bndbox, CV_RGB(255,255,255),1, 8, 0);
    }
    imshow("binaryMat",binaryMat);
    imshow("result",resultMat);
    imshow("frame",src);

    waitKey(0);
    return 0;

}