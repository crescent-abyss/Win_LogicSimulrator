
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
	delete pButton2;
}


BEGIN_MESSAGE_MAP(ListView, CView)
END_MESSAGE_MAP()


// ListView �׸����Դϴ�.


void ListView::OnInitialUpdate()					// ��ư ����
{
	CView::OnInitialUpdate();

	
	//TODO : Add your specialized code here
	
	pButton = new CButton();
	pButton2 = new CButton();
	pTitle = new CButton();

	pTitle->Create(_T("����Ʈ"), BS_DEFPUSHBUTTON, CRect(0, 0, 200, 50), this, 99);
	pButton->Create(_T("AND ����Ʈ"), BS_DEFPUSHBUTTON, CRect(0, 50, 200, 100), this, 100);
	pButton2->Create(_T("OR ����Ʈ"), BS_DEFPUSHBUTTON, CRect(0, 100, 200, 150), this, 101);
}


void ListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	pTitle->ShowWindow(SW_SHOW);
	//pButton->ShowWindow(SW_SHOW);
	//pButton2->ShowWindow(SW_SHOW);
	

}

BOOL ListView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 99){								// ����Ʈ Ŭ���� �޴� ����
		
		if (Flag == TRUE){
			pButton->ShowWindow(SW_SHOW);
			pButton2->ShowWindow(SW_SHOW);
			Flag = FALSE;
		}
		else{
			pButton->ShowWindow(SW_HIDE);
			pButton2->ShowWindow(SW_HIDE);
			Flag = TRUE;
		}
	}
	else if (wParam == 100){						// AND ����Ʈ Ŭ����
		CString str;
		str.Format(_T("AND ����Ʈ"));
		AfxMessageBox(str);
	}
	else if(wParam == 101){							// OR ����Ʈ Ŭ����
		CString str;
		str.Format(_T("OR ����Ʈ"));
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
