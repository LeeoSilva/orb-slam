#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <utility>
#include "../headers/processing.hpp"
#include "../headers/featureExtractor.hpp"
#include "../headers/arguments.hpp"

int main(int argc, char** argv){
	// Supported algorithms for feature detection
	enum Algorithm{
		ORB  = 0, // Oriented FAST and Rotated BRIEF
		GFFT = 1  // Good Features To Track 
	};

	std::string data; 
	Algorithm alg = ORB; // Default algorithm is ORB
	if(argc >= 2){
	for( std::size_t i = 1; i < argc; ++i){
			std::string arg = std::string(argv[i]);
			if(arg == "h" || arg == "--help"){ logUsage(); return 0; }
			else if(arg == "--orb"){ alg = ORB; }
			else if(arg == "--gftt"){ alg = GFFT; }
			else data = arg;
		}	
	}

	logInfo();
	cv::VideoCapture cap; 
	if(data.empty()) cap = cv::VideoCapture(0, CV_WINDOW_NORMAL);	
	else cap.open(data, CV_WINDOW_NORMAL);

	std::vector<cv::Mat> frames;
	cv::Mat frame; // Current frame
	cv::Mat prevFrame; // Previous frame (for matching)

	cv::Mat descriptor; // Descriptor of keypoints current frame
	cv::Mat prevDescriptor; // Descriptor of keypoints of the previous frame
	imageHandler image; // src/imageHandler.cpp class
	featureExtractor detector; // src/featureDetector.cpp class
	cv::Mat gray; // Current frame, but grayscale (easy for the algs)_

	//while(cap.isOpened()){	
	for(std::size_t i = 0; cap.isOpened(); i++){
		cap >> frame; // Converts VideoCapture to cv::Mat
		if(frame.empty()) break;
		cv::resize(frame, frame, cv::Size(frame.size[1]*0.5, frame.size[0]*0.5)); // Downscaling the image by half.
		cv::cvtColor(frame, gray, CV_RGB2GRAY);
		frames.push_back(frame);
		if(alg == ORB){
			std::pair<cv::Mat, std::vector<cv::KeyPoint>> result1 = detector.ORB_detectAndCompute(gray);
			std::pair<cv::Mat, std::vector<cv::KeyPoint>> result2 = detector.ORB_detectAndCompute(frames[i-1]);
			frame = detector.drawKeyPoints(frame, result1.second);
			std::vector<std::vector<cv::DMatch>> matches = detector.ORB_match(result1.first, result2.first);
		}
		else if(alg == GFFT){
			std::vector<cv::Point2f> corners = detector.GFTT_detect(gray);
			frame = detector.drawKeyPoints(frame, corners);
		}
		image.draw(frame);
		if(cv::waitKey(30) >= 0) break;
	}

	return 0;
}
