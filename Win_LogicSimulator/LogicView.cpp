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
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// LogicView �׸����Դϴ�.

void LogicView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	
}

void LogicView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags & MK_LBUTTON && listvalue == 0) {						// ���콺 �̵���  �׸� ��ġ ���� 

		CDC* pDC = GetDC();
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SetROP2(R2_NOT);

		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		MemDC.CreateCompatibleDC(pDC);
		bmp.LoadBitmapW(311);
		bmp.GetBitmap(&bmpInfo);
		CBitmap *pOldBmp = (CBitmap *)MemDC.SelectObject(&bmp);
		
		DeleteObject(bmp);


		// �̵�
		PositionInfoX[current] += point.x - startx;
		PositionInfoY[current] += point.y - starty;

		
		startx = point.x;
		starty = point.y;
	
		pOldBmp = pDC->SelectObject(&bmp);
		pDC->BitBlt(point.x, point.y, point.x + bmpInfo.bmWidth, point.y + bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		pDC->TextOutW(point.x + 50, point.y + 150, _T("And����Ʈ"));
		DeleteObject(bmp);


	}

	CWnd::OnMouseMove(nFlags, point);
}




void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
		// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON && listvalue == 0){
		for (int i = 0; i < PositionInfoX[i]; i++) {
			if (PositionInfoX[i] <= point.x && point.x <= PositionInfoX[i] + 50 &&
				PositionInfoY[i] <= point.y && point.y <= PositionInfoY[i] + 50) {
				current = i;
				break;
			}
		}
	}
	else if (nFlags & MK_RBUTTON){					// ���콺 ���ÿ� ������ ��ҵ�
		listvalue = 0;

	}
	else if(listvalue > 99 && listvalue < 210){											//����Ʈ �׸���
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
			break;
		case 104:
			bmp.LoadBitmapW(IDB_BITMAP5);
			name = _T("NOR����Ʈ");
			break;
		case 105:
			bmp.LoadBitmapW(IDB_BITMAP6);
			name = _T("XOR����Ʈ");
			break;
		case 200:
			bmp.LoadBitmapW(IDB_BITMAP7);
			name = _T("D�ø��÷�");
			break;
		case 201:
			bmp.LoadBitmapW(IDB_BITMAP8);
			name = _T("JK�ø��÷�");
			break;
		case 202:
			bmp.LoadBitmapW(IDB_BITMAP9);
			name = _T("T�ø��÷�");
			break;
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
	else if (listvalue == 300) {

	}
	
	CView::OnLButtonDown(nFlags, point);
}

void LogicView::OnRButtonDown(UINT nFlags, CPoint point) {
	if (nFlags & MK_RBUTTON) {               //���콺 ������ ��ư -> �׸��� �׸�
		listvalue = 0;
	}
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
