#include "../headers/frame.hpp"

// Class for processed frame	

Frame::Frame(const cv::Mat& img){ 
	this->frame = img; 
}

void Frame::prepare_frame(){
	cv::resize(this->frame, this->frame, cv::Size(this->frame.size[1]*0.5, this->frame.size[0]*0.5)); // Downscaling the image by half.
	cv::cvtColor(this->frame, this->gray, CV_RGB2GRAY); 
}

void Frame::process_frame(){
	if(this->gray.channels() != 1){ // Checks if this->gray is grayscale
		std::cerr << "Image should have only one channel" << std::endl;
		return;
	}
	featureExtractor extractor;
	this->keypoints = extractor.GFTT_detect(this->gray);
	this->descriptors = extractor.ORB_compute(this->gray, this->keypoints); // Compute descriptors
	this->frame = extractor.drawKeyPoints(this->frame, this->keypoints); // Draw keypoints in the original image
}
 
void Frame::draw(){
 	cv::namedWindow("Video Feed", CV_WINDOW_AUTOSIZE);
	cv::resizeWindow("Video Feed", this->frame.size[1], this->frame.size[0]);
	cv::imshow("Video Feed", this->frame);
}

std::vector<cv::KeyPoint> Frame::getKeyPoints(){
	return this->keypoints;
}

cv::Mat Frame::getDescriptors(){
	return this->descriptors;
}
