#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include "./aruco_src/opencv2/aruco/charuco.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void gengerate_aruco_code()
{

	// to gengerate a new maker
	cv::Mat markerImage;//创建存储marker的Mat对象
	cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	cv::aruco::drawMarker(mdictionary, 12, 500, markerImage, 1);//生成marker ID:11  大小500x500像素  存放至Mat对象

	imshow("test", markerImage);//显示marker
	waitKey();
	imwrite("aruco_marker.jpg", markerImage);
}


int main()
{
	gengerate_aruco_code();
	return 0;
}
