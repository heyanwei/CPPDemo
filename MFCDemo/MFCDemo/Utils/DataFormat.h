#pragma once

#include <string>

namespace hyw {
	namespace utils {
		//CString ת����unsigned short����//
		unsigned short CStringToUnShort(CString str);

		//CString ת����std::string����//
		std::string CStringTostring(CString str);

		//CString ת����char[]����//
		char* CStringToChars(CString str);
	}
}
