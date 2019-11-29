#include "stdafx.h"
#include "StationDB.h"

void StationDB::GetStation()
{
	auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
	auto conn1 = pool.get();
	auto res = conn1->query<tb_user>();
	TRACE(L"输出查询结果：%d\n", res.size());
}

void StationDB::GetStations()
{
	auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
	auto conn1 = pool.get();
	auto res = conn1->query<tb_user>();
	TRACE(L"输出查询结果：%d\n", res.size());
}
