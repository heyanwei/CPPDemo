#pragma once

#include <memory>

#include "Utils/TestDataFormat.h"

class TestManager
{
public:
	TestManager();
	~TestManager();

	std::shared_ptr<TestDataFormat> _dataFormat;
};

