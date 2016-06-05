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
	
	ON_WM_PAINT()
END_MESSAGE_MAP()


// InfomationView 그리기입니다.

void InfomationView::OnDraw(CDC* pDC)
{

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


void InfomationView::OnPaint()
{
	if (test == 1){
		CPaintDC dc(this); // device context for painting
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
		//CDocument* pDoc = GetDocument();
		// TODO: 여기에 그리기 코드를 추가합니다.	
		dc.Rectangle(10, 10, 100, 100);
		dc.DrawText(_T("입력단자1"), CRect(20, 20, 50, 50), 300);
		dc.DrawText(_T("on"), CRect(30, 50, 60, 70), 301);
		dc.DrawText(_T("off"), CRect(60, 50, 80, 70), 30);
	}
	else if (test == 2){


	
		/*
		CButton * radioButtonZero;
		CButton * radioButtonOne;
		radioButtonZero = new CButton();
		radioButtonOne = new CButton();
		
		radioButtonZero->Create(_T("0"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(30, 85, 65, 110), this, 300);
		radioButtonOne->Create(_T("1"), BS_AUTORADIOBUTTON, CRect(80, 85, 135, 110), this, 301);
		radioButtonZero->ShowWindow(SW_SHOW);
		radioButtonOne->ShowWindow(SW_SHOW);
		
		CButton * Clock1;
		CButton * Clock10;
		CButton * Clock50;


		Clock1->Create(_T("1Hz"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(50, 55, 85, 90), this, 302);		//인포메이션 뷰에 만들자 넘버링 1 부터 ++
		Clock10->Create(_T("10Hz"), BS_AUTORADIOBUTTON, CRect(95, 55, 145, 90), this, 303);
		Clock50->Create(_T("50Hz"), BS_AUTORADIOBUTTON, CRect(150, 55, 200, 90), this, 304);
		Clock1->ShowWindow(SW_SHOW);
		Clock10->ShowWindow(SW_SHOW);
		Clock50->ShowWindow(SW_SHOW);
		*/
		//test = 0;
	}
}
