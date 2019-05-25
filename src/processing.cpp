#include "../headers/processing.hpp"
// setters for the aspect ratio of the image
void imageHandler::setWidth(const unsigned& x){ width = x; }
void imageHandler::setHeigth(const unsigned& y){ heigth = y; }

// In case there is modification in the aspect 
// ratio variables resize the image and drawn it
void imageHandler::draw(const cv::Mat& frame){
 	cv::namedWindow("Video Feed", 0);
	if (width != 0 && heigth != 0) cv::resize(frame, frame, cv::Size(width, heigth));
	cv::imshow("Video Feed", cv::Mat(frame));
}


