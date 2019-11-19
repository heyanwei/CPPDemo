#pragma once

#include <string>

namespace hyw {
	namespace utils {
		//CString ת����unsigned short����//
		unsigned short CStringToUnShort(CString str);

		//CString ת����int����//
		int CStringToInt(CString str);

		//int ת����CString����//
		CString IntToCString(int value);

		//CString ת����std::string����//
		std::string CStringTostring(CString str);

		//CString ת����char[]����//
		char* CStringToChars(CString str);
	}
}
