#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include <utility>

class featureExtractor{
public:
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> ORB_detector(const cv::Mat& img);
	cv::Mat ORB_compute(const cv::Mat& img, std::vector<cv::KeyPoint>& keypoints);
	std::vector<cv::Mat> swapImages(std::vector<cv::Mat>& vector, const cv::Mat& img);
	std::vector<cv::Point2f> GFTT_alg(const cv::Mat& img);
	//std::vector<cv::KeyPoint> computeKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features);
	std::vector<cv::KeyPoint> mat2KeyPoints(const std::vector<cv::Point2f>& features);


	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints); 
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& keypoints);
};
