#include "stdafx.h"

#include <map>

#include "TestManager.h"
#include "Singleton/SingletonCT.h"

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

}
