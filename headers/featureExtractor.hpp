#pragma once
#include <opencv2/opencv.hpp>

class featureExtractor{
public:
	cv::Mat detectKeypoints(const cv::Mat& img);

};
