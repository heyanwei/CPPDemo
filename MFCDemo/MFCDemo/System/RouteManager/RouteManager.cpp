#include "RouteManager.h"
#include <iostream>
#include <algorithm>
#include <map>

RouteManager::RouteManager()
{
	std::cout << "Load Route Manager..." << std::endl;

	_routeFile = std::make_shared<RouteFile>();
}


RouteManager::~RouteManager()
{
	std::cout << "Exit Route Manager..." << std::endl;
}

bool RouteManager::LoadMap()
{
	std::cout << "Load Map..." << std::endl;
	if (!_routeFile->ReadPoints(_pointsMap))
	{
		std::cout << "read points failed..." << std::endl;
		return false;
	}
	std::cout << "read points success, total: "<< _pointsMap.size()
		<< std::endl;

	if (!_routeFile->ReadSegments(_segmentMap))
	{
		std::cout << "read segments failed..." << std::endl;
		return false;
	}
	std::cout << "read segments success, total: " << _segmentMap.size()
		<< std::endl;

	if (!_routeFile->ReadStations(_stationMap))
	{
		std::cout << "read stations failed..." << std::endl;
		return false;
	}
	std::cout << "read stations success, total: " << _stationMap.size()
		<< std::endl;

	return true;
}
