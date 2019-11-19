#include "stdafx.h"
#include "DataFormat.h"

namespace hyw {
	namespace utils {

		unsigned short CStringToUnShort(CString str)
		{
			return _ttoi(str);
		}

		int CStringToInt(CString str)
		{
			return _ttoi(str);
		}

		CString IntToCString(int value)
		{
			CString str;
			str.Format(_T("%d"), value);
			return str;
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