#include "../headers/featureMatcher.hpp"

// For explanation of how does Feature Matching works go to:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_matcher/py_matcher.html

void featureMatcher::match(const cv::Mat& descriptors1, const cv::Mat& descriptors2){
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); // Brute force matcher 
	matcher.match(descriptors1, descriptors2, this->matches);
	std::cout << "\rGot " << this->matches.size() << " matches" << std::endl;
}

cv::Mat featureMatcher::paint(const cv::Mat& actFrame, 
				const std::vector<cv::KeyPoint>& keypoints1, 
				const cv::Mat& prevFrame,
				const std::vector<cv::KeyPoint>& keypoints2){
	cv::Mat imgMatches; // output image
	drawMatches(actFrame, keypoints1, prevFrame, keypoints2, this->matches, imgMatches);
	return imgMatches;
}

void featureMatcher::filter(const unsigned& maxDistance, const unsigned& minDistance){
	std::vector<cv::DMatch> filteredMatches; 
	for(std::size_t i = 0; i <= this->matches.size(); ++i){
		if(matches[i].distance > minDistance) filteredMatches.push_back(matches[i]);
		else if(matches[i].distance < maxDistance) filteredMatches.push_back(matches[i]);
	}
	this->matches = filteredMatches;
}

void featureMatcher::sortByDistance(){
	std::vector<cv::DMatch> sortedMatches;
	for(std::size_t i = 0; i <= this->matches.size(); ++i){
		std::cout << "Distance: " << this->matches[i].queryIdx<< std::endl;
	}
}


std::vector<cv::DMatch> featureMatcher::getTopMatches(const unsigned& top){

}

