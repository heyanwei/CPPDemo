#pragma once

#include <string>

namespace route {
	class HWStation
	{
	public:
		HWStation();
		~HWStation();

	public:
		int stationID;
		int pointID;
		std::string type;
		int sysMode;
		int carrierTypes;
	};
}


