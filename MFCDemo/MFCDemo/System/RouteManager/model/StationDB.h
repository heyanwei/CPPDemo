#pragma once

#include "Utils/SQL/SQLUtils.h"

struct tb_user {
	int id;
	std::string user_name;
	int age;
};
REFLECTION(tb_user, id, user_name, age)

class StationDB
{
public:
	void GetStation();

	void GetStations();

	bool AddStation();

	bool DeleteStation();

	bool UpdateStation();


};

