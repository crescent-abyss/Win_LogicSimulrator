// InfomationView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "InfomationView.h"


// InfomationView

IMPLEMENT_DYNCREATE(InfomationView, CView)

InfomationView::InfomationView()
{

}

InfomationView::~InfomationView()
{
}

BEGIN_MESSAGE_MAP(InfomationView, CView)
END_MESSAGE_MAP()


// InfomationView �׸����Դϴ�.

void InfomationView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.	
}


// InfomationView �����Դϴ�.

#ifdef _DEBUG
void InfomationView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void InfomationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG
