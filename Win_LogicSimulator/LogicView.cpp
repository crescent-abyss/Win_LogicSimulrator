// LogicView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "LogicView.h"
#include "TreeView.h"
#include "InfomationView.h"
#include "MainFrm.h"
#include "Win_LogicSimulatorDoc.h"
#include "Win_LogicSimulatorView.h"

CString gate_name[100];
CString name;
CMainFrame *p_frame = (CMainFrame *)AfxGetMainWnd();
//CWin_LogicSimulatorDoc * p_Doc = (CWin_LogicSimulatorDoc *)p_frame->GetActiveDocument();



// (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 && m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2); 좌상

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
	ON_BN_CLICKED(300, OnButtonClicked)
	ON_BN_CLICKED(301, OnButtonClicked)
	ON_BN_CLICKED(302, OnButtonClicked_CLock)
	ON_BN_CLICKED(303, OnButtonClicked_CLock)
	ON_BN_CLICKED(304, OnButtonClicked_CLock)
	ON_WM_PAINT()
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
	if (listvalue == 500){
		for (i = 0; i < max; i++) {
			CDC* pDC = GetDC();
			CBitmap bmp;
			CDC MemDC;
			BITMAP bmpInfo;
			CClientDC dc(this);
			CPen test_dot_tick1_pen(PS_DOT, 3, RGB(0, 255, 0));
			// 새로 생성한 펜을 DC에 연결한다.
			CPen *p_old_pen = dc.SelectObject(&test_dot_tick1_pen);

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight) {
				current = i;

				if (nFlags & MK_LBUTTON && listvalue == 500 && m_bDrawMode == TRUE)
					// 출력부분만 설정 출력 게이트 클릭시 m_bDrawMode = TRUE 로 설정
				{
					if (bitmap_name[i] == 317){			//and게이트일떄
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 110);

						}

					}
					else if (bitmap_name[i] == 318){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 5);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 5);
						}

					}
					else if (bitmap_name[i] == 319){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 47);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 110);

						}
					}
					else if (bitmap_name[i] == 320){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 250);
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 250);
						}

					}
					else if (bitmap_name[i] == 327){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 15, m_ptBitmapY[current] + 52);

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 15, m_ptBitmapY[current] + 113);

						}
					}
					else if (bitmap_name[i] == 328){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 45, m_ptBitmapY[current] + 15);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 107, m_ptBitmapY[current] + 15);
						}
					}
					else if (bitmap_name[i] == 329){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 260, m_ptBitmapY[current] + 45);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 260, m_ptBitmapY[current] + 105);

						}
					}
					else if (bitmap_name[i] == 330){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 53, m_ptBitmapY[current] + 260);
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 112, m_ptBitmapY[current] + 260);
						}
					}
					else if (bitmap_name[i] == 337){
					}
					else if (bitmap_name[i] == 338){
					}
					else if (bitmap_name[i] == 339){
					}
					else if (bitmap_name[i] == 340){
					}
					else if (bitmap_name[i] == 347){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);

						}
					}
					else if (bitmap_name[i] == 348){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
						}
					}
					else if (bitmap_name[i] == 349){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);

						}
					}
					else if (bitmap_name[i] == 350){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
						}
					}
					else if (bitmap_name[i] == 357){																					// NOR		
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);

						}
					}
					else if (bitmap_name[i] == 358){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
						}
					}
					else if (bitmap_name[i] == 359){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);

						}
					}
					else if (bitmap_name[i] == 360){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
						}
					}
					else if (bitmap_name[i] == 367){																							//XOR
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);

						}
					}
					else if (bitmap_name[i] == 368){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
						}
					}
					else if (bitmap_name[i] == 369){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);

						}
					}
					else if (bitmap_name[i] == 370){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							dc.SetROP2(R2_NOT);
							dc.MoveTo(m_ptStart);
							dc.LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
						}
					}
					else if (bitmap_name[i] == 377){
					}
					else if (bitmap_name[i] == 378){
					}
					else if (bitmap_name[i] == 379){
					}
					else if (bitmap_name[i] == 380){
					}
					else if (bitmap_name[i] == 387){
					}
					else if (bitmap_name[i] == 388){
					}
					else if (bitmap_name[i] == 389){
					}
					else if (bitmap_name[i] == 390){
					}
					else if (bitmap_name[i] == 397){
					}
					else if (bitmap_name[i] == 398){
					}
					else if (bitmap_name[i] == 399){
					}
					else if (bitmap_name[i] == 400){
					}
					else if (bitmap_name[i] == 587){
						dc.SetROP2(R2_NOT);
						dc.MoveTo(m_ptStart);
						dc.LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 70);
					}




				}
				break;
			}
		}
	}
	if (nFlags & MK_LBUTTON && listvalue == 0) {						

		m_ptBitmapX[current] = point.x;
		m_ptBitmapY[current] = point.y;
		
	}
}


void LogicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (listvalue == 0){
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
		Invalidate(TRUE);
		
		
	}
	else if (listvalue == 500){
		if (m_bDrawMode == TRUE){
			CClientDC dc(this);
		
			m_bDrawMode = FALSE;
		}
	}
	
	CView::OnLButtonUp(nFlags, point);
}


void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDC* pDC = GetDC();
	CBitmap bmp;
	CDC MemDC;
	BITMAP bmpInfo;

																											//출력부분
	if (listvalue == 500){

		if (bitmap_name[i] == 317){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 327){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 337){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 347){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 357){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 367){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 377){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight/2){					// 우상 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
			else if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight ){					// 우하 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 387){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){					// 우상 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
			else if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우하 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 397){

			bmp.LoadBitmapW(bitmap_name[i]);
			bmp.GetBitmap(&bmpInfo);

			if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){					// 우상 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
			else if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
				m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){					// 우하 -- 출력비트
				m_ptStart = point;
				m_ptEnd = m_ptBitmapY[current] + 110;
				m_bDrawMode = TRUE;
			}
		}
		if (bitmap_name[i] == 507){
			m_ptStart = point;
			m_ptEnd = m_ptBitmapY[current] + 110;
			m_bDrawMode = TRUE;
		}





	}



	
	else if (nFlags & MK_LBUTTON && listvalue == 0){                                                      //클릭이 잘 안됨
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
	
	else if (nFlags & MK_LBUTTON && listvalue == 500){
		
	}
	else if (nFlags & MK_RBUTTON){					
		listvalue = 0;

	}
	else if(listvalue > 99 && listvalue < 499){											//게이트 그리기
		CDC* pDC = GetDC();
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		MemDC.CreateCompatibleDC(pDC);
		
		switch (listvalue) {
		case 100:
			bmp.LoadBitmapW(IDB_BITMAP1);
			name = _T("AND게이트");
			bitmap_name[i] = IDB_BITMAP1;
			break;
		case 101:
			bmp.LoadBitmapW(IDB_BITMAP2);
			bitmap_name[i] = IDB_BITMAP2;
			name = _T("OR게이트");
			break;
		case 102:
			bmp.LoadBitmapW(IDB_BITMAP3);
			name = _T("NOT게이트");
			bitmap_name[i] = IDB_BITMAP3;
			break;
		case 103:
			bmp.LoadBitmapW(IDB_BITMAP4);
			name = _T("NAND게이트");
			bitmap_name[i] = IDB_BITMAP4;
			break;
		case 104:
			bmp.LoadBitmapW(IDB_BITMAP5);
			name = _T("NOR게이트");
			bitmap_name[i] = IDB_BITMAP5;
			break;
		case 105:
			bmp.LoadBitmapW(IDB_BITMAP6);
			name = _T("XOR게이트");
			bitmap_name[i] = IDB_BITMAP6;
			break;
		case 200:
			bmp.LoadBitmapW(IDB_BITMAP7);
			name = _T("D플립플롭");
			bitmap_name[i] = IDB_BITMAP7;
			break;
		case 201:
			bmp.LoadBitmapW(IDB_BITMAP8);
			name = _T("JK플립플롭");
			bitmap_name[i] = IDB_BITMAP8;
			break;
		case 202:
			bmp.LoadBitmapW(IDB_BITMAP9);
			name = _T("T플립플롭");
			bitmap_name[i] = IDB_BITMAP9;
			break;
		case 300:
			bmp.LoadBitmapW(IDB_BITMAP10);
			name = _T("입력 스위치");
			bitmap_name[i] = IDB_BITMAP10;
			
			break;

		case 400:
			bmp.LoadBitmapW(IDB_BITMAP15);
			name = _T("출력 램프");
			bitmap_name[i] = IDB_BITMAP15;
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

		CDocument* pDoc = GetDocument();
		pDoc->SetModifiedFlag();

	}

	CView::OnLButtonDown(nFlags, point);
}

void LogicView::OnRButtonDown(UINT nFlags, CPoint point) {
	if (nFlags & MK_RBUTTON && listvalue != 0)                //마우스 오른쪽 버튼 -> 그리기 그만
		listvalue = 0;
	else if (listvalue == 0 && bitmap_name[i] <500){
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

		CDocument* pDoc = GetDocument();
		pDoc->SetModifiedFlag();
}

void LogicView::OnButtonClicked(void) {  //입력 값 radio button (미구현) 
	int state_ZeroOne;
	int data;

	state_ZeroOne = GetCheckedRadioButton(300, 301);

	if (state_ZeroOne == 300) {
		data = 0;
	}
	else {
		data = 1;
	}

}

void LogicView::OnButtonClicked_CLock(void) {			//클록 라디오 버튼 클릭 리스너
	int state_Clock;
	int data_Clock;

	state_Clock = GetCheckedRadioButton(302, 304);

	if (state_Clock == 302) {
		data_Clock = 1;
	}
	else if (state_Clock == 303) {
		data_Clock = 10;
	}
	else {
		data_Clock = 50;
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



void LogicView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

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

	CDocument* pDoc = GetDocument();
	pDoc->SetModifiedFlag();
	}

	
	
	//i = i++;
}
