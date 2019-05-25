cmake_minimum_required(VERSION 3.14)
project(orb-slam)

find_package(OpenCV REQUIRED ) # OpenCV

set(OPTION_BUILD "-j9 -std=c++11")

add_library(processing
	./src/processing.cpp
	./headers/processing.hpp
)

add_library(featureExtractor
	./src/featureExtractor.cpp
	./headers/featureExtractor.hpp
)

add_executable(orb-slam
	./src/main.cpp
)

target_link_libraries(orb-slam featureExtractor)
target_link_libraries(orb-slam processing)
target_link_libraries(orb-slam ${OpenCV_LIBS})
