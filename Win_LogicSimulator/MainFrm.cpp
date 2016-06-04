
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"

#include "MainFrm.h"
#include "Win_LogicSimulatorDoc.h"
#include "Win_LogicSimulatorView.h"
#include "ListView.h"
#include "TreeView.h"
#include "LogicView.h"
#include "InfomationView.h"
//#include "ListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	
	m_wndSplitter.CreateStatic(this, 2, 1);

	// m_wndSplitter ���� ù��° ��(0)�� ù��° ��(0)�� �ش��ϴ� â��
	// Main_Splitter �� �� ���� ���� 2���� ���� ����.
	m_wndSplitter.IdFromRowCol(0, 0);
	Main_Splitter.CreateStatic(&m_wndSplitter, 1, 2);

	// m_wndSplitter �� ù��° ���� ���̸� ����.	
	m_wndSplitter.SetRowInfo(0, 500, 500);
	//m_wndSplitterMain.SetRowInfo(1, 100, 100);

	// Main_Splitter �� ù��° ���� �ʺ� ����.
	Main_Splitter.SetColumnInfo(0, 200, 200);
	//m_wndSplitterSub.SetColumnInfo(1, 100, 100);

	// �̸� ������ ���� class �� ���ҵ� ������ ������. ũ�⸦ ������ �� �ִ�.
	// m_wndSplitter �� �ι�° ��� ù��° ���� �ش��ϴ� â.
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(InfomationView), CSize(0, 0), pContext);			// ���� ����â

	// Main_Splitter �� ù��° ��� ù��° ���� �ش��ϴ� â.
	Main_Splitter.CreateView(0, 0, RUNTIME_CLASS(TreeView), CSize(200, 0), pContext);						// Ʈ�� ����Ʈâ

	// Main_Splitter �� ù��° ��� �ι�° ���� �ش��ϴ� â.
	Main_Splitter.CreateView(0, 1, RUNTIME_CLASS(LogicView), CSize(0, 0), pContext);						// ���� ��

	return TRUE;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����
