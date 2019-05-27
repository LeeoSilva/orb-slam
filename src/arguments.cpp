#include "../headers/arguments.hpp"

void logInfo(){
	// TODO: Display CUDA version if supported
	std::cout << "OpenCV version: " << CV_VERSION << std::endl;
}

void logUsage(){
	std::cout << "./orb-slam <algorithm> <data>" << std::endl;
	std::cout << "Available algorithms: " << std::endl;
	std::cout << "GFFT" << std::endl;
	std::cout << "ORB" << std::endl;
}


