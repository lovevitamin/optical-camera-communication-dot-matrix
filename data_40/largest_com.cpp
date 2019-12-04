#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/highgui/highgui_c.h>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <fstream>
#include <math.h>
#include <string>
using namespace cv;
using namespace std;

int main()
{
   // Mat src = imread( argv[1] );
	
    int largest_area=0;
    int largest_contour_index=0;
    Rect bounding_rect;
VideoCapture capture(0);
	while(1)													//
	{	
	Mat image;  //定义一个Mat变量，用于存储每一帧的图像		//	
		capture >> image;  //读取当前帧	
		Mat src = image.clone();
    Mat thr;
    cvtColor( src, thr, COLOR_BGR2GRAY ); //Convert to gray
    threshold( thr, thr, 125, 255, THRESH_BINARY ); //Threshold the gray

    vector<vector<Point> > contours; // Vector for storing contours

    findContours( thr, contours, RETR_CCOMP, CHAIN_APPROX_SIMPLE ); // Find the contours in the image

    for( size_t i = 0; i< contours.size(); i++ ) // iterate through each contour.
    {
        double area = contourArea( contours[i] );  //  Find the area of contour

        if( area > largest_area )
        {
            largest_area = area;
            largest_contour_index = i;               //Store the index of largest contour
            bounding_rect = boundingRect( contours[i] ); // Find the bounding rectangle for biggest contour
		drawContours( src, contours,largest_contour_index, Scalar( 0, 255, 0 ), 2 );
        }
    }

     // Draw the largest contour using previously stored index.

    imshow( "result", src );
    waitKey(30);
}
    return 0;
}
