#include "../headers/featureMatcher.hpp"
// For explanation of how does Feature Matching works  go to:
// https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_matcher/py_matcher.html
/*
std::vector<std::vector<cv::DMatch>> featureMatcher::match(const cv::Mat& descriptors1, const cv::Mat& descriptors2){
	std::vector<std::vector<cv::DMatch>> matches;
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); // Brute force matcher 
	matcher.match(descriptors1, descriptors2, matches);
	std::cout << "\rGot " << (matches.size() * matches[0].size())  << " matches" << std::endl;
	return matches;
}
*/
std::vector<cv::DMatch> featureMatcher::match(const cv::Mat& descriptors1, const cv::Mat& descriptors2){
	std::vector<cv::DMatch> matches;
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); // Brute force matcher 
	matcher.match(descriptors1, descriptors2, matches);
	std::cout << "Got " << matches.size()  << " matches" << std::endl;
	return matches;
}

std::vector<std::vector<cv::DMatch>> featureMatcher::knnMatch(const cv::Mat& descriptors1, const cv::Mat& descriptors2, const unsigned& k){
	std::vector<std::vector<cv::DMatch>> matches;
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); // Brute force matcher 
    matcher.knnMatch(descriptors1, descriptors2, matches, k);
	return matches;
}


cv::Mat featureMatcher::paint(const cv::Mat& actFrame, 
				const std::vector<cv::KeyPoint>& keypoints1, 
				const cv::Mat& prevFrame,
				const std::vector<cv::KeyPoint>& keypoints2,
				const std::vector<cv::DMatch>& matches)
{
	cv::Mat imgMatches; // output image
	drawMatches(actFrame, keypoints1, prevFrame, keypoints2, matches, imgMatches);
	return imgMatches;
}


void featureMatcher::sortByDistance(const std::vector<cv::DMatch>& matches){
	std::vector<cv::DMatch> sortedMatches;
	for(std::size_t i = 0; i <= matches.size(); ++i)
		std::cout << "Distance: " << matches[i].distance << std::endl;
}


/*
std::vector<std::vector<cv::DMatch>> featureMatcher::filter(const unsigned& maxDistance, const unsigned& minDistance, const std::vector<std::vector<cv::DMatch>> matches){
	std::vector<std::vector<cv::DMatch>> filteredMatches;
	for(std::size_t i = 0; i <= matches.size(); ++i)
		for(std::size_t j = 0; j <= matches[i].size; ++j){
			 bool cond = (matches[i].distance > minDistance && matches[i].distance < maxDistance);
			if(cond) filteredMatches.emplace_back(matches[i]);
		}

	return filteredMatches;
}


std::vector<cv::DMatch> featureMatcher::filter(const unsigned& maxDistance, const unsigned& minDistance, const std::vector<cv::DMatch> matches){
	std::vector<cv::DMatch> filteredMatches;
	for(std::size_t i = 0; i <= matches.size(); ++i)
		for(std::size_t j = 0; j <= matches[i].size; ++j){
			 bool cond = (matches[i].distance > minDistance && matches[i].distance < maxDistance);
			if(cond) filteredMatches.emplace_back(matches[i]);
		}

	return filteredMatches;
}


 
std::vector<cv::DMatch> featureMatcher::getTopMatches(const unsigned& top){

}
*/
