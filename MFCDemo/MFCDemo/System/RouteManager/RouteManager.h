#pragma once

#include "file/RouteFile.h"

class RouteManager
{
public:
	static RouteManager& Instance();

	//加载地图//
	bool LoadMap();

	//获取点列表//
	std::map<int, HWPoint> GetPointsMap() { return _pointsMap; };

	//获取段列表//
	std::map<int, HWSegment> GetSegmentsMap() { return _segmentMap; };

	//获取站台列表//
	std::map<int, HWStation> GetStationsMap() { return _stationMap; };

private:
	RouteManager();
	~RouteManager();

	std::shared_ptr<RouteFile> _routeFile;

	std::map<int, HWPoint> _pointsMap;
	std::map<int, HWSegment> _segmentMap;
	std::map<int, HWStation> _stationMap;
};

