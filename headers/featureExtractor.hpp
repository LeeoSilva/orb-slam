#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include <utility>

class featureExtractor{
public:
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> ORB_detector(const cv::Mat& img);
	cv::Mat ORB_compute(const cv::Mat& img, std::vector<cv::KeyPoint>& keypoints);
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> ORB_detectAndCompute(const cv::Mat& img);
	std::vector<cv::KeyPoint> GFTT_detect(const cv::Mat& img);
	std::vector<std::vector<cv::DMatch>> matching(const cv::Mat& descriptors1, const cv::Mat& descriptors2);
	//std::vector<cv::KeyPoint> computeKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features);
	//std::vector<cv::KeyPoint> mat2KeyPoints(const std::vector<cv::Point2f>& features);


	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints); 
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& keypoints);
};
