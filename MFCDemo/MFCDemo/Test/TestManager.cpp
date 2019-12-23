#include "stdafx.h"

#include <map>

#include "TestManager.h"
#include "Singleton/SingletonCT.h"
#include "System/RouteManager/model/StationModel.h"
#include "TestClass/ClassInt.h"
#include "Utils/Log/easylogging++.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TestManager::TestManager()
{
	_dataFormat = std::make_shared<TestDataFormat>();

	//����ʱ�Ϳ�ʼ����//
	TestInStart();
}


TestManager::~TestManager()
{
}

void TestManager::TestInStart()
{
	//��������д���ĵ���ģʽ�᲻���ζ�CT��ʼ�����������//
	SingletonCT &ct1 = SingletonCT::Instance();
	ct1.Test();

	SingletonCT &ct2 = SingletonCT::Instance();
	ct2.Test();

	ClassInt cls1(10);
	ClassInt cls2(30);
	ClassInt cls = cls1 + cls2;
	LOG(INFO) << "class int: " << (int)cls;

}
