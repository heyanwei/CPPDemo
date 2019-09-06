#include "stdafx.h"
#include "TestManager.h"
#include "Singleton/SingletonCT.h"

TestManager::TestManager()
{
	_dataFormat = std::make_shared<TestDataFormat>();

	//启动时就开始测试//
	TestInStart();
}


TestManager::~TestManager()
{
}

void TestManager::TestInStart()
{
	SingletonCT &ct1 = SingletonCT::Instance();
	ct1.Test();

	SingletonCT &ct2 = SingletonCT::Instance();
	ct2.Test();

}
