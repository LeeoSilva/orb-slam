#include "../headers/processing.hpp"
// setters for the aspect ratio of the image
inline void imageHandler::setWidth(const unsigned& x){ width = x; }
inline void imageHandler::setHeigth(const unsigned& y){ heigth = y; }

// In case there is modification in the aspect 
// ratio variables resize the image and drawn it
void imageHandler::draw(const cv::Mat& frame){
	const std::string windowName = "Video Feed";
 	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	cv::resizeWindow(windowName, frame.size[0], frame.size[1]);
	cv::imshow(windowName, cv::Mat(frame));
}
 

