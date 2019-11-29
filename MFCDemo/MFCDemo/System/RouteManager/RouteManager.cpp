#include "stdafx.h"
#include "RouteManager.h"
#include <iostream>
#include <algorithm>
#include <map>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool RouteManager::SearchPathPntToPnt(int start, int end, int & weight, int & length, std::list<int>& segList)
{

	return false;
}

bool RouteManager::GetAllWeightByPoint(int pointID)
{
	if (!IsPointInMatrix(pointID))
	{
		return false;
	}

	std::map<int, int> distanceMap;
	std::map<int, AdjacencyMatrix> pMap;

	if (Dijkstra(pointID, distanceMap, pMap))
	{
		return true;
	}
	return false;
}

bool RouteManager::GetWeight(int start, int end, int& weight)
{
	if ((!IsPointInMatrix(start))|| (!IsPointInMatrix(end)))
	{
		return false;
	}

	std::map<int, int> distanceMap;
	std::map<int, AdjacencyMatrix> pMap;

	if (!Dijkstra(start, distanceMap, pMap))
	{
		return false;
	}

	weight = distanceMap[end];

	return true;
}

bool RouteManager::IsPointInMatrix(int point)
{
	for (auto iter = _adjMatrix.begin(); iter != _adjMatrix.end(); iter++)
	{
		if (point == iter->first)
		{
			return true;
		}
	}
	return false;
}

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
	//����ڽӾ���Ԫ��//
	_adjMatrix.clear();
	//��ʼ���ڽӾ���//
	//�������//
	for (auto spnt = _pointsList.begin(); spnt != _pointsList.end(); spnt++)
	{
		std::map<int, std::shared_ptr<AdjacencyMatrix>> endMap;
		//�����յ�//
		for (auto epnt = _pointsList.begin(); epnt != _pointsList.end(); epnt++)
		{
			std::shared_ptr<AdjacencyMatrix> adj = std::make_shared<AdjacencyMatrix>();
			endMap[epnt->orgID] = adj;
		}
		_adjMatrix[spnt->orgID] = endMap;
	}

	//�������еĶΣ�����ε�Ȩ��С�ڵ�ǰ��Ȩ�أ���ô�滻��//
	for (auto segIter = _segmentList.begin(); segIter != _segmentList.end(); segIter++)
	{
		int startpnt = segIter->startPoint;
		int endpnt = segIter->endPoint;

		std::shared_ptr<AdjacencyMatrix> adj = _adjMatrix[startpnt][endpnt];
		if (adj == NULL)
		{
			_adjMatrix.clear();
			return false;
		}

		int segWeight = segIter->travelTime + segIter->addWeight * 1000;
		if (segWeight < adj->weight)
		{
			adj->id = segIter->orgID;
			adj->weight = segWeight;

			_adjMatrix[startpnt][endpnt] = adj;
		}
	}

	TRACE(L"BuildAdjacencyMatrix Success...\n");

	return true;
}

bool RouteManager::Dijkstra(int startPnt, std::map<int, int> &distanceMap, 
	std::map<int, AdjacencyMatrix> &pMap)
{
	//��ʼ����㵽�������ж������СȨ��//
	//std::map<int, int> distanceMap;
	//�Ѿ�����Ķ���ı�־λ//
	std::map<int, bool> flagMap;
	//ǰ������¼����㵽��ǰ�㣬��������һ����ı��//
	//std::map<int, AdjacencyMatrix> pMap;

	for (auto iter = _adjMatrix.begin(); iter != _adjMatrix.end(); iter++)
	{
		std::shared_ptr<AdjacencyMatrix> tmpMatrix = _adjMatrix[startPnt][iter->first];
		if (!tmpMatrix)
		{
			TRACE(L"����Ϊ��...\n");
			return false;
		}
		distanceMap[iter->first] = tmpMatrix->weight;
		flagMap[iter->first] = false;

		AdjacencyMatrix adj;
		if (distanceMap[iter->first] == RouteMaxWeight)
		{
			//Դ�㵽�����·������Ϊ�����˵���������㲻����//
			adj.weight = RouteMaxWeight;
		}
		else
		{
			//����������ڣ����ö����ǰ��ΪԴ��//
			adj.id = _adjMatrix[startPnt][iter->first]->id;
			adj.weight = startPnt;
		}
		pMap[iter->first] = adj;
	}
	//��ʼ��ֻ��һ��Ԫ�أ�������ʼ��
	distanceMap[startPnt] = 0;
	flagMap[startPnt] = true;

	int temp = 0;
	int t = 0;
	for (auto iter = _adjMatrix.begin(); iter != _adjMatrix.end(); iter++)
	{
		temp = RouteMaxWeight;
		t = startPnt;

		for (auto it = _adjMatrix.begin(); it != _adjMatrix.end(); it++)
		{
			if ((!flagMap[it->first]) && (distanceMap[it->first] < temp))
			{
				t = it->first;
				temp = distanceMap[it->first];
			}
		}
		//����Ҳ���t����ô����ѭ��//
		if (t == startPnt)
		{
			return true;
		}
		//���򣬰�t���뼯��
		flagMap[t] = true;

		//���¼���V-S����t�ڽӵĶ��㵽Դ��u�ľ���
		for (auto it = _adjMatrix.begin(); it != _adjMatrix.end(); it++)
		{
			if ((!flagMap[it->first]) && (_adjMatrix[t][it->first]->
				weight < RouteMaxWeight))
			{
				if (distanceMap[it->first] > (distanceMap[t] + _adjMatrix[t][it->first]->weight))
				{
					distanceMap[it->first] = distanceMap[t] + _adjMatrix[t][it->first]->weight;
					pMap[it->first].weight = t;
					pMap[it->first].id = _adjMatrix[t][it->first]->id;
				}
			}
		}

	}

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
	if (!_routeFile->ReadPoints(_pointsList))
	{
		TRACE("read points failed...\n");
		return false;
	}
	TRACE("read points success, total: %d\n", _pointsList.size());

	if (!_routeFile->ReadSegments(_segmentList))
	{
		TRACE("read segments failed...\n");
		return false;
	}
	TRACE("read segments success, total: %d\n", _segmentList.size());

	if (!_routeFile->ReadStations(_stationList))
	{
		TRACE("read stations failed...\n");
		return false;
	}
	TRACE("read stations success, total: %d\n", _stationList.size());

	if (!BuildAdjacencyMatrix())
	{
		return false;
	}

	return true;
}
