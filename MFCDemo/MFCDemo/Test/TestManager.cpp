#include "stdafx.h"

#include <map>

#include "TestManager.h"
#include "Singleton/SingletonCT.h"
#include "System/RouteManager/model/StationModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TestManager::TestManager()
{
	_dataFormat = std::make_shared<TestDataFormat>();

	//启动时就开始测试//
	TestInStart();

	route::StationModel db;
	db.CreateStationTable();
	db.AddStation();
	db.GetStation();
	db.GetStations();
}


TestManager::~TestManager()
{
}

void TestManager::TestInStart()
{
	//测试这种写法的单例模式会不会多次多CT初始化，结果不会//
	SingletonCT &ct1 = SingletonCT::Instance();
	ct1.Test();

	SingletonCT &ct2 = SingletonCT::Instance();
	ct2.Test();

}
