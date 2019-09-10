#pragma once

#include <map>

#include "file/RouteFile.h"
#include "object/AdjacencyMatrix.h"

class RouteManager
{
public:
	static RouteManager& Instance();

	//���ص�ͼ//
	bool LoadMap();

	//��ȡ���б�//
	std::list<HWPoint> GetPointsList() { return _pointsList; };

	//��ȡ���б�//
	std::list<HWSegment> GetSegmentsList() { return _segmentList; };

	//��ȡվ̨�б�//
	std::list<HWStation> GetStationsList() { return _stationList; };

	//�����㵽���·��//
	bool SearchPathPntToPnt(int start, int end, int &weight, 
		int &length, std::list<int> &segList);

private:
	RouteManager();
	~RouteManager();

	//�����ڽӾ���//
	bool BuildAdjacencyMatrix();
	//�Ͻ�˹�����㷨//
	bool Dijkstra(int startPnt);

	std::shared_ptr<RouteFile> _routeFile;

	std::list<HWPoint> _pointsList;
	std::list<HWSegment> _segmentList;
	std::list<HWStation> _stationList;

	//�ڽӾ���//
	std::map<int, std::map<int, std::shared_ptr<AdjacencyMatrix>>> _adjMatrix;
};

