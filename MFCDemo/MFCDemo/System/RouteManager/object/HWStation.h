#pragma once

#include <string>

class HWStation
{
public:
	HWStation();
	~HWStation();

public:
	int stationID;
	int pointID;
	std::string type;
	int sysMode;
	int carrierTypes;
};

