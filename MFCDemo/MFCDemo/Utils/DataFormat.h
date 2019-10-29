#pragma once

#include <string>

namespace hyw {
	namespace utils {
		//CString 转换成unsigned short类型//
		unsigned short CStringToUnShort(CString str);

		//CString 转换成std::string类型//
		std::string CStringTostring(CString str);

		//CString 转换成char[]类型//
		char* CStringToChars(CString str);
	}
}
