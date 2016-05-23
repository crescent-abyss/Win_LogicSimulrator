// LogicView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "LogicView.h"


// LogicView

IMPLEMENT_DYNCREATE(LogicView, CView)

LogicView::LogicView()
{

}

LogicView::~LogicView()
{
}

BEGIN_MESSAGE_MAP(LogicView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// LogicView 그리기입니다.

void LogicView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	

	// TODO: 여기에 그리기 코드를 추가합니다.
	
}


void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
		// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON && listvalue == 100){
		CDC* pDC = GetDC();
		pDC->Rectangle(point.x, point.y, point.x + 50, point.y + 50);
		ReleaseDC(pDC);
	}
	else if(nFlags & MK_LBUTTON && listvalue == 101){
		CDC* pDC = GetDC();
		pDC->Rectangle(point.x, point.y, point.x + 20, point.y + 20);
		ReleaseDC(pDC);
	}
	CView::OnLButtonDown(nFlags, point);
}


// LogicView 진단입니다.

#ifdef _DEBUG
void LogicView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void LogicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// LogicView 메시지 처리기입니다.
