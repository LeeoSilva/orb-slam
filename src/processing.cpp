#include "../headers/processing.hpp"

void imageHandler::draw(const cv::Mat& frame){
	cv::namedWindow("Video Feed", 0);
	if (width != 0 && heigth != 0)
		cv::resize(frame, frame, cv::Size(width, heigth));
	cv::imshow("Video Feed", cv::Mat(frame));

}

void imageHandler::setWidth(const unsigned& x){
	width = x;
}

void imageHandler::setHeigth(const unsigned& y){
	 heigth = y;
}

