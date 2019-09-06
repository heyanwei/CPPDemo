#pragma once

#include "file/RouteFile.h"

class RouteManager
{
public:
	static RouteManager& Instance();

	//���ص�ͼ//
	bool LoadMap();

	//��ȡ���б�//
	std::map<int, HWPoint> GetPointsMap() { return _pointsMap; };

	//��ȡ���б�//
	std::map<int, HWSegment> GetSegmentsMap() { return _segmentMap; };

	//��ȡվ̨�б�//
	std::map<int, HWStation> GetStationsMap() { return _stationMap; };

private:
	RouteManager();
	~RouteManager();

	std::shared_ptr<RouteFile> _routeFile;

	std::map<int, HWPoint> _pointsMap;
	std::map<int, HWSegment> _segmentMap;
	std::map<int, HWStation> _stationMap;
};

