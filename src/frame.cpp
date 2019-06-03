#include "../headers/frame.hpp"

// Class for processed frame	

Frame::Frame(const cv::Mat& img){ this->frame = img; }

void Frame::process_frame(){
	featureExtractor extractor;
	std::vector<cv::Point2f> pts = extractor.GFTT_detect(this->frame);
	this->keypoints  = extractor.mat2KeyPoints(pts);
	this->descriptors = extractor.ORB_compute(this->frame, this->keypoints);
}
	
 
