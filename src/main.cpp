#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <utility>
#include "../headers/processing.hpp"
#include "../headers/featureExtractor.hpp"
#include "../headers/arguments.hpp"
#include "../headers/frame.hpp"

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
	cv::Mat img; // Current frame
	cv::Mat prevFrame; // Previous frame (for matching)

	cv::Mat descriptor; // Descriptor of keypoints current frame
	cv::Mat prevDescriptor; // Descriptor of keypoints of the previous img
	imageHandler image; // src/imageHandler.cpp class
	featureExtractor detector; // src/featureDetector.cpp class
	cv::Mat gray; // Current img, but grayscale (easy for the algs)_

	while(cap.isOpened()){	
		cap >> img; // Converts VideoCapture to cv::Mat
		if(img.empty()) break;
		struct Frame frame = Frame(img);
		img = frame.process_frame();
		image.draw(img);
		if(cv::waitKey(30) >= 0) break;
	}

	return 0;
}
