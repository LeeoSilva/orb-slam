#pragma once 
#include <opencv2/opencv.hpp>
#include <vector>

class imageHandler{
public:
	unsigned width = 0;
	unsigned heigth = 0;

	void setWidth(const unsigned& width);
	void setHeigth(const unsigned& height);
	void detectKeypoints(cv::Mat img);
	void draw(cv::Mat frame);
};
