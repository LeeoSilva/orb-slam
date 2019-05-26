#pragma once
#include <vector>
#include <opencv2/opencv.hpp>

class featureExtractor{
public:
	std::vector<cv::KeyPoint > detectKeyPoints(const cv::Mat& img);
	std::vector<cv::KeyPoint> computeKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features);
	std::vector<cv::KeyPoint> mat2KeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features);
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints);
};
