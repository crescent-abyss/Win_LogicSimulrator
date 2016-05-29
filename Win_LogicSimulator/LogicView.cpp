// LogicView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "LogicView.h"
#include "TreeView.h"

CString gate_name[100];
CString name;



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
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONUP()

	ON_WM_PAINT()
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
	if (nFlags & MK_LBUTTON && listvalue == 0) {						

		m_ptBitmapX[current] = point.x;
		m_ptBitmapY[current] = point.y;
		
	}

	CWnd::OnMouseMove(nFlags, point);
}


void LogicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (listvalue == 0){
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
		Invalidate(TRUE);
		
		
	}
	CView::OnLButtonUp(nFlags, point);
}


void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
		// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON && listvalue == 0){																		//Ŭ���� �� �ȵ�
		for (i = 0; i < max; i++) {
			CDC* pDC = GetDC();
			CBitmap bmp;
			CDC MemDC;
			BITMAP bmpInfo;
			
			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);
			
			if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight) {
				current = i;
				break;
			}
		}
	}
	else if (nFlags & MK_RBUTTON){					
		listvalue = 0;

	}
	else if(listvalue > 99 && listvalue < 350){											//����Ʈ �׸���
		CDC* pDC = GetDC();
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		MemDC.CreateCompatibleDC(pDC);
		
		switch (listvalue) {
		case 100:
			bmp.LoadBitmapW(IDB_BITMAP1);
			name = _T("AND����Ʈ");
			bitmap_name[i] = IDB_BITMAP1;
			break;
		case 101:
			bmp.LoadBitmapW(IDB_BITMAP2);
			bitmap_name[i] = IDB_BITMAP2;
			name = _T("OR����Ʈ");
			break;
		case 102:
			bmp.LoadBitmapW(IDB_BITMAP3);
			name = _T("NOT����Ʈ");
			bitmap_name[i] = IDB_BITMAP3;
			break;
		case 103:
			bmp.LoadBitmapW(IDB_BITMAP4);
			name = _T("NAND����Ʈ");
			bitmap_name[i] = IDB_BITMAP4;
			break;
		case 104:
			bmp.LoadBitmapW(IDB_BITMAP5);
			name = _T("NOR����Ʈ");
			bitmap_name[i] = IDB_BITMAP5;
			break;
		case 105:
			bmp.LoadBitmapW(IDB_BITMAP6);
			name = _T("XOR����Ʈ");
			bitmap_name[i] = IDB_BITMAP6;
			break;
		case 200:
			bmp.LoadBitmapW(IDB_BITMAP7);
			name = _T("D�ø��÷�");
			bitmap_name[i] = IDB_BITMAP7;
			break;
		case 201:
			bmp.LoadBitmapW(IDB_BITMAP8);
			name = _T("JK�ø��÷�");
			bitmap_name[i] = IDB_BITMAP8;
			break;
		case 202:
			bmp.LoadBitmapW(IDB_BITMAP9);
			name = _T("T�ø��÷�");
			bitmap_name[i] = IDB_BITMAP9;
			break;
		case 300:
			bmp.LoadBitmapW(IDB_BITMAP10);
			name = _T("");
			bitmap_name[i] = IDB_BITMAP10;
			CButton * radioButtonZero;
			CButton * radioButtonOne;
			radioButtonZero = new CButton();
			radioButtonOne = new CButton();

			radioButtonZero->Create(_T("0"), WS_GROUP | BS_AUTORADIOBUTTON, CRect(point.x, point.y + 35, point.x + 25, point.y + 50), this, 300);
			radioButtonOne->Create(_T("1"), BS_AUTORADIOBUTTON, CRect(point.x + 30, point.y + 33, point.x + 55, point.y + 50), this, 301);
			radioButtonZero->ShowWindow(SW_SHOW);
			radioButtonOne->ShowWindow(SW_SHOW);
			break;
			
		}
		bmp.GetBitmap(&bmpInfo);
		CBitmap *pOldBmp = (CBitmap *)MemDC.SelectObject(&bmp);
		pOldBmp = pDC->SelectObject(&bmp);
		m_ptBitmapX[i] = point.x;
		m_ptBitmapY[i] = point.y;

		pDC->BitBlt(m_ptBitmapX[i], m_ptBitmapY[i], m_ptBitmapX[i] + bmpInfo.bmWidth, m_ptBitmapY[i] + bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		pDC->TextOutW(m_ptBitmapX[i] + 10, m_ptBitmapY[i] + bmpInfo.bmHeight, name);

		PositionInfoX[i] = point.x;
		PositionInfoY[i] = point.y;
		gate_name[i] = name;
		

		i++;
		max++;

		MemDC.SelectObject(pOldBmp);

		ReleaseDC(pDC);
	}
	else if (listvalue = 400) {

	}
	CView::OnLButtonDown(nFlags, point);
}

void LogicView::OnRButtonDown(UINT nFlags, CPoint point) {
	if (nFlags & MK_RBUTTON && listvalue != 0)                //���콺 ������ ��ư -> �׸��� �׸�
		listvalue = 0;
	else if (listvalue == 0){
		LogicView::BYTE_image_rotate_90();

	}
}

void LogicView::BYTE_image_rotate_90()
{	
	if (bitmap_name[current] % 10 != 0)
		bitmap_name[current] = bitmap_name[current] + 1;
	else
		bitmap_name[current] = bitmap_name[current] - 3;
		Invalidate(TRUE);
}

void LogicView::OnButtonClicked(void) {  //�Է� �� radio button (�̱���)
	int state_radio;

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



void LogicView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CDC* pDC = GetDC();
	
	CDC MemDC;
	BITMAP bmpInfo;


	if (listvalue != -1){
	MemDC.CreateCompatibleDC(pDC);

	
	
	for (i = 0; i < max; i = i++){
		CBitmap bmp;
		bmp.LoadBitmapW(bitmap_name[i]);
		bmp.GetBitmap(&bmpInfo);
		CBitmap *pOldBmp = (CBitmap *)MemDC.SelectObject(&bmp);
		pOldBmp = pDC->SelectObject(&bmp);
		pDC->BitBlt(m_ptBitmapX[i], m_ptBitmapY[i], m_ptBitmapX[i] + bmpInfo.bmWidth, m_ptBitmapY[i] + bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		//if(gate_name[i] ==NULL)
		pDC->TextOutW(m_ptBitmapX[i] + 10, m_ptBitmapY[i] + bmpInfo.bmHeight, gate_name[i]);
		}
	}
	//i = i++;
}
