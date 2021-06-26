
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include "./aruco_src/opencv2/aruco/charuco.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void maker_test(Mat image)
{

	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

	cv::Ptr<cv::aruco::DetectorParameters> params = aruco::DetectorParameters::create();
	params->cornerRefinementMethod = cv::aruco::CORNER_REFINE_NONE;

	cv::Mat imageCopy;

	image.copyTo(imageCopy);
	std::vector<int> ids;
	std::vector<std::vector<cv::Point2f>> corners, rejected;
	cv::aruco::detectMarkers(image, dictionary, corners, ids, params);
	

    std::cout<<"---------------------"<<ids.size()<<std::endl;
	// if at least one marker detected
	if (ids.size() > 0) 
	{
		cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
		cv::imshow("ww", imageCopy);
		cv::waitKey(0);
	}
}


int main()
{
	Mat img = cv::imread("ww.png", 1);
	maker_test(img);	
}
