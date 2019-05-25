#include "../headers/featureExtractor.hpp"
// For a explanation of what is a feature in a image
// and what is feature descriptors take a look into:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_features_meaning/py_features_meaning.html#features-meaning

cv::Mat featureExtractor::detectKeypoints(const cv::Mat& img) {
	cv::Mat features;
	
	float maxFeatures= 3000.0f;  // Max corners to detect
	float qualityLevel = 0.01f;  // if the best corner has the quality measure = 1500,
								 // and the qualityLevel=0.01 , then all the features which quality measure is
								 // less than 15 will be rejected.
								
	float minDistance = 3; // The minimum possible Euclidean distance between the returned features 
	cv::goodFeaturesToTrack(img, features, maxFeatures, qualityLevel, minDistance);
	return features;
}

cv::Mat featureExtractor::drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f> corners){
	for( std::size_t i = 0; i < corners.size(); i++ )
		cv::circle(img, corners[i], 3, cv::Scalar(0,255, 0), 3); 
	return img;
}

