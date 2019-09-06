#pragma once

#include <string>

class HWSegment
{
public:
	HWSegment();
	~HWSegment();

public:
	int orgID;
	int startPoint;
	int endPoint;
	std::string segmentTemplate;
	std::string vehicle;
	int travelTime;
	int startsAsStartPoint;
	int endsAsEndPoint;
	int direction;
	int plcBits;
	int plcWord;
	int plcWord2;
	int addWeight;
	int length;
	int carrierTypes;
};

