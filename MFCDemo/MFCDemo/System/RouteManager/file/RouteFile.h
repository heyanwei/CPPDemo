#pragma once

#include "../object/HWPoint.h"
#include "../object/HWSegment.h"
#include "../object/HWStation.h"

#include <list>
#include <memory>

namespace route {
	class RouteFile
	{
	public:
		RouteFile();
		~RouteFile();

		bool ReadPoints(std::list<HWPoint>& pointsMap);
		bool ReadStations(std::list<HWStation>& stationsMap);
		bool ReadSegments(std::list<HWSegment>& segmentsMap);


	};
}


