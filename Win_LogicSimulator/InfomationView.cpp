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
	if (test ==1)
	DrawOption();
}


// InfomationView �����Դϴ�.


void InfomationView::DrawOption()
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.	
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

	Clock1->Create(_T("1Hz"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(50, 55, 75, 90), this, 302);		//�������̼� �信 ������ �ѹ��� 1 ���� ++
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
