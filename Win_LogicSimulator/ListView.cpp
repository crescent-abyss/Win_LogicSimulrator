\=
// ListView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "ListView.h"


// ListView

IMPLEMENT_DYNCREATE(ListView, CView)

ListView::ListView()
{
	// 리스트 초기화 
	
}

ListView::~ListView()
{
	delete pButton;
}


BEGIN_MESSAGE_MAP(ListView, CView)
END_MESSAGE_MAP()


// ListView 그리기입니다.


void ListView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	//TODO : Add your specialized code here
	pButton = new CButton();
	pButton2 = new CButton();
	pButton->Create(_T("AND 게이트"), BS_DEFPUSHBUTTON, CRect(0, 0, 200, 50), this, 100);
	pButton2->Create(_T("OR 게이트"), BS_DEFPUSHBUTTON, CRect(0, 50, 200, 100), this, 100);
}


void ListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: 여기에 그리기 코드를 추가합니다.
	pButton->ShowWindow(SW_SHOW);
	pButton2->ShowWindow(SW_SHOW);
	

}

BOOL ListView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 100){
		CString str;
		str.Format(_T("AND 게이트"));
		AfxMessageBox(str);
	}
	else if (wParam >= 101){
		CString str;
		str.Format(_T("Test 버튼 2"));
		AfxMessageBox(str);
	}

	return CView::OnCommand(wParam, lParam);
}

// ListView 진단입니다.

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


// ListView 메시지 처리기입니다.
