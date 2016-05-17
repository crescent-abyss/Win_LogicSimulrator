
// Win_LogicSimulatorView.cpp : CWin_LogicSimulatorView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWin_LogicSimulatorView ����/�Ҹ�

CWin_LogicSimulatorView::CWin_LogicSimulatorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWin_LogicSimulatorView::~CWin_LogicSimulatorView()
{
}

BOOL CWin_LogicSimulatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWin_LogicSimulatorView �׸���

void CWin_LogicSimulatorView::OnDraw(CDC* pDC)
{
	CWin_LogicSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWin_LogicSimulatorView �μ�

BOOL CWin_LogicSimulatorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWin_LogicSimulatorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWin_LogicSimulatorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CWin_LogicSimulatorView ����

#ifdef _DEBUG
void CWin_LogicSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void CWin_LogicSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin_LogicSimulatorDoc* CWin_LogicSimulatorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin_LogicSimulatorDoc)));
	return (CWin_LogicSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG


// CWin_LogicSimulatorView �޽��� ó����
