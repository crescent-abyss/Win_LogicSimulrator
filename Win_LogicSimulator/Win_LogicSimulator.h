
// Win_LogicSimulator.h : Win_LogicSimulator ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWin_LogicSimulatorApp:
// �� Ŭ������ ������ ���ؼ��� Win_LogicSimulator.cpp�� �����Ͻʽÿ�.
//

class CWin_LogicSimulatorApp : public CWinApp
{
public:
	CWin_LogicSimulatorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWin_LogicSimulatorApp theApp;
