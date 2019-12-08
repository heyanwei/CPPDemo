#include "stdafx.h"
#include "LiftManager.h"

namespace lift {

	LiftManager& LiftManager::Instance()
	{
		static LiftManager theCT;
		return theCT;
	}

	LiftManager::LiftManager()
	{
	}

	LiftManager::~LiftManager()
	{
	}

}