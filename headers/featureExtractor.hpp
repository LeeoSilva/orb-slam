#pragma once
#include <vector>
#include <opencv2/opencv.hpp>

class featureExtractor{
public:
	cv::Mat detectKeypoints(const cv::Mat& img);
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& corners);
	std::vector<cv::KeyPoint> computeKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features);
};
