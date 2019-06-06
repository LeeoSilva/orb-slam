#include "../headers/localization.hpp"

localization::localization(const cv::Mat& img){
	pp1 = img.size[1]*0.5;
	pp2 = img.size[0]*0.5;

}
