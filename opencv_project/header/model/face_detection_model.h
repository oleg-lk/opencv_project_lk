#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class FaceDetectModel : public Model {

	public:
		//path to the model
		std::string fd_modelPath = "./onnx/face_detection_yunet_2023mar.onnx";
		//filter out faces of score < score_threshold
		float scoreThreshold = 0.9;
		//suppress bounding boxes >= nmsThreshold
		float nmsThreshold = 0.3;
		//keep top_k bounding boxes before NMS
		int topK = 5000;

		cv::Ptr<cv::FaceDetectorYN> detector;

		//constructor
		FaceDetectModel() {
			//creates an instance of this class with given parameters
			detector = cv::FaceDetectorYN::create(fd_modelPath, "", cv::Size(320, 320), scoreThreshold, nmsThreshold, topK);
		}
		//func visualize faces
		void visualize(cv::Mat& input, int frame, cv::Mat& faces, double fps, int thickness = 2);

		cv::Mat process(cv::Mat frame);
};