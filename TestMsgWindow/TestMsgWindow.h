
// TestMsgWindow.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestMsgWindowApp:
// �йش����ʵ�֣������ TestMsgWindow.cpp
//

class CTestMsgWindowApp : public CWinApp
{
public:
	CTestMsgWindowApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestMsgWindowApp theApp;