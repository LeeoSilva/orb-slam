#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <utility>
#include "../headers/processing.hpp"
#include "../headers/featureExtractor.hpp"
#include "../headers/arguments.hpp"


int main(int argc, char** argv){

	enum Algorithm{
		GFFT = 0,
		ORB  = 1
	};

	std::string data = "";
	if(argc >= 2){
		for( std::size_t i = 1; i < argc; ++i){
			std::string arg = argv[i];
			if(arg == "h" || arg == "--help"){ std::cout << 1; logUsage(); return 0; }
			if(arg == "GFTT"){ std::cout << 2; Algorithm alg = GFFT; }
			else data = arg;
		}	
	}
	
	cv::VideoCapture cap(0, CV_WINDOW_NORMAL); // Get the Webcam video capture
	std::cout << data << std::endl;
	if(data != ""){
		cap.open(data, CV_WINDOW_NORMAL);
		if(!cap.isOpened()) throw std::invalid_argument("Could not open " + data);
	} 
		
	cv::Mat frame; // OpenCV image type
	imageHandler image; // src/imageHandler.cpp class
	featureExtractor detector; // src/featureDetector.cpp class
	cv::Mat gray;

	while (cap.isOpened()){ cap >> frame;
		cv::resize(frame, frame, cv::Size(frame.size[1]*0.5, frame.size[0]*0.5)); // downscalling the image by half.
		cv::cvtColor(frame, gray, CV_RGB2GRAY);

		std::pair<cv::Mat, std::vector<cv::KeyPoint>> result =  detector.ORB_alg(gray);
		frame = detector.drawKeyPoints(frame, result.second);
		image.draw(frame);
		if(cv::waitKey(30) >= 0) break;
		if(frame.empty()) break;
	}

	return 0;
}
