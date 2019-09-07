#pragma once

#include "file/RouteFile.h"
#include "object/AdjacencyMatrix.h"

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

	//建立邻接矩阵//
	bool BuildAdjacencyMatrix();

	std::shared_ptr<RouteFile> _routeFile;

	std::map<int, HWPoint> _pointsMap;
	std::map<int, HWSegment> _segmentMap;
	std::map<int, HWStation> _stationMap;

	//邻接矩阵//
	std::map<int, std::map<int, std::shared_ptr<AdjacencyMatrix>>> _adjMatrix;
};

