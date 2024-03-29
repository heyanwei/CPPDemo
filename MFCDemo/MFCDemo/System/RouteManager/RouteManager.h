#pragma once

#include <map>

#include "file/RouteFile.h"
#include "object/AdjacencyMatrix.h"

namespace route {
	class RouteManager
	{
	public:
		static RouteManager& Instance();

		//加载地图//
		bool LoadMap();

		//获取点列表//
		std::list<HWPoint> GetPointsList() { return _pointsList; };

		//获取段列表//
		std::list<HWSegment> GetSegmentsList() { return _segmentList; };

		//获取站台列表//
		std::list<HWStation> GetStationsList() { return _stationList; };

		//搜索点到点的路径//
		bool SearchPathPntToPnt(int start, int end, int& weight,
			int& length, std::list<int>& segList);

		//搜索点到所有点的权重//
		bool GetAllWeightByPoint(int pointID);

		//获取点到点的权重//
		bool GetWeight(int start, int end, int& weight);

		//查看点是否在邻接矩阵中//
		bool IsPointInMatrix(int point);

	private:
		RouteManager();
		~RouteManager();

		//建立邻接矩阵//
		bool BuildAdjacencyMatrix();
		//迪杰斯特拉算法//
		bool Dijkstra(int startPnt, std::map<int, int>& distanceMap,
			std::map<int, AdjacencyMatrix>& pMap);

		std::shared_ptr<RouteFile> _routeFile;

		std::list<HWPoint> _pointsList;
		std::list<HWSegment> _segmentList;
		std::list<HWStation> _stationList;

		//邻接矩阵//
		std::map<int, std::map<int, std::shared_ptr<AdjacencyMatrix>>> _adjMatrix;
	};
}



