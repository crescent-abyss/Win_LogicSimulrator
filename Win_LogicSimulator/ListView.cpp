\=
// ListView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "ListView.h"


// ListView

IMPLEMENT_DYNCREATE(ListView, CView)

ListView::ListView()
{
	// ����Ʈ �ʱ�ȭ 
	
}

ListView::~ListView()
{
}

BEGIN_MESSAGE_MAP(ListView, CView)
END_MESSAGE_MAP()


// ListView �׸����Դϴ�.

void ListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(100, 10, _T("AND ����Ʈ"));
	pDC->TextOutW(100, 30, _T(" OR ����Ʈ"));
	

}


// ListView �����Դϴ�.

#ifdef _DEBUG
void ListView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void ListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// ListView �޽��� ó�����Դϴ�.
