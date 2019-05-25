#include "../headers/featureExtractor.hpp"



cv::Ptr<cv::FeatureExtractor> detectKeypoints(const cv::Mat& img){
	// Detecting Keypoints with FAST
	// Obs: the first argument of each detector usually controls
	// the balance between the amount of keypoints and their
	// stability.
	// FAST has the meaning of pixel intensity difference and usually 
	// varies in the region [0,40]
	cv::Ptr<cv::FeatureExtractor> detector = cv::FastFeatureExtractor::create(15);
	std::vector<cv::KeyPoint> keypoints;
	return detector->detect(img1, keypoint);
}


// cv::Ptr<cv::SURF> computeDescriptors(const std::vector<cv::KeyPoint>& keypoint){}
