#pragma once
#include <opencv2/opencv.hpp>
#include "../headers/featureExtractor.hpp"

struct Frame{
	cv::Mat frame;
	std::vector<cv::KeyPoint> keypoints;
	std::vector<cv::Mat> descriptors;
	
	Frame(const cv::Mat& img);
	cv::Mat process_frame();
	void draw();
};

