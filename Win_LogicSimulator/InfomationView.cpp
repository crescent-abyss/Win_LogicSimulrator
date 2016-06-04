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
	if (test ==1)
	DrawOption();
}


// InfomationView 진단입니다.


void InfomationView::DrawOption()
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.	
	CButton * radioButtonZero;
	CButton * radioButtonOne;
	radioButtonZero = new CButton();
	radioButtonOne = new CButton();

	radioButtonZero->Create(_T("0"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(30, 55, 55, 70), this, 300);
	radioButtonOne->Create(_T("1"), BS_AUTORADIOBUTTON, CRect(80, 55, 105, 70), this, 301);
	radioButtonZero->ShowWindow(SW_SHOW);
	radioButtonOne->ShowWindow(SW_SHOW);

	CButton * Clock1;
	CButton * Clock10;
	CButton * Clock50;

	Clock1 = new CButton();
	Clock10 = new CButton();
	Clock50 = new CButton();

	Clock1->Create(_T("1Hz"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(50, 55, 75, 90), this, 302);		//인포메이션 뷰에 만들자 넘버링 1 부터 ++
	Clock10->Create(_T("10Hz"), BS_AUTORADIOBUTTON, CRect(75, 55, 95, 90), this, 303);
	Clock50->Create(_T("50Hz"), BS_AUTORADIOBUTTON, CRect(100, 55, 120, 90), this, 304);
	Clock1->ShowWindow(SW_SHOW);
	Clock10->ShowWindow(SW_SHOW);
	Clock50->ShowWindow(SW_SHOW);
	test = 0;
}
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
