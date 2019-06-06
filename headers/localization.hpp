#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class localization{
// The intrinsics matrix in this case needs to be given in pixel units,
// that means your principal point is usually (imageWidth / 2, imageHeight / 2) 
// and your focal length is usually focalLengthInMM / sensorWidthInMM * imageHeight. 

private:
	float pp1;
	float pp2;
	float principalPoint;
	float focalLength;

public:
	localization(const cv::Mat& img);
};
