﻿
// MFCDemo.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMFCDemoApp:
// 有关此类的实现，请参阅 MFCDemo.cpp
//

class CMFCDemoApp : public CWinApp
{
public:
	CMFCDemoApp();

private:
	static void RollbackHandle(const char* filename, std::size_t size) {};

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCDemoApp theApp;
