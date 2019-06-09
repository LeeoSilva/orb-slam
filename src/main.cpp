#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <utility>
#include "../headers/processing.hpp"
#include "../headers/featureMatcher.hpp"
#include "../headers/arguments.hpp"
#include "../headers/frame.hpp"
#include "../headers/featureExtractor.hpp"

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
			if(arg == "-h" || arg == "--help"){ logUsage(); return 0; }
			else if(arg == "--orb"){ alg = ORB; }
			else if(arg == "--gftt"){ alg = GFFT; }
			else data = arg;
		}	
	}

	logInfo();
	cv::VideoCapture cap; 
	if(data.empty()) cap = cv::VideoCapture(0, CV_WINDOW_NORMAL);	
	else cap.open(data, CV_WINDOW_NORMAL);

	imageHandler image; // src/imageHandler.cpp class
	featureMatcher matcher; // src/featureMatcher class

	cv::Mat matchedImage; // two images stacked horizontally
	for(cv::Mat img, prevImg; cap.isOpened() && cv::waitKey(30) < 0; image.draw(img)){	
		cap >> img; // Video streaming
		if(img.empty()) break;

		Frame actFrame(img); // Actual frame of the video
		actFrame.prepare_frame(); // Resize the frame and convert into grayscale
		actFrame.process_frame(alg); // Extract Good Features and generate Descriptors

		if(!prevImg.empty()){
			// Doing the same process for the previous frame for matching descriptors
			Frame prevFrame(prevImg);
			prevFrame.prepare_frame();
			prevFrame.process_frame(alg);

			matcher.match(actFrame.getDescriptors(), prevFrame.getDescriptors());	
			matchedImage = matcher.paint(img, actFrame.getKeyPoints(), prevImg, prevFrame.getKeyPoints());
		}

		prevImg = img;
	}
	return 0;
}

