#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "data/data.h"
#include "data/data_photo.h"
#include "view/view.h"

cv::Mat DataPhoto::getData() {

	//Read img
	static cv::Mat img = cv::imread("img/z_96977774.jpg");

	//check if not img
	if (!img.data)
	{
		std::cout << "Image is missing" << std::endl;
		return cv::Mat();		
	}
	return img;
}