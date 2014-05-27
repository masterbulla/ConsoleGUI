
// ConsoleGUI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CConsoleGUIApp:
// See ConsoleGUI.cpp for the implementation of this class
//

class CConsoleGUIApp : public CWinAppEx
{
public:
	CConsoleGUIApp();

public:
	void ProcessCommandLine (int argc, LPWSTR *argv);

public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bConsoleMode;
};

extern CConsoleGUIApp theApp;