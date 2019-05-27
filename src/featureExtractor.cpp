#include "../headers/featureExtractor.hpp"


// For a explanation of what is a feature in a image
// and what is feature descriptors take a look into:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_features_meaning/py_features_meaning.html#features-meaning


std::pair<cv::Mat, std::vector<cv::KeyPoint>> featureExtractor::ORB_alg(const cv::Mat& img){
	// A modification of FAST algorithm
	// Obs: Ironically it is faster then FAST '-'
	cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create(); 
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;
	detector->detect(img, keypoints);
	detector->compute(img, keypoints, descriptors);	
	return std::make_pair(descriptors, keypoints);
}


cv::Mat featureExtractor::GFTT_alg(const cv::Mat& img) {
	// Determines strong corners in a image.
	cv::Mat features;
	unsigned maxFeatures= 3000;  // Max corners to detect
	float qualityLevel = 0.01f;  // if the best corner has the quality measure = 1500,
								 // and the qualityLevel=0.01 , then all the features which quality measure is
								 // less than 15 will be rejected.
								
	float minDistance = 3; // The minimum possible Euclidean distance between the returned features 
	cv::goodFeaturesToTrack(img, features, maxFeatures, qualityLevel, minDistance);
	return features;
}

//std::vector<cv::KeyPoint> featureExtractor::mat2KeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& features){
//	std::vector<cv::KeyPoint> keypoints;
//	for(std::size_t i = 0; i < features.size(); i++)
//		keypoints.push_back(cv::KeyPoint(features[i].x, features[i].y, 20)); 
//	return keypoints;
//}

//std::vector<cv::Feature> featureExtractor::computeKeypoints(const cv::Mat& img, std::vector<cv::KeyPoint> keypoints){
//	std::vector<cv::ORB> extractor = cv::Orb.detectAndCompute();
//	for( std::size_t i = 0; i < keypoints[i]; i++){
//			
	//
//	}
//}


cv::Mat featureExtractor::drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints){
	unsigned circleRadius = 1;
	for( std::size_t i = 0; i < keypoints.size(); i++ )
		cv::circle(img, keypoints[i].pt, circleRadius, cv::Scalar(0,255, 0), 3); 
	return img;
}
