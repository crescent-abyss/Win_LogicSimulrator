// LogicView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "LogicView.h"
#include "TreeView.h"


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
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// LogicView �׸����Դϴ�.

void LogicView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	
}


void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
		// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON && listvalue == 0){
		
	}
	else if (nFlags & MK_RBUTTON){					// ���콺 ���ÿ� ������ ��ҵ�
		listvalue = 0;

	}
	else {											//����Ʈ �׸���
		CDC* pDC = GetDC();
		CString name;
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		MemDC.CreateCompatibleDC(pDC);
		
		switch (listvalue) {
		case 100:
			bmp.LoadBitmapW(IDB_BITMAP1);
			name = _T("AND����Ʈ");
			break;
		case 101:
			bmp.LoadBitmapW(IDB_BITMAP2);
			name = _T("OR����Ʈ");
			break;
		case 102:
			bmp.LoadBitmapW(IDB_BITMAP3);
			name = _T("NOT����Ʈ");
			break;
		case 103:
			bmp.LoadBitmapW(IDB_BITMAP4);
			name = _T("NAND����Ʈ");
		}

		bmp.GetBitmap(&bmpInfo);
		CBitmap *pOldBmp = (CBitmap *)MemDC.SelectObject(&bmp);
		pOldBmp = pDC->SelectObject(&bmp);
		pDC->BitBlt(point.x, point.y, point.x + bmpInfo.bmWidth, point.y + bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		pDC->TextOutW(point.x + 50, point.y + 150, name);

		PositionInfoX[i] = point.x;
		PositionInfoY[i] = point.y;
		i = i++;

		MemDC.SelectObject(pOldBmp);

		ReleaseDC(pDC);
	}
	
	CView::OnLButtonDown(nFlags, point);
}


// LogicView �����Դϴ�.

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


// LogicView �޽��� ó�����Դϴ�.