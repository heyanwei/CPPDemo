#include "stdafx.h"
#include "RouteManager.h"
#include <iostream>
#include <algorithm>
#include <map>

RouteManager::RouteManager()
{
	TRACE("Load Route Manager...\n");

	_routeFile = std::make_shared<RouteFile>();
}


RouteManager::~RouteManager()
{
	TRACE("Exit Route Manager...\n");
}

bool RouteManager::BuildAdjacencyMatrix()
{
	//清除邻接矩阵元素//
	_adjMatrix.clear();
	//初始化邻接矩阵//
	//遍历起点//
	for (auto spnt = _pointsMap.begin(); spnt != _pointsMap.end(); spnt++)
	{
		std::map<int, std::shared_ptr<AdjacencyMatrix>> endMap;
		//遍历终点//
		for (auto epnt = _pointsMap.begin(); epnt != _pointsMap.end(); epnt++)
		{
			std::shared_ptr<AdjacencyMatrix> adj = std::make_shared<AdjacencyMatrix>();
			endMap[epnt->first] = adj;
		}
		_adjMatrix[spnt->first] = endMap;
	}

	//遍历所有的段，如果段的权重小于当前的权重，那么替换掉//
	for (auto segIter = _segmentMap.begin(); segIter != _segmentMap.end(); segIter++)
	{
		int startpnt = segIter->second.startPoint;
		int endpnt = segIter->second.endPoint;

		std::shared_ptr<AdjacencyMatrix> adj = _adjMatrix[startpnt][endpnt];
		if (adj == NULL)
		{
			_adjMatrix.clear();
			return false;
		}

		int segWeight = segIter->second.travelTime + segIter->second.addWeight * 1000;
		if (segWeight < adj->weight)
		{
			adj->segmentID = segIter->second.orgID;
			adj->weight = segWeight;
			adj->length = segIter->second.length;

			_adjMatrix[startpnt][endpnt] = adj;
		}
	}

	TRACE(L"BuildAdjacencyMatrix Success...\n");

	return true;
}

RouteManager & RouteManager::Instance()
{
	static RouteManager theCT;
	return theCT;
}

bool RouteManager::LoadMap()
{
	TRACE("Load Map...\n");
	if (!_routeFile->ReadPoints(_pointsMap))
	{
		TRACE("read points failed...\n");
		return false;
	}
	TRACE("read points success, total: %d\n", _pointsMap.size());

	if (!_routeFile->ReadSegments(_segmentMap))
	{
		TRACE("read segments failed...\n");
		return false;
	}
	TRACE("read segments success, total: %d\n", _segmentMap.size());

	if (!_routeFile->ReadStations(_stationMap))
	{
		TRACE("read stations failed...\n");
		return false;
	}
	TRACE("read stations success, total: %d\n", _stationMap.size());

	if (!BuildAdjacencyMatrix())
	{
		return false;
	}

	return true;
}
