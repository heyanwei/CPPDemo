#pragma once

#include "mysql.hpp"
#include "dbng.hpp"
#include "connection_pool.hpp"
#include "ormpp_cfg.hpp"

class SQLUtils
{
public:
	static SQLUtils& Instance();

	bool Init();

private:
	SQLUtils();
	~SQLUtils();
};

