#include "stdafx.h"
#include "SQLUtils.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SQLUtils::SQLUtils()
{

}

SQLUtils::~SQLUtils()
{

}

bool SQLUtils::Init()
{
	ormpp::ormpp_cfg cfg{};
	bool ret = ormpp::config_manager::from_file(cfg, "./config/ormpp.cfg");
	if (!ret)
	{
		return false;
	}
	auto& pool = ormpp::connection_pool<ormpp::dbng<ormpp::mysql>>::instance();
	try
	{
		pool.init(cfg.db_conn_num, cfg.db_ip.data(),
			cfg.user_name.data(), cfg.pwd.data(),
			cfg.db_name.data(), cfg.timeout);
	}
	catch (const std::exception & e)
	{
		TRACE(L"连接池初始化失败...%s\n", e.what());
		return false;
	}
	return true;
}

SQLUtils& SQLUtils::Instance()
{
	static SQLUtils theCT;
	return theCT;
}