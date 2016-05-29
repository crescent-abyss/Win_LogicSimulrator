// InfomationView.cpp : 구현 파일입니다.
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


// InfomationView 그리기입니다.

void InfomationView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.	
}


// InfomationView 진단입니다.

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
