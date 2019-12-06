
// MFCDemo.cpp: 定义应用程序的类行为。
//

#include "stdafx.h"
#include "MFCDemo.h"
#include "MFCDemoDlg.h"

#include "Utils/Log/easylogging++.h"

#include "Utils/SQL/SQLUtils.h"
#include "Version.h"

INITIALIZE_EASYLOGGINGPP

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoApp

BEGIN_MESSAGE_MAP(CMFCDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCDemoApp 构造

CMFCDemoApp::CMFCDemoApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CMFCDemoApp 对象

CMFCDemoApp theApp;


// CMFCDemoApp 初始化

BOOL CMFCDemoApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	//可限制用户打开多个该程序//
	HANDLE appInstance;
	appInstance = ::CreateMutex(NULL, FALSE, HW_SYSTEM_NAME);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		if (appInstance)
		{
			CloseHandle(appInstance);
		}	
		AfxMessageBox(_T("软件已启动"));
		return FALSE;
	}

	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
		"%datetime|%level: %msg [%fbase %line]");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "Log\\_%datetime{%Y%M%d}.log");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "2097152");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::PerformanceTracking, "false");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");

	el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
	el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

	el::Helpers::installPreRollOutCallback(RollbackHandle);

	LOG(INFO) << "==============================";
	LOG(INFO) << "==============================";
	LOG(INFO) << "===== "<< HW_SYSTEM_NAME<<"已启动 " << HW_VERSION_NUMBER << "=====";
	LOG(INFO) << "===更新时间：" << HW_UPDATE_TIME << "==";
	LOG(INFO) << "==============================";
	LOG(INFO) << "==============================";
	LOG(INFO) << "==============================";

	SQLUtils& sqlUtils = SQLUtils::Instance();
	if (!sqlUtils.Init())
	{
		LOG(ERROR) << "系统启动失败：数据库初始化失败";
		AfxMessageBox(_T("数据库初始化失败"));
		return FALSE;
	}

	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMFCDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		LOG(INFO) << "==============系统正常结束";
	}
	else if (nResponse == IDCANCEL)
	{
		LOG(INFO) << "==============系统取消结束";
	}
	else if (nResponse == -1)
	{
		LOG(ERROR) << "==============系统异常结束";
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

