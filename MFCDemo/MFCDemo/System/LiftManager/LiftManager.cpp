#include "stdafx.h"
#include "LiftManager.h"

#include "Utils/Log/easylogging++.h"

namespace lift {

	LiftManager& LiftManager::Instance()
	{
		static LiftManager theCT;
		return theCT;
	}

	bool LiftManager::Init()
	{
		LOG(INFO) << "��ʼ��LiftManager...";


		return false;
	}

	LiftManager::LiftManager()
	{
	}

	LiftManager::~LiftManager()
	{
		LOG(INFO) << "�ͷ�LiftManager...";
	}

}