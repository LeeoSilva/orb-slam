#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include "../headers/featureExtractor.hpp"

class Frame{
private:
	cv::Mat frame;
	cv::Mat gray;
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;
public:	
	Frame(const cv::Mat& img);
	void process_frame();
	void prepare_frame();
	void draw();
};

