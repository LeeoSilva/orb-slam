#pragma once
#include <vector>
#include <utility>
#include <opencv2/opencv.hpp>

class featureMatcher{
	public:
	cv::Mat paint(const cv::Mat& actframe, 
		const cv::Mat& prevFrame,
		const std::vector<cv::KeyPoint>& keypoints1, 
		const std::vector<cv::KeyPoint>& keypoints2,
		const std::vector<cv::DMatch>& matches);


	void filter(const unsigned& maxDistance, const unsigned& minDistance);
	void sortByDistance(const std::vector<cv::DMatch>& matches);

	//std::vector<std::vector<cv::DMatch>> match(const cv::Mat& descriptors1, const cv::Mat& descriptors2);
	std::vector<cv::DMatch> match(const cv::Mat& descriptors1, const cv::Mat& descriptors2);
	std::vector<std::vector<cv::DMatch>> knnMatch(const cv::Mat& descriptors1, const cv::Mat& descriptors2, const unsigned& k);

	cv::Mat paint(const cv::Mat& actFrame, 
					const std::vector<cv::KeyPoint>& keypoints1, 
					const cv::Mat& prevFrame,
					const std::vector<cv::KeyPoint>& keypoints2,
					const std::vector<cv::DMatch>& matches);
};
