#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "opencv2/video/tracking.hpp"
#include <opencv2/video.hpp>
#include <opencv2/core/utility.hpp>
#include <cstring>

using namespace std;
using namespace cv;

int main(int argc,char** argv) {
    Mat frame;                                             //定义Mat类型用来存储视频流中的帧
    Ptr<TrackerKCF> tracker = TrackerKCF::create();        //创建一个跟踪器，跟踪器为KCF类型
    VideoCapture video(0);                                 //实例化一个对象video，控制摄像头视频的流入，输入参数0用来打开相机
    if(!video.isOpened())                                  //如果视频没有打开
    {
        cerr<<"cannot read video!"<<endl;                  //输出错误
        return -1;
    }

    Rect2d trackWindow;                                    //定义一个矩形窗口trackWindow
    video.read(frame);                                     //从video中读取图像存入到frame中
    trackWindow = selectROI("TRACK",frame);                //用鼠标框选感兴趣的区域
    if(trackWindow.width == 0 || trackWindow.height == 0)  //勾选区域如果为空，则返回0
    {
        return  0;
    }
    tracker->init(frame,trackWindow);                      //初始化跟踪器，用视频的第一帧，和框选的矩形区域
    cout<<"开始进行跟踪！";
    while(video.read(frame))                               //循环，不断读取视频的帧
    {

        tracker->update(frame,trackWindow);                //跟新跟踪器，用新的一帧和框选的区域
        rectangle(frame,trackWindow,Scalar(255,0,0),2,1);  //在后续帧中自动绘制矩形，矩形在新的一帧，大小为trackWindow，颜色为蓝色，线宽，线型
        imshow("TRACK",frame);                             //展示frame帧在TRACK窗口
        int k = waitKey(1);
        if(k == 27)
        {
            break;
        }
    }
//    video.read(frame);
//    Rect2d box(270,120,180,260);
//    tracker->init(frame,box);
//    while(video.read(frame))
//    {
//        tracker->update(frame,box);
//        rectangle(frame,box,Scalar(255,0,0),2,1);
//        imshow("Tracking",frame);
//        int k = waitKey(1);
//        if(k == 27)
//        {
//            break;
//        }
//    }
}
