
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/highgui/highgui_c.h>
#include <vector>

#include <fstream>
#include<math.h>

using namespace cv;
using namespace std;

Point ptL, ptR; //鼠标画出矩形框的起点和终点
Mat imageSource, imageSourceCopy;
Mat ROI; //原图需要修复区域的ROI
Mat ROIgray;
Mat result;
//int b, c, d, e, f, g, h, n = 0;
//int a, b, c, d, e, f, g, h, n, i ,j = 0;
int i, j = 0;
int a[8]={ 0,0,0,0,0,0,0,0 };
int b[64] ;
char c[8] ;
int m = 1;
int k = 0;

void OnMouse(int event, int x, int y, int flag, void *ustg);   //鼠标回调函数
///*13. 图像的二维分割，即将图像分割成rows行、cols列的小格子—array[rows][cols]，
///     保存在二维矢量vector中，
std::vector<std::vector<Mat> > partitionImage(Mat&src, int rows, int cols)
{
	std::vector<std::vector<Mat> > array(rows, std::vector<Mat>(cols));

	int irows = src.rows, icols = src.cols;//原图像的行数、列数
	int dr = irows / rows, dc = icols / cols;//分割后的小块图像的行数、列数
	//分割行、列数与图像的行列数不能整除时，有效图像偏移delt_x、delt_y。
	/// 也就是将不能整除的余数像素丢弃，丢弃的方法就是，在图像上、下、左右
	/// 各删除余数一半的像素。比如行余数为4，则在图像顶部、底部分别删除2行像素。
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
	//迭代器访问像素点
	Mat_<uchar>::iterator it = src.begin<uchar>();
	Mat_<uchar>::iterator itend = src.end<uchar>();
	for (; it != itend; ++it)
	{
		if ((*it) > 0) counter += 1;//二值化后，像素点是0或者255
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
int main()

{

	imageSource = imread("E:\\onedrive\\图片\\20190730_111725537_iOS (3).jpg");

	if (!imageSource.data)

	{

		return -1;

	}


	//namedWindow("原图", CV_WINDOW_NORMAL);

	imshow("原图", imageSource);

	setMouseCallback("原图", OnMouse);

	waitKey();

}

void OnMouse(int event, int x, int y, int flag, void *ustg)

{

	if (event == CV_EVENT_LBUTTONDOWN)   //可以根据鼠标的起点 和 终点来确定矩形

	{

		ptL = Point(x, y);   //起点

		ptR = Point(x, y);   //终点

	}

	if (flag == CV_EVENT_FLAG_LBUTTON)    //画矩形

	{

		ptR = Point(x, y);                //终点

		imageSourceCopy = imageSource.clone();

		rectangle(imageSourceCopy, ptL, ptR, Scalar(255, 0, 0));
		//namedWindow("原图", CV_WINDOW_NORMAL);

		imshow("原图", imageSourceCopy);

	}

	if (event == CV_EVENT_LBUTTONUP)        //画矩形后，所做的事件

	{

		if (ptL != ptR)

		{

			ROI = imageSource(Rect(ptL, ptR));  //用户选择后的图片
			//namedWindow("ROI", CV_WINDOW_NORMAL);

			imshow("ROI", ROI);//显示 用户选择后的图片

			cvtColor(ROI, ROIgray, CV_BGR2GRAY);
			imshow("ROIgray", ROIgray);							//提示 Rect(ptL, ptR) 为用户选择后，选区的大小
			threshold(ROIgray, result, 185, 255, CV_THRESH_BINARY);
			imshow("二值化后的图", result);
			imwrite("二值化的二维码.jpg", result);
			//Mat img = imread("D:/CodeWork/MyImage/lena.jpg", 0);
			vector<vector<Mat> > parts = partitionImage(result, 8, 8);
			

			imshow("rogin img", parts[3][0]);
			for (i = 0; i < 8;  i++)
			{
				for (j = 0; j < 8;  j++)
				{
					
					int d = bSums(parts[i][j]);
					int f = cSums(parts[i][j]);
					if ( d > (f/100) )
					{
						a[i] += m << (7 - j);
					}
				}
			}
			//c[8] = b[8];
			for (i = 0; i < 8; i++)
			{
				
				cout <<(unsigned char) a[i] ;
				 
			
			}
			
				
				
			
			//cout << b << " " << c << " "<< d << " " << e << " " << f << " " << g << " " << h << " " << n << endl;
			
			waitKey();

		}

	}

	//单击鼠标右键 ，触发的事件     

	/*if (event == CV_EVENT_RBUTTONDOWN)

	{
		//自定义事件

	}
	*/
}

