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
using namespace std;
using namespace cv;

int i, j = 0;
int a=0;
int x[8]={362,380,395,415,432,450,468,486};
int y[8]={270,288,307,325,344,363,382,401};
int b[64] ;
char c[8] ;
int m = 1;
int k = 0;
Mat ROIgray;
Mat binary;
Mat binary1;
Mat frame_gray;
Mat eimage;
char keyCode;
//ofstream fout("jar1.txt");

std::vector<std::vector<Mat> > partitionImage(Mat&src, int rows, int cols)
{
	std::vector<std::vector<Mat> > array(rows, std::vector<Mat>(cols));

	int irows = src.rows, icols = src.cols;//The number of rows and columns of the original image
	int dr = irows / rows, dc = icols / cols;//The number of rows and the number of columns of the divided small block image
	// Split the number of rows, columns and the number of rows and columns of the image can not be divisible, the effective image offset delt_x, delt_y.
/// That is, discarding the remainder pixels that cannot be divisible, the method of discarding is, on the image, down, left and right
/// Each pixel that deletes the remainder is half. For example, if the remainder of the line is 4, then 2 rows of pixels are deleted at the top and bottom of the image.
	int delt_y = (irows%rows) / 2, delt_x = (icols%cols) / 2;
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			int x = j * dc + delt_x, y = i * dr + delt_y;
			array[i][j] = src(cv::Rect(x, y, dc, dr));
		}
	}
	return array;
}


int bSums(Mat src)
{

	int counter = 0;
	//Iterator access pixel
	Mat_<uchar>::iterator it = src.begin<uchar>();
	Mat_<uchar>::iterator itend = src.end<uchar>();
	for (; it != itend; ++it)
	{
		if ((*it) > 240) counter += 1;//二值化后，像素点是0或者255
	}
	return counter;
}
int cSums(Mat src)
{

	int counter = 0;
	//迭代器访问像素点
	Mat_<uchar>::iterator it = src.begin<uchar>();
	Mat_<uchar>::iterator itend = src.end<uchar>();
	for (; it != itend; ++it)
	{
		if ((*it) = 0) counter += 1;//二值化后，像素点是0或者255
	}
	return counter;
}


int main(int argc, char **argv)
{
	ofstream fout("20cm_30bps_dark.txt");
	VideoCapture cap;
	cap.open(0);
	while (1)
	{
		Mat frame;//Define a variable to display the video source one frame at a time
		cap >> frame;
		//Rect rect(405,31,80,80);
		//Mat image_roi = frame(rect);
		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		//cvtColor(image_roi, ROIgray, CV_BGR2GRAY);
		//thresholdIntegral2(ROIgray,binary);
		//equalizeHist(frame_gray, eimage);
		threshold( frame_gray, binary, 200, 255, THRESH_BINARY);
		//Mat binary2 = binary(rect);
		//binary1 = binary2.clone();
		//binary1 = binary;
    //int blockSize = 25;
    //int constValue = 10;
		//adaptiveThreshold(ROIgray, binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, blockSize, constValue);
		//vector<vector<Mat> > parts = partitionImage(binary1, 8, 8);
		//for (i = 0; i < 8;  i++)
			//{
				for (j = 1; j < 8;  j++)
				{
					Rect rect(x[j],270,16,16);
					Mat binary2 = binary(rect);
					int d = bSums(binary2);
					//int f = cSums(parts[i][j]);
					if ( d > 40 )
					{
						a += m << (7 - j);
					}
				//cout << (char)a[i] ;
				}
			//}
			//c[8] = b[8];
			//for (i = 0; i < 8; i++)
			//{
				
				cout << (char)a ;
				fout << (char)a ;
				a = 0;
				 
			
			//}
				//cout<< " ";
				//a[8]={ 0,0,0,0,0,0,0,0 };
		fout  << endl;
		cout  << endl;
		if (frame.empty())
		{
			cout << "Finish"<< endl ;
			break;
		}
		imshow("src", frame);
		imshow("frame_gray", frame_gray);
		//imshow("eimage", eimage);
		//imshow("Input video", binary);
		//imshow("image_roi",binary2);
		//imshow("ccc",binary1);
		//imshow("ROIgray",ROIgray); 
		//imshow("binary",binary);
		waitKey(30);
	}
//fout << "123";
	cap.release();
	fout.close();
	return 0;
 
}
