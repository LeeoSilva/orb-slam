#include "../headers/featureExtractor.hpp"

// For a explanation of what is a feature in a image
// and what is feature descriptors take a look into:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_features_meaning/py_features_meaning.html#features-meaning

std::pair<cv::Mat, std::vector<cv::KeyPoint>> featureExtractor::ORB_detector(const cv::Mat& img){
	// A modification of FAST algorithm
	// Obs: Ironically it is faster then FAST '-'
	unsigned maxFeatures = 3000;
	cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create(maxFeatures); 
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;
	detector->detect(img, keypoints);
	detector->compute(img, keypoints, descriptors);	
	return std::make_pair(descriptors, keypoints);
}

cv::Mat featureExtractor::ORB_compute(const cv::Mat& img, std::vector<cv::KeyPoint>& keypoints){
	// Computes the descriptors to get ready for feature matching
	// Requires ORB::detector() function return statements to work
	cv::Mat descriptors;
	cv::Ptr<cv::FeatureDetector> extractor = cv::ORB::create();
	extractor->compute(img, keypoints, descriptors);
	return descriptors;
}

std::pair<cv::Mat, std::vector<cv::KeyPoint>> featureExtractor::ORB_detectAndCompute(const cv::Mat& img){
	featureExtractor detector; 
	std::pair<cv::Mat, std::vector<cv::KeyPoint>> result =  detector.ORB_detector(img);
	cv::Mat descriptors = detector.ORB_compute(img, result.second);
	return (descriptors, result);
}

std::vector<std::vector<cv::DMatch>> featureExtractor::matching(const cv::Mat& descriptors1, const cv::Mat& descriptors2){
	cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::NORM_HAMMING);
    std::vector< std::vector<cv::DMatch> > knn_matches;
    matcher->knnMatch( descriptors1, descriptors2, knn_matches, 2 );
	return knn_matches;
}

std::vector<cv::KeyPoint> featureExtractor::GFTT_detect(const cv::Mat& img) {
	// Determines strong corners in a image.
	std::vector<cv::KeyPoint> keypoints;
	unsigned maxFeatures= 3000;  // Max corners to detect
	float qualityLevel = 0.01f;  // if the best corner has the quality measure = 1500,
								 // and the qualityLevel=0.01 , then all the features which quality measure is
								 // less than 15 will be rejected.
								
	float minDistance = 3; // The minimum possible Euclidean distance between the returned features 
	cv::Ptr<cv::GFTTDetector> detector = cv::GFTTDetector::create(maxFeatures, qualityLevel, minDistance);
	detector->detect(img, keypoints);
	return keypoints;
}

cv::Mat featureExtractor::drawKeyPoints(const cv::Mat& img, const std::vector<cv::Point2f>& keypoints){
	unsigned circleRadius = 1;
	cv::Scalar circleColor(0, 255, 0);
	unsigned circleTickness = 3;
	for( std::size_t i = 0; i < keypoints.size(); i++ )
        cv::circle(img, keypoints[i], circleRadius, circleColor, circleTickness); 
	return img;
}

cv::Mat featureExtractor::drawKeyPoints(const cv::Mat& img, const std::vector<cv::KeyPoint>& keypoints){
	unsigned circleRadius = 1;
	cv::Scalar circleColor(0, 255, 0);
	unsigned circleTickness = 1;
	for( std::size_t i = 0; i < keypoints.size(); i++ )
		cv::circle(img, keypoints[i].pt, circleRadius, circleColor, circleTickness); 
	return img;
}

