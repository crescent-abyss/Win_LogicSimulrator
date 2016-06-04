
// MainFrm.cpp : CMainFrame 클래스의 구현
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
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
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
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	
	m_wndSplitter.CreateStatic(this, 2, 1);

	// m_wndSplitter 에서 첫번째 행(0)과 첫번째 열(0)에 해당하는 창을
	// Main_Splitter 로 한 개의 열과 2개의 열로 나눔.
	m_wndSplitter.IdFromRowCol(0, 0);
	Main_Splitter.CreateStatic(&m_wndSplitter, 1, 2);

	// m_wndSplitter 의 첫번째 행의 높이를 정함.	
	m_wndSplitter.SetRowInfo(0, 500, 500);
	//m_wndSplitterMain.SetRowInfo(1, 100, 100);

	// Main_Splitter 의 첫번째 열의 너비를 정함.
	Main_Splitter.SetColumnInfo(0, 200, 200);
	//m_wndSplitterSub.SetColumnInfo(1, 100, 100);

	// 미리 정의해 놓은 class 를 분할된 영역에 생성함. 크기를 지정할 수 있다.
	// m_wndSplitter 의 두번째 행과 첫번째 열에 해당하는 창.
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(InfomationView), CSize(0, 0), pContext);			// 상태 정보창

	// Main_Splitter 의 첫번째 행과 첫번째 열에 해당하는 창.
	Main_Splitter.CreateView(0, 0, RUNTIME_CLASS(TreeView), CSize(200, 0), pContext);						// 트리 리스트창

	// Main_Splitter 의 첫번째 행과 두번째 열에 해당하는 창.
	Main_Splitter.CreateView(0, 1, RUNTIME_CLASS(LogicView), CSize(0, 0), pContext);						// 로직 뷰

	return TRUE;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

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


// CMainFrame 메시지 처리기
