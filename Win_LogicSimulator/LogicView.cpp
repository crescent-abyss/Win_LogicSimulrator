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
#include <afxwin.h>

CString gate_name[100];
CString name;
CMainFrame *p_frame = (CMainFrame *)AfxGetMainWnd();
InfomationView* a = new InfomationView;
CButton * Clock1;		//클럭 버튼 구현
CButton * Clock10;
CButton * Clock50;
CButton make_libraryBox;
CString text;
int textlocation[100] = { NULL };
int check1;
int check2;
int state_switch[100] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int data[100] = { NULL };
int and[100] = { NULL };
int inputvalue[100] = { NULL };
int p = 0;
int Hz_state;
int not[100] = { NULL };
int or[100] = { NULL };
int t[100] = { NULL };
int jk[100] = { NULL };
int d[100] = { NULL };
int nand[100] = { NULL };
int xor[100] = { NULL };
int nor[100] = { NULL };

CString text_name[100] = { NULL };
// (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 && m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2); 좌상

// LogicView

IMPLEMENT_DYNCREATE(LogicView, CView)

LogicView::LogicView()
{
	Clip_bitmap = 0;
	Clip_gateName = "";
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
	ON_COMMAND(ID_EDIT_UNDO, OnUndo)
	ON_COMMAND(ID_EDIT_REDO, OnRedo)
	ON_COMMAND(ID_EDIT_CUT, Cut)
	ON_COMMAND(ID_EDIT_PASTE, Paste)
	ON_COMMAND(ID_EDIT_COPY, Copy)
	ON_COMMAND(680, OnClickedPush)
	ON_WM_PAINT()
	ON_WM_CREATE()
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
		
			CPen Pen, *oldPen;
			Pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
			oldPen = pDC->SelectObject(&Pen);//old에 반드시 넣어준다.
			
			// 새로 생성한 펜을 DC에 연결한다.


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
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							LayerEndX[Layer_column] = m_ptBitmapX[current] + 5;
							LayerEndY[Layer_column] = m_ptBitmapY[current] + 47;
							and[0] = inputvalue[p];

							

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 110);
							LayerEndX[Layer_column] = m_ptBitmapX[current] + 5;
							LayerEndY[Layer_column] = m_ptBitmapY[current] + 110;
							and[1] = inputvalue[p];

							
							
						}

					}
					else if (bitmap_name[i] == 318){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 5);
							and[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 5);
							and[1] = inputvalue[p];
						}

					}
					else if (bitmap_name[i] == 319){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 47);
							and[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 110);
							and[1] = inputvalue[p];

						}
					}
					else if (bitmap_name[i] == 320){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 250);
							and[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 250);
							and[1] = inputvalue[p];
						}

					}
					else if (bitmap_name[i] == 327){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 15, m_ptBitmapY[current] + 52);
							or[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 15, m_ptBitmapY[current] + 113);
							or[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 328){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 45, m_ptBitmapY[current] + 15);
							or[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 107, m_ptBitmapY[current] + 15);
							or[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 329){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 260, m_ptBitmapY[current] + 45);
							or[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 260, m_ptBitmapY[current] + 105);
							or[1] = inputvalue[p];

						}
					}
					else if (bitmap_name[i] == 330){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 53, m_ptBitmapY[current] + 260);
							or[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 112, m_ptBitmapY[current] + 260);
							or[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 337){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 12, m_ptBitmapY[current] + 60);
							not[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 338){
						if (m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 52, m_ptBitmapY[current] + 10);
							not[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 339){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 262, m_ptBitmapY[current] + 60);
							not[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 340){
						if (m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 62, m_ptBitmapY[current] + 210);
							not[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 347){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);
							nand[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);
							nand[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 348){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);
							nand[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
							nand[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 349){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);
							nand[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);
							nand[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 350){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
							nand[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
							nand[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 357){																					// NOR		
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);
							nor[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);
							nor[1] = inputvalue[p];

						}
					}
					else if (bitmap_name[i] == 358){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);
							nor[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
							nor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 359){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);
							nor[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);
							nor[1] = inputvalue[p];

						}
					}
					else if (bitmap_name[i] == 360){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
							nor[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
							nor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 367){																							//XOR
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 43);
							xor[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 10, m_ptBitmapY[current] + 108);
							xor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 368){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 43, m_ptBitmapY[current] + 8);
							xor[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 105, m_ptBitmapY[current] + 8);
							xor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 369){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 39);
							xor[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 267, m_ptBitmapY[current] + 104);
							xor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 370){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 270);
							xor[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 270);
							xor[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 377){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							d[0] = inputvalue[p];
					}
					}
					else if (bitmap_name[i] == 378){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
						pDC->MoveTo(m_ptStart);
						pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							d[0] = inputvalue[p];
					}
					}

					else if (bitmap_name[i] == 379){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){

							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 110);
							d[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 380){
						if(m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight)
							d[0] = inputvalue[p];
					}
					else if (bitmap_name[i] == 387){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							jk[0] = inputvalue[p];



						}
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 110);
							jk[1] = inputvalue[p];



						}
					}
					else if (bitmap_name[i] == 388){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 5);
							jk[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 5);
							jk[1] = inputvalue[p];
						}

					}
					else if (bitmap_name[i] == 389){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 47);
							jk[0] = inputvalue[p];

						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 110);
							jk[1] = inputvalue[p];

						}
					}
					else if (bitmap_name[i] == 390){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){//좌하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 48, m_ptBitmapY[current] + 250);
							jk[0] = inputvalue[p];
						}
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){	//우하
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 110, m_ptBitmapY[current] + 250);
							jk[1] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 397){
						if (m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//좌상
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							t[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 398){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight / 2){	//우상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 5, m_ptBitmapY[current] + 47);
							t[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 399){
						if (m_ptBitmapX[i] + bmpInfo.bmWidth / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight){

							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current] + 250, m_ptBitmapY[current] + 110);
							t[0] = inputvalue[p];
						}
					}
					else if (bitmap_name[i] == 400){
						if (m_ptBitmapX[i] / 2 <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 2 <= point.y && point.y <= m_ptBitmapY[i] + bmpInfo.bmHeight)

							t[0] = inputvalue[p];
					}
					else if (bitmap_name[i] == 407){
					if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
						m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] +20+ (bmpInfo.bmHeight / 7) * 2) ){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP42;
								Invalidate(TRUE);
							}
							else if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP41;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] +20+ (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP43;
								Invalidate(TRUE);
							}
							
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7)*3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP45;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP49;
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 410){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP42;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP43;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP45;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP49;
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 411){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP41;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP44;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP47;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP50;
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 412){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP44;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP41;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP47;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 413){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP43;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP42;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP48;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 414){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP46;
								Invalidate(TRUE);
							}
							
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP47;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP41;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 415){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP45;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP48;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 416){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP48;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP45;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP43;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 417){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP47;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP46;
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP44;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 418){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 1){
								bitmap_name[i] = IDB_BITMAP50;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){
								
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP41;
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 419){
						if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + bmpInfo.bmHeight / 7 <= point.y && point.y <= m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2)){
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 45);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP49;
								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + 20 + (bmpInfo.bmHeight / 7) * 2 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 82);
							if (inputvalue[p] == 1){

								Invalidate(TRUE);
							}

						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 3 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 120);
							if (inputvalue[p] == 1){

								Invalidate(TRUE);
							}
						}
						else if ((m_ptBitmapX[i] <= point.x && point.x <= m_ptBitmapX[i] + bmpInfo.bmWidth / 2 &&
							m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 5 <= point.y && point.y <= m_ptBitmapY[i] + (bmpInfo.bmHeight / 7) * 6)){	//좌상
							pDC->SetROP2(R2_NOT);
							pDC->MoveTo(m_ptStart);
							pDC->LineTo(m_ptBitmapX[current], m_ptBitmapY[current] + 150);
							if (inputvalue[p] == 0){
								bitmap_name[i] = IDB_BITMAP42;
								Invalidate(TRUE);
							}
						}
					}
					else if (bitmap_name[i] == 517){
						pDC->SetROP2(R2_NOT);
						pDC->MoveTo(m_ptStart);
						pDC->LineTo(m_ptBitmapX[current] + 18, m_ptBitmapY[current] + 70);
							if (inputvalue[p] == 1)
								AfxMessageBox(_T("1값"));
							else
								AfxMessageBox(_T("0값"));
						
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
			p = p + 1;
			
			m_bDrawMode = FALSE;
			
			
																														// 비트맵위에서 마우스 떌시 p = p+1; 해주기로
		}
	}
	
	CView::OnLButtonUp(nFlags, point);
}


void LogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_pos = point;			//잘라내기, 복사, 붙여넣기 위한 좌표값을 받는다.

	CDC* pDC = GetDC();
	CBitmap bmp;
	CDC MemDC;
	BITMAP bmpInfo;
	CClientDC dc(this);

	if (25 <= point.x && point.x <= 105 &&
		535 <= point.y && point.y <= 555){									// Hz_ 설정
		CPen Pen, *oldPen;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 540, 100, 550);
		Hz_state = 1;
		Pen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		oldPen = pDC->SelectObject(&Pen);//old에 반드시 넣어준다.
		pDC->Rectangle(CRect(80, 560, 100, 570));//이런 식으로 사용한다
		pDC->Rectangle(CRect(80, 580, 100, 590));//이런 식으로 사용한다
		// 새로 생성한 펜을 DC에 연결한다.
		Pen.DeleteObject(); //팬을 제거 한다. 
		
	}
	if (25 <= point.x && point.x <= 105 &&
		555 <= point.y && point.y <= 575){

		CPen Pen, *oldPen;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 560, 100, 570);
		Hz_state = 10;
		Pen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//녹색의 선을 만든다.
		oldPen = pDC->SelectObject(&Pen);//old에 반드시 넣어준다.
		pDC->Rectangle(CRect(80, 530, 100, 550));//이런 식으로 사용한다
		pDC->Rectangle(CRect(80, 580, 100, 590));//이런 식으로 사용한다
	}

	if (25 <= point.x && point.x <= 105 &&
		575 <= point.y && point.y <= 595){
		CPen Pen, *oldPen;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 580, 100, 590);
		Hz_state = 50;
		Pen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//녹색의 선을 만든다.
		oldPen = pDC->SelectObject(&Pen);//old에 반드시 넣어준다.
		pDC->Rectangle(CRect(80, 530, 100, 550));//이런 식으로 사용한다
		pDC->Rectangle(CRect(80, 550, 100, 570));//이런 식으로 사용한다
	}
	if (150 <= point.x && point.x <= 190 &&
		540 <= point.y && point.y <= 570){
		state_switch[0] = 1;
		data[0] = 1;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160, 540, 190, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160, 570, 190, 600);
		
	}
	if (150 <= point.x && point.x <= 190 &&
		570 <= point.y && point.y <= 600){
		state_switch[0] = 0;
		data[0] = 0;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160, 570, 190, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160, 540, 190, 570);
	}
	if (150 +70 <= point.x && point.x <= 190 +70 &&
		540 <= point.y && point.y <= 570)
	{
		state_switch[1] = 1;
		data[1] = 1;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 70, 540, 190 + 70, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 70, 570, 190 + 70, 600);
	}
	if (150 + 70 <= point.x && point.x <= 190 + 70 &&
		570 <= point.y && point.y <= 600)
	{
		state_switch[1] = 0;
		data[1] = 0;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 70, 570, 190 + 70, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 70, 540, 190 + 70, 570);
	}
	if (150 + 140 <= point.x && point.x <= 190 + 140 &&
		540 <= point.y && point.y <= 570)
	{
		state_switch[2] = 1;
		data[2] = 1;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 140, 540, 190 + 140, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 140, 570, 190 + 140, 600);
	}
	if (150 + 140 <= point.x && point.x <= 190 + 140 &&
		570 <= point.y && point.y <= 600)
	{
		state_switch[2] = 0;
		data[2] = 0;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 140, 570, 190 + 140, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 140, 540, 190 + 140, 570);
	}
	if (150 + 210 <= point.x && point.x <= 190 + 210 &&
		540 <= point.y && point.y <= 570)
	{
		state_switch[3] = 1;
		data[3] = 1;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 210, 540, 190 + 210, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 210, 570, 190 + 210, 600);
	}
	if (150 + 210 <= point.x && point.x <= 190 + 210 &&
		570 <= point.y && point.y <= 600)
	{
		state_switch[3] = 0;
		data[3] = 0;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 210, 570, 190 + 210, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 210, 540, 190 + 210, 570);
	}
	if (150 + 280 <= point.x && point.x <= 190 + 280 &&
		540 <= point.y && point.y <= 570)
	{
		state_switch[4] = 1;
		data[4] = 1;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 280, 540, 190 + 280, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 280, 570, 190 + 280, 600);
	}
	if (150 + 280 <= point.x && point.x <= 190 + 280 &&
		570 <= point.y && point.y <= 600)
	{
		state_switch[4] = 0;
		data[4] = 0;
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 280, 570, 190 + 280, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 280, 540, 190 + 280, 570);
	}
	

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
				int result;
				result = and[0] & and[1];
				inputvalue[p] = result;
				
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
				int result;
				result = or[0] | or[1];
				inputvalue[p] = result;
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
				int result;
				if (not[0] == 1)
					result = 0;
				else
					result = 1;
				inputvalue[p] = result;
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
				int result;
				result = nand[0] & nand[1];
				if (result == 1)
					result = 0;
				else
					result = 1;
				inputvalue[p] = result;

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
				int result;
				result = nor[0] | nor[1];
				if (result == 1)
					result = 0;
				else
					result = 1;
				inputvalue[p] = result;
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
				int result;
				result = xor[0] ^ xor[1];
				inputvalue[p] = result;
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
					if (text_name[i] == _T("0번입력")){
						inputvalue[p] = data[0];
						LayerX[Layer_column] = point.x;
						LayerY[Layer_column] = point.y;
					}
					else if (text_name[i] == _T("1번입력")){
						inputvalue[p] = data[1];
						LayerX[Layer_column] = point.x;
						LayerY[Layer_column] = point.y;
					}
					else if (text_name[i] == _T("2번입력")){
						inputvalue[p] = data[2];
						LayerX[0] = point.x;
						LayerY[0] = point.y;
					}
					else if (text_name[i] == _T("3번입력")){
						inputvalue[p] = data[3];
						LayerX[0] = point.x;
						LayerY[0] = point.y;
					}
				}
			}
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
		case 407:
			bmp.LoadBitmapW(IDB_BITMAP40);		//세그먼트
			name = _T("7-세그먼트");
			bitmap_name[i] = IDB_BITMAP40;
			break;
		case 300:
			bmp.LoadBitmapW(IDB_BITMAP10);
			text.Format(_T("%d번입력"), test);
			name = text;
		
			bitmap_name[i] = IDB_BITMAP10;
			
			CButton * radioButtonZero;
			CButton * radioButtonOne;
			radioButtonZero = new CButton();
			radioButtonOne = new CButton();
			pDC->DrawText(text, CRect(150 + test * 70, 510, 220 + test * 70, 540), NULL);
			
			textlocation[j] = 150 + test * 70;
			check1 = 300 + test * 2;
			check2 = 301 + test * 2;

			pDC->Rectangle(CRect(150 + test * 70 + 10, 540, 150 + test * 70 + 40, 570));
			pDC->DrawText(_T("1"), CRect(150 + test * 70, 540, 150 + test * 70 + 10, 570), NULL);
			pDC->DrawText(_T("0"), CRect(150 + test * 70, 570, 150 + test * 70 + 10, 600), NULL);
			pDC->Rectangle(CRect(150 + test * 70 + 10, 570, 150 + test * 70 + 40, 600));
			//data[test];
			test = test + 1;
			text_name[j] = text;
			j = j++;
			break;


		case 400:									//출력 램프 및 라벨 설정
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

		
		gate_name[i] = name;
		
		i++;
		max++;
		Undo_max = max;

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
	else
		;
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

	dc.MoveTo(0, 500);
	dc.LineTo(2500, 500);
	dc.Rectangle(10, 520, 120, 610);
	dc.DrawText(_T("헤르츠설정"), CRect(25, 510, 105, 600), NULL);
	dc.DrawText(_T("1Hz"), CRect(25, 535, 105, 555), NULL);
	dc.DrawText(_T("10Hz"), CRect(25, 555, 105, 575), NULL);
	dc.DrawText(_T("50Hz"), CRect(25, 575, 105, 595), NULL);
	
	if (Hz_state == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 540, 100, 550);
		dc.SetROP2(R2_COPYPEN);
	}
	else if (Hz_state == 10){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 560, 100, 570);
		dc.SetROP2(R2_COPYPEN);
	}
	else if (Hz_state == 50){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(80, 580, 100, 590);
		dc.SetROP2(R2_COPYPEN);
	}


	
	
	if (listvalue != -1){
	MemDC.CreateCompatibleDC(pDC);

	
	for (int k = 0; k < j; k++){
		pDC->DrawText(text_name[k], CRect(textlocation[k], 510, textlocation[k] + 100, 540), NULL);
		dc.Rectangle(CRect(textlocation[k] +10 , 540, textlocation[k]+40 , 570));
		dc.DrawText(_T("1"), CRect(textlocation[k], 540, textlocation[k] + 10, 570), NULL);
		dc.DrawText(_T("0"), CRect(textlocation[k], 570, textlocation[k] + 10, 600), NULL);
		dc.Rectangle(CRect(textlocation[k] +10, 570, textlocation[k] + 40, 600));
	
	}
	
	if (state_switch[0] == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160, 540, 190, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160, 570, 190, 600);
	}
	if (state_switch[0] == 0){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160, 570, 190, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160, 540, 190, 570);
	}
	if (state_switch[1] == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 70, 540, 190 + 70, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 70, 570, 190 + 70, 600);
	}
	if (state_switch[1] == 0){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 70, 570, 190 + 70, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 70, 540, 190 + 70, 570);
	}
	if (state_switch[2] == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 140, 540, 190 + 140, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 140, 570, 190 + 140, 600);
	}
	if (state_switch[2] == 0){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 140, 570, 190 + 140, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 140, 540, 190 + 140, 570);
	}
	if (state_switch[3] == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 210, 540, 190 + 210, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 210, 570, 190 + 210, 600);
	}
	if (state_switch[3] == 0){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 210, 570, 190 + 210, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 210, 540, 190 + 210, 570);
	}
	if (state_switch[4] == 1){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 280, 540, 190 + 280, 570);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 280, 570, 190 + 280, 600);
	}
	if (state_switch[4] == 0){
		dc.SetROP2(R2_NOT);
		dc.Rectangle(160 + 280, 570, 190 + 280, 600);
		dc.SetROP2(R2_COPYPEN);
		dc.Rectangle(160 + 280, 540, 190 + 280, 570);
	}
	
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

		CPen Pen, *oldPen;
		Pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
		oldPen = pDC->SelectObject(&Pen);//old에 반드시 넣어준다.

		//pDC->MoveTo(LayerX[0], LayerY[0]);
		//pDC->LineTo(LayerEndX[0], LayerEndY[0]);
		
	
	CDocument* pDoc = GetDocument();
	pDoc->SetModifiedFlag();
	
	}

	
	//i = i++;
}

void LogicView::OnUndo() {			//와이어링 미구현
	if (max != 0) {
		if (bitmap_name[max - 1] == IDB_BITMAP10) {
			test--;
			j--;
		}
		max--;
		Invalidate();
	}
	else {
		AfxMessageBox(_T("Can not Undo"));
}
}

void LogicView::OnRedo() {			//와이어링 미구현
	if (max < Undo_max) {
		max++;
		if (bitmap_name[max - 1] == IDB_BITMAP10) {
			test++;
			j++;
		}
		Invalidate();
	}
	else {
		AfxMessageBox(_T("Can not Redo"));
}
}

void LogicView::Cut() {								//잘라내기
	for (i = 0; i < max; ++i) {
		CDC * pDC = GetDC();
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		CClientDC dc(this);

		bmp.LoadBitmapW(bitmap_name[i]);
		bmp.GetBitmap(&bmpInfo);

		if (m_ptBitmapX[i] <= m_pos.x && m_pos.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
			m_ptBitmapY[i] <= m_pos.y && m_pos.y <= m_ptBitmapY[i] + bmpInfo.bmHeight) {
			current = i;
		}
	}

	Clip_bitmap = bitmap_name[current];
	Clip_gateName = gate_name[current];

	if (Clip_bitmap == IDB_BITMAP10) {
		test--;
		j--;
	}

	for (int j = current; j < max-1; ++j) {
		m_ptBitmapX[j] = m_ptBitmapX[j + 1];
		m_ptBitmapY[j] = m_ptBitmapY[j + 1];
		bitmap_name[j] = bitmap_name[j + 1];
		gate_name[j] = gate_name[j + 1];
	}
	
	m_ptBitmapX[max - 1] = NULL;
	m_ptBitmapY[max - 1] = NULL;
	bitmap_name[max - 1] = NULL;
	gate_name[max - 1] = "";

	max--;

	Invalidate();
}

void LogicView::Paste() {
	if (Clip_bitmap) {
		
		m_ptBitmapX[max] = m_pos.x;
		m_ptBitmapY[max] = m_pos.y;
		bitmap_name[max] = Clip_bitmap;
		if (bitmap_name[max] != IDB_BITMAP10) {
			gate_name[max] = Clip_gateName;
		}
		else {
			test++;
			j++;
			CString text;
			text.Format(_T("%d번입력"), test);
			gate_name[max] = text;
		}
		max++;

		Invalidate();
	}
}

void LogicView::Copy() {
	for (i = 0; i < max; ++i) {
		CDC * pDC = GetDC();
		CBitmap bmp;
		CDC MemDC;
		BITMAP bmpInfo;
		CClientDC dc(this);

		bmp.LoadBitmapW(bitmap_name[i]);
		bmp.GetBitmap(&bmpInfo);

		if (m_ptBitmapX[i] <= m_pos.x && m_pos.x <= m_ptBitmapX[i] + bmpInfo.bmWidth &&
			m_ptBitmapY[i] <= m_pos.y && m_pos.y <= m_ptBitmapY[i] + bmpInfo.bmHeight) {
			current = i;
		}
		
	}
	Clip_bitmap = bitmap_name[current];
	Clip_gateName = gate_name[current];
}

int LogicView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	make_libraryBox.Create(_T("라이브러리 만들기"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(0, 0, 140, 20), this, 680);
	return 0;
}
void LogicView::OnClickedPush() {
	int Lib_X[100];
	int Lib_Y[100];
	int Lib_bitmap[100];
	CString Lib_gateName[100];
	int Lib_max = max;

	for (int k = 0; k < max; ++k) {
		Lib_X[k] = m_ptBitmapX[k];
		Lib_Y[k] = m_ptBitmapY[k];
		Lib_bitmap[k] = bitmap_name[k];
		Lib_gateName[k] = gate_name[k];
	}

}