#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "../headers/processing.hpp"

void logInfo(){
	std::cout << "OpenCV version: " << CV_VERSION << std::endl;
}

int main(int argc, char** argv){
	logInfo();
	cv::VideoCapture cap(0); // Get the Webcam video capture
		if(argc == 2) cap.open(std::string(argv[1]));

	cv::Mat frame; // OpenCV image type
	imageHandler image;

	//image.setHeigth(10);
	//image.setWidth(10);

	while (cap.isOpened()){
		cap >> frame;
		image.draw(frame);
		if(cv::waitKey(30) >= 0) break;
	}

	return 0;
}
