cmake_minimum_required(VERSION 3.14)
project(slam)

find_package(OpenCV REQUIRED ) # OpenCV

set(OPTION_BUILD "-j 8 -std=c++11")
set(OPTION_BUILD "-W -Wall -Werror") # For displaying debug information

add_library(processing
	./src/processing.cpp
	./headers/processing.hpp
)

add_library(featureExtractor
	./src/featureExtractor.cpp
	./headers/featureExtractor.hpp
)

add_library(arguments
	./src/arguments.cpp
	./headers/arguments.hpp
)

add_library(frame
	./src/frame.cpp
	./headers/frame.hpp
)

add_executable(slam
	./src/main.cpp
)

target_link_libraries(slam arguments)
target_link_libraries(slam processing)
target_link_libraries(slam frame)
target_link_libraries(slam featureExtractor)
target_link_libraries(slam ${OpenCV_LIBS})
