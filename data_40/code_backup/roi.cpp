
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

Point ptL, ptR; //��껭�����ο�������յ�
Mat imageSource, imageSourceCopy;
Mat ROI; //ԭͼ��Ҫ�޸������ROI
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

void OnMouse(int event, int x, int y, int flag, void *ustg);   //���ص�����
///*13. ͼ��Ķ�ά�ָ����ͼ��ָ��rows�С�cols�е�С���ӡ�array[rows][cols]��
///     �����ڶ�άʸ��vector�У�
std::vector<std::vector<Mat> > partitionImage(Mat&src, int rows, int cols)
{
	std::vector<std::vector<Mat> > array(rows, std::vector<Mat>(cols));

	int irows = src.rows, icols = src.cols;//ԭͼ�������������
	int dr = irows / rows, dc = icols / cols;//�ָ���С��ͼ�������������
	//�ָ��С�������ͼ�����������������ʱ����Чͼ��ƫ��delt_x��delt_y��
	/// Ҳ���ǽ������������������ض����������ķ������ǣ���ͼ���ϡ��¡�����
	/// ��ɾ������һ������ء�����������Ϊ4������ͼ�񶥲����ײ��ֱ�ɾ��2�����ء�
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
	//�������������ص�
	Mat_<uchar>::iterator it = src.begin<uchar>();
	Mat_<uchar>::iterator itend = src.end<uchar>();
	for (; it != itend; ++it)
	{
		if ((*it) > 0) counter += 1;//��ֵ�������ص���0����255
	}
	return counter;
}
int cSums(Mat src)
{

	int counter = 0;
	//�������������ص�
	Mat_<uchar>::iterator it = src.begin<uchar>();
	Mat_<uchar>::iterator itend = src.end<uchar>();
	for (; it != itend; ++it)
	{
		if ((*it) = 0) counter += 1;//��ֵ�������ص���0����255
	}
	return counter;
}
int main()

{

	imageSource = imread("E:\\onedrive\\ͼƬ\\20190730_111725537_iOS (3).jpg");

	if (!imageSource.data)

	{

		return -1;

	}


	//namedWindow("ԭͼ", CV_WINDOW_NORMAL);

	imshow("ԭͼ", imageSource);

	setMouseCallback("ԭͼ", OnMouse);

	waitKey();

}

void OnMouse(int event, int x, int y, int flag, void *ustg)

{

	if (event == CV_EVENT_LBUTTONDOWN)   //���Ը���������� �� �յ���ȷ������

	{

		ptL = Point(x, y);   //���

		ptR = Point(x, y);   //�յ�

	}

	if (flag == CV_EVENT_FLAG_LBUTTON)    //������

	{

		ptR = Point(x, y);                //�յ�

		imageSourceCopy = imageSource.clone();

		rectangle(imageSourceCopy, ptL, ptR, Scalar(255, 0, 0));
		//namedWindow("ԭͼ", CV_WINDOW_NORMAL);

		imshow("ԭͼ", imageSourceCopy);

	}

	if (event == CV_EVENT_LBUTTONUP)        //�����κ��������¼�

	{

		if (ptL != ptR)

		{

			ROI = imageSource(Rect(ptL, ptR));  //�û�ѡ����ͼƬ
			//namedWindow("ROI", CV_WINDOW_NORMAL);

			imshow("ROI", ROI);//��ʾ �û�ѡ����ͼƬ

			cvtColor(ROI, ROIgray, CV_BGR2GRAY);
			imshow("ROIgray", ROIgray);							//��ʾ Rect(ptL, ptR) Ϊ�û�ѡ���ѡ���Ĵ�С
			threshold(ROIgray, result, 185, 255, CV_THRESH_BINARY);
			imshow("��ֵ�����ͼ", result);
			imwrite("��ֵ���Ķ�ά��.jpg", result);
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

	//��������Ҽ� ���������¼�     

	/*if (event == CV_EVENT_RBUTTONDOWN)

	{
		//�Զ����¼�

	}
	*/
}

