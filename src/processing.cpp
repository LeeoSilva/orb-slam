#include "../headers/processing.hpp"

// setters for the aspect ratio of the image
inline void imageHandler::setWidth(const unsigned& x){ width = x; }
inline void imageHandler::setHeigth(const unsigned& y){ heigth = y; }

// In case there is modification in the aspect 
// ratio variables resize the image and drawn it
void imageHandler::draw(const cv::Mat& frame){
 	cv::namedWindow("Video Feed", CV_WINDOW_AUTOSIZE);
	cv::resizeWindow("Video Feed", frame.size[1]*0.5, frame.size[0]*0.5);
	cv::imshow("Video Feed", frame);
}
 

