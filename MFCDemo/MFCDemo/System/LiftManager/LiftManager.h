#pragma once

#include "model/LiftModel.h"

namespace lift {
	class LiftManager
	{
	public:
		static LiftManager& Instance();
	
	private:
		LiftManager();
		~LiftManager();
	};
}


