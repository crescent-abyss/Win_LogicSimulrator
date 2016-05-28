// LogicView.cpp : 구현 파일입니다.
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


// LogicView 그리기입니다.

void LogicView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	// TODO: 여기에 그리기 코드를 추가합니다.
	
}

void LogicView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON && listvalue == 0) {						// 마우스 이동시  그림 위치 변경 

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


		// 이동
		PositionInfoX[current] += point.x - startx;
		PositionInfoY[current] += point.y - starty;

		
		startx = point.x;
		starty = point.y;
	
		pOldBmp = pDC->SelectObject(&bmp);
		pDC->BitBlt(point.x, point.y, point.x + bmpInfo.bmWidth, point.y + bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		pDC->TextOutW(point.x + 50, point.y + 150, _T("And게이트"));
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
	else if (nFlags & MK_RBUTTON){					// 마우스 동시에 눌러야 취소됨
		listvalue = 0;

	}
	else if(listvalue > 99 && listvalue < 210){											//게이트 그리기
		CDC* pDC = GetDC();
		CString name;
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		MemDC.CreateCompatibleDC(pDC);
		
		switch (listvalue) {
		case 100:
			bmp.LoadBitmapW(IDB_BITMAP1);
			name = _T("AND게이트");
			break;
		case 101:
			bmp.LoadBitmapW(IDB_BITMAP2);
			name = _T("OR게이트");
			break;
		case 102:
			bmp.LoadBitmapW(IDB_BITMAP3);
			name = _T("NOT게이트");
			break;
		case 103:
			bmp.LoadBitmapW(IDB_BITMAP4);
			name = _T("NAND게이트");
			break;
		case 104:
			bmp.LoadBitmapW(IDB_BITMAP5);
			name = _T("NOR게이트");
			break;
		case 105:
			bmp.LoadBitmapW(IDB_BITMAP6);
			name = _T("XOR게이트");
			break;
		case 200:
			bmp.LoadBitmapW(IDB_BITMAP7);
			name = _T("D플립플롭");
			break;
		case 201:
			bmp.LoadBitmapW(IDB_BITMAP8);
			name = _T("JK플립플롭");
			break;
		case 202:
			bmp.LoadBitmapW(IDB_BITMAP9);
			name = _T("T플립플롭");
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
	if (nFlags & MK_RBUTTON) {               //마우스 오른쪽 버튼 -> 그리기 그만
		listvalue = 0;
	}
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
