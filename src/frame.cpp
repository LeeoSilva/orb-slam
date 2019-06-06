#include "../headers/frame.hpp"

// Class for processed frame	

Frame::Frame(const cv::Mat& img){ 
	this->frame = img; 
}

void Frame::prepare_frame(){
	cv::resize(this->frame, this->frame, this->frame.size(), 0.5, 0.5); // Downscaling the image by half.
	cv::cvtColor(this->frame, this->gray, CV_RGB2GRAY); 
}

void Frame::process_frame(){
	if(this->gray.channels() != 1){ // Checks if this->gray is grayscale
		std::cerr << "Image should have only one channel" << std::endl;
		return;
	}
	featureExtractor extractor;
	std::cout << "Detecting good features to track" << std::endl;
	this->keypoints = extractor.GFTT_detect(this->gray);
	std::cout << "Computing descriptors" << std::endl;
	std::cout << "got " << this->keypoints.size() << " KeyPoints" << std::endl;
	this->descriptors = extractor.ORB_compute(this->gray, this->keypoints); // Compute descriptors
	std::cout << "Drawing keypoints" << std::endl;
	this->frame = extractor.drawKeyPoints(this->frame, this->keypoints); // Draw keypoints in the original image
	std::cout << "Done drawing keypoints" << std::endl;
}
 
void Frame::draw(){
 	cv::namedWindow("Video Feed", CV_WINDOW_AUTOSIZE);
	cv::resizeWindow("Video Feed", this->frame.size[1], this->frame.size[0]);
	cv::imshow("Video Feed", this->frame);
}
