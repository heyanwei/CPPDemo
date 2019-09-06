#include "stdafx.h"
#include "DataFormat.h"

namespace hyw {
	namespace utils {
		unsigned short CStringToUnShort(CString str)
		{
			return _ttoi(str);
		}
	}
}