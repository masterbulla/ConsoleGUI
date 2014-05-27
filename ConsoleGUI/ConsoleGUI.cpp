
// ConsoleGUI.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ConsoleGUI.h"
#include "ConsoleGUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConsoleGUIApp

BEGIN_MESSAGE_MAP(CConsoleGUIApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CConsoleGUIApp construction

CConsoleGUIApp::CConsoleGUIApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_bConsoleMode = FALSE;
}


// The one and only CConsoleGUIApp object

CConsoleGUIApp theApp;


// CConsoleGUIApp initialization

BOOL CConsoleGUIApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LPWSTR *szArglist;
	int nArgs;

	szArglist = CommandLineToArgvW (GetCommandLineW(), &nArgs);
	if (szArglist != NULL) {
		if (nArgs == 1) {
			CString strFilePath;
			GetModuleFileName (m_hInstance,  strFilePath.GetBuffer (MAX_PATH), MAX_PATH);
			strFilePath.ReleaseBuffer ();
			strFilePath += _T(" /gui{80F0C7CB-6A50-4441-9985-5A0F4181C1C1}");
			STARTUPINFO startInfo = {0};
			PROCESS_INFORMATION processInfo = {0};

			startInfo.cb = sizeof(STARTUPINFO);

			// relaunch myself in GUI mode
			::CreateProcess (NULL, (LPTSTR)(LPCTSTR)strFilePath, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startInfo, &processInfo);
			return FALSE;
		} else {
			if (nArgs == 2 && wcscmp (szArglist[1], L"/gui{80F0C7CB-6A50-4441-9985-5A0F4181C1C1}") == 0) {
				::ShowWindow (GetConsoleWindow (), SW_HIDE);
			} else {
				m_bConsoleMode = TRUE;
				ProcessCommandLine (nArgs, szArglist);
				LocalFree (szArglist);
				return FALSE;
			}
		}

		LocalFree (szArglist);
	}	

	m_bConsoleMode = TRUE;

	CConsoleGUIDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


void CConsoleGUIApp::ProcessCommandLine (int argc, LPWSTR *argv)
{
}