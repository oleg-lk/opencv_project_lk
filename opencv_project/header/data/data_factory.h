#pragma once
#include "data/data_photo.h"
#include "data/data_video.h"

class DataFactory {

public:
	//	Enum with datatypes
	enum class TypeData { TypeDataPhoto, TypeDataVideo };
	//	Function returns pointer to datatype, that object of DataFactory class calls from main function
	Data* getData(enum TypeData type);
};

