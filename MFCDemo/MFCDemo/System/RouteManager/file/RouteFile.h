#pragma once

#include "../object/HWPoint.h"
#include "../object/HWSegment.h"
#include "../object/HWStation.h"

#include <map>
#include <memory>

class RouteFile
{
public:
	RouteFile();
	~RouteFile();

	bool ReadPoints(std::map<int, HWPoint> &pointsMap);
	bool ReadStations(std::map<int, HWStation> &stationsMap);
	bool ReadSegments(std::map<int, HWSegment> &segmentsMap);


};

