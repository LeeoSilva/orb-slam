#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "../headers/processing.hpp"
#include "../headers/featureExtractor.hpp"

void logInfo(){
	std::cout << "OpenCV version: " << CV_VERSION << std::endl;
}

int main(int argc, char** argv){
	logInfo();
	cv::VideoCapture cap(0); // Get the Webcam video capture
		if(argc == 2) cap.open(std::string(argv[1]), CV_WINDOW_NORMAL);

	cv::Mat frame; // OpenCV image type
	imageHandler image; // src/imageHandler.cpp class
	featureExtractor detector; // src/featureDetector.cpp class
	cv::Mat gray;

	while (cap.isOpened()){
		cap >> frame;
		cv::cvtColor(frame, gray, CV_RGB2GRAY);
		std::vector<cv::Point2f> corners =  detector.detectKeypoints(gray);
		frame = detector.drawKeyPoints(frame, corners);	
		image.draw(frame);
		if(cv::waitKey(30) >= 0) break;
	}

	return 0;
}
