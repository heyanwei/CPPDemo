#pragma once

#include "Utils/SQL/SQLUtils.h"

struct tb_station {
	int stationID;
	int pointID;
	std::string type;
	int sysMode;
	int carrierTypes;

	tb_station()
	{
		stationID = 0;
		pointID = 0;
		type = "";
		sysMode = 0;
		carrierTypes = 0;
	}
};
REFLECTION(tb_station, stationID, pointID, type, sysMode, carrierTypes)

class StationModel
{
public:
	void CreateStationTable();

	void GetStation();

	void GetStations();

	bool AddStation();

	bool AddStations();

	bool DeleteStation();

	bool UpdateStation();


};

