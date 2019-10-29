#include "stdafx.h"
#include "DataFormat.h"

namespace hyw {
	namespace utils {

		unsigned short CStringToUnShort(CString str)
		{
			return _ttoi(str);
		}

		std::string CStringTostring(CString str)
		{
			std::string s = CT2A(str.GetBuffer());
			str.ReleaseBuffer();
			return s;
		}

		char * CStringToChars(CString str)
		{
			USES_CONVERSION;
			char *cs = T2A(str);
			return cs;
		}
	}
}