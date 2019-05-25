#include "../headers/featureExtractor.hpp"
// For a explanation of what is a feature in a image
// and what is feature descriptors take a look into:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_features_meaning/py_features_meaning.html#features-meaning

//cv::Ptr<cv::FeatureExtractor> detectKeypoints(const cv::Mat& img){
cv::Mat detectKeypoints(const cv::Mat& img) {
	// Detecting Keypoints with FAST
	// Obs: the first argument of each detector usually controls
	// the balance between the amount of keypoints and their
	// stability.
	// FAST has the meaning of pixel intensity difference and usually 
	// varies in the region [0,40]
	
	cv::Mat features;
	cv::goodFeaturesToTrack(img, features, 3000, 0.01, 3);
	return features
	// cv::Ptr<cv::FeatureExtractor> detector = cv::FastFeatureExtractor::create(15);
	// std::vector<cv::KeyPoint> keypoints;
	// return detector->detect(img1, keypoint);
}


// cv::Ptr<cv::SURF> computeDescriptors(const std::vector<cv::KeyPoint>& keypoint){}
