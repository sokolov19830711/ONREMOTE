#pragma once

#include "dataStructures.h"

class DataManager
{
public:
	static void init();
	static McuInData& config();
	static McuOutData& outData();

private:

	DataManager() {};
	static DataManager& getData();

	McuInData _config;
	McuOutData _outData;
};

