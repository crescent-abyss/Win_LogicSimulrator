
// Win_LogicSimulatorView.cpp : CWin_LogicSimulatorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Win_LogicSimulator.h"
#endif

#include "Win_LogicSimulatorDoc.h"
#include "Win_LogicSimulatorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWin_LogicSimulatorView

IMPLEMENT_DYNCREATE(CWin_LogicSimulatorView, CView)

BEGIN_MESSAGE_MAP(CWin_LogicSimulatorView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWin_LogicSimulatorView 생성/소멸

CWin_LogicSimulatorView::CWin_LogicSimulatorView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWin_LogicSimulatorView::~CWin_LogicSimulatorView()
{
}

BOOL CWin_LogicSimulatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWin_LogicSimulatorView 그리기

void CWin_LogicSimulatorView::OnDraw(CDC* pDC)
{
	CWin_LogicSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWin_LogicSimulatorView 인쇄

BOOL CWin_LogicSimulatorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWin_LogicSimulatorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWin_LogicSimulatorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWin_LogicSimulatorView 진단

#ifdef _DEBUG
void CWin_LogicSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void CWin_LogicSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin_LogicSimulatorDoc* CWin_LogicSimulatorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin_LogicSimulatorDoc)));
	return (CWin_LogicSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG


// CWin_LogicSimulatorView 메시지 처리기
