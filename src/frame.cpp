#include "../headers/frame.hpp"

// Class for processed frame	

Frame::Frame(const cv::Mat& img){ 
	cv::resize(img, img, cv::Size(img.size[1]*0.5, img.size[0]*0.5)); // Downscaling the image by half.
	cv::cvtColor(img, img, CV_RGB2GRAY); 
	this->frame = img; 
}

cv::Mat Frame::process_frame(){
	featureExtractor extractor;
	std::vector<cv::Point2f> pts = extractor.GFTT_detect(this->frame);
	this->keypoints  = extractor.mat2KeyPoints(pts);
	this->descriptors = extractor.ORB_compute(this->frame, this->keypoints);
	return extractor.drawKeyPoints(this->frame, keypoints);
}

void Frame::draw(){
 	cv::namedWindow("Video Feed", CV_WINDOW_AUTOSIZE);
	cv::resizeWindow("Video Feed", frame.size[1]*0.5, frame.size[0]*0.5);
	cv::imshow("Video Feed", frame);
}
