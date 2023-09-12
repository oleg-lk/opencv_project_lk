#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/hsv_model.h"

cv::Mat HSVmodel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat hsvImage;

	cv::cvtColor(frame, hsvImage, cv::COLOR_BGR2HSV);

	//trackbar1 from 0 to 240, pos = 100, range 75-125
	int hue_from = _par1 - 25;
	int hue_to = _par1 + 25;


	if (hue_from < 0 || hue_to > 240){
		hue_from = 0;
		hue_to > 240;
	}

	//trackbar2 from 0 to 240, pos = 240
	int sat_from = _par2 - 25;
	int sat_to = _par2 + 25;

	//brightness
	int val_from = 30;
	int val_to = 220;

	cv::Mat rangeImage;

	//Checks if array elements lie between the elements of two other arrays
	/*hsvImage = inputArray, cv::Scalar(inputArray (upper bounds)),
	cv::Scalar(inputArray(lower bounds)), rangeImage = outputArray*/
	cv::inRange(hsvImage, cv::Scalar(hue_from, sat_from, val_from), 
		cv::Scalar(hue_to, sat_to, val_to), rangeImage);

	//������ �������

	cv::Mat dilateImage; 
	cv::dilate(rangeImage, dilateImage, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3)));

	//vector of vectors of points
	std::vector<std::vector<cv::Point>> contours;

	// finds outer contours, using only 4 corner points
	cv::findContours(dilateImage, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

	for (auto contour : contours) {

		cv::Scalar color(0, 255, 0);
		cv::drawContours(frame, contours, -1, color, cv::FILLED, 8);
	}

	return dilateImage;
}