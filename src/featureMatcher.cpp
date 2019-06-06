#include "../headers/featureMatcher.hpp"

// For better explanation of how does Feature Matching works go to:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_matcher/py_matcher.html


void featureMatcher::match(const cv::Mat& descriptors1, const cv::Mat& descriptors2){
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); // Brute force matcher 
	matcher.match(descriptors1, descriptors2, this->matches);
}

cv::Mat featureMatcher::draw(const cv::Mat& actFrame, 
					const std::vector<cv::KeyPoint>& keypoints1, 
					const cv::Mat& prevFrame,
					const std::vector<cv::KeyPoint>& keypoints2){
	cv::Mat imgMatches;
	drawMatches(actFrame, keypoints1, prevFrame, keypoints2, this->matches, imgMatches);
	return imgMatches;
}

