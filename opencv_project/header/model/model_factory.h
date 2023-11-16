#pragma once
#include "model/model_gray.h"
#include "model/model_canny.h"
#include "model/model_hsv.h"
#include "model/model_dnn.h"
#include "model/model_haar.h"
#include "model/model_mtcnn.h"

class ModelFactory {

public:
	//	Enum with types of models
	enum class TypeModel { TypeGrayModel, TypeCannyModel, TypeHSVModel, TypeDNNModel, TypeHaarModel, TypeMTCNNModel };
	//	Function returns pointer to type of model, that object of ModelFactory class calls from main function
	Model* getModel(enum TypeModel type);
};
