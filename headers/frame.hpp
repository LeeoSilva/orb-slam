#pragma once
#include <opencv2/opencv.hpp>
#include "../headers/featureExtractor.hpp"

class Frame{
public:
	cv::Mat frame;
	std::vector<cv::KeyPoint> keypoints;
	std::vector<cv::Mat> descriptors;
	
	Frame(const cv::Mat& img);
	void process_frame();
};

