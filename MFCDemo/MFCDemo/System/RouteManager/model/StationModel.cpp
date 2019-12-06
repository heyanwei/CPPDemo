#include "stdafx.h"
#include "StationModel.h"

#include <string_view>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace route {
	void StationModel::CreateStationTable()
	{
		auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
		auto conn = pool.get();

		ormpp_key priKey{
			"stationID"
		};
		ormpp_not_null notNullKey{
			{
				"pointID"
			}
		};
		ormpp_unique uinqueKey{
			"stationID"
		};
		//ormpp_auto_key auto_key{ "pointID" };

		if (!conn->create_datatable<tb_station>(priKey, notNullKey, uinqueKey))
		{
			TRACE(L"创建Station失败...\n");
			return;
		}
		TRACE(L"创建Station成功...\n");
	}

	void StationModel::GetStation()
	{
		auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
		auto conn = pool.get();

		auto stations = conn->query<tb_station>("select * from tb_station where stationID=1");
		for (auto stn : stations)
		{
			TRACE(L"输出查询结果：%d\n", stn.stationID);
		}

	}

	void StationModel::GetStations()
	{
		auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
		auto conn = pool.get();

		auto res = conn->query<tb_station>();
		TRACE(L"输出查询结果：%d\n", res.size());
	}

	bool StationModel::AddStation()
	{
		tb_station stn;
		stn.stationID = 1;

		auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
		auto conn = pool.get();
		if (!conn->insert(stn))
		{
			return false;
		}
		return true;
	}

	bool StationModel::AddStations()
	{
		/*
		TEST_REQUIRE(mysql.begin());
		for (int i = 0; i < 10; ++i) {
			student s = {i, "tom", 0, 19, 1.5, "room2"};
			if(!mysql.insert(s)){
				mysql.rollback();
				return;
			}
		}
		TEST_REQUIRE(mysql.commit());
		*/
		return false;
	}

}
