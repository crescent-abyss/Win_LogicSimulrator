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
	delete pButton;
}


BEGIN_MESSAGE_MAP(ListView, CView)
END_MESSAGE_MAP()


// ListView �׸����Դϴ�.


void ListView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	//TODO : Add your specialized code here
	pButton = new CButton();
	pButton2 = new CButton();
	pButton->Create(_T("AND ����Ʈ"), BS_DEFPUSHBUTTON, CRect(0, 0, 200, 50), this, 100);
	pButton2->Create(_T("OR ����Ʈ"), BS_DEFPUSHBUTTON, CRect(0, 50, 200, 100), this, 100);
}


void ListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	pButton->ShowWindow(SW_SHOW);
	pButton2->ShowWindow(SW_SHOW);
	

}

BOOL ListView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 100){
		CString str;
		str.Format(_T("AND ����Ʈ"));
		AfxMessageBox(str);
	}
	else if (wParam >= 101){
		CString str;
		str.Format(_T("Test ��ư 2"));
		AfxMessageBox(str);
	}

	return CView::OnCommand(wParam, lParam);
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
