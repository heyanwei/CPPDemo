#include "stdafx.h"
#include "TestDataFormat.h"

#include "Utils/DataFormat.h"

TestDataFormat::TestDataFormat()
{
}


TestDataFormat::~TestDataFormat()
{
}

void TestDataFormat::CStringToUShort()
{
	//���ȫ�����ַ����ͣ��᷵��0//
	CString str = _T("���");
	unsigned short k = hyw::utils::CStringToUnShort(str);
	TRACE("%d ======\n", (int)k);

	//����������������ַ�����ô������ǰ������֣���123//
	str = _T("123���333");
	k = hyw::utils::CStringToUnShort(str);
	TRACE("%d ======\n", (int)k);

	//���ȫ�������֣���ô�������֣���3215//
	str = _T("3215");
	k = hyw::utils::CStringToUnShort(str);
	TRACE("%d ======\n", (int)k);
}

void TestDataFormat::CStringTostring()
{
	CString str = _T("asda");
	std::string s = hyw::utils::CStringTostring(str);
	TRACE("%s ======\n", s);
}
