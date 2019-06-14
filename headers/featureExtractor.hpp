#pragma once
#include <opencv2/opencv.hpp>
#include <utility>
#include <vector>

template<class T>  
class featureExtractor<std::vector<cv::DMatch>> {
public:
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> ORB_detector(const cv::Mat& img);
	cv::Mat ORB_compute(const cv::Mat& img, std::vector<cv::KeyPoint>& keypoints);
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> ORB_detectAndCompute(const cv::Mat& img);
	std::vector<cv::KeyPoint> GFTT_detect(const cv::Mat& img);
	std::vector<std::vector<cv::DMatch>> matching(const cv::Mat& descriptors1, const cv::Mat& descriptors2);
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints) const;
	cv::Mat drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& keypoints) const;
};

class featureExtractor<std::vector<std::vector<cv::DMatch>>>{
public:
	std::pair<cv::Mat, std::vector<cv::DMatch>> ORB_detector(const cv::Mat& img);
	cv::Mat ORB_compute(const cv::Mat& img,  

}
