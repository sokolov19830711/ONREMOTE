#pragma once

#include <DHT.h>

class MoistureSensors
{
public:

	MoistureSensors();
	~MoistureSensors();

	void init();
	void update();

private:

	DHT* _dht = nullptr;
};

