// TreeView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Win_LogicSimulator.h"
#include "TreeView.h"
#include "Win_LogicSimulatorDoc.h"


// TreeView

IMPLEMENT_DYNCREATE(TreeView, CTreeView)

TreeView::TreeView()
{
	
}

TreeView::~TreeView()
{
}

BEGIN_MESSAGE_MAP(TreeView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &TreeView::OnTvnSelchanged)
END_MESSAGE_MAP()


BOOL TreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;
	return CTreeView::PreCreateWindow(cs);
}

void TreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// 이미지 리스트 생성과 초기화
	CImageList il;
	il.Create(IDR_Win_LogicSimulaTYPE, 16, 1, RGB(255, 255, 255));

	// 이미지 리스트 설정
	CTreeCtrl& tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	// 항목 추가
	/* 1-레벨 초기화 */
	HTREEITEM LogicTree = tree.InsertItem(_T("논리회로"), 0, 0, TVI_ROOT, TVI_LAST);
	HTREEITEM LibTree = tree.InsertItem(_T("라이브러리"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-레벨 초기화 */
	HTREEITEM SubTree[5];
	CString Tree[] = {
		_T("논리게이트"), _T("플립플롭(FF)"), _T("입력"), _T("출력"), _T("와이어")
	};
	for (int i = 0; i<5; i++)
		SubTree[i] = tree.InsertItem(Tree[i], 1, 1, LogicTree, TVI_LAST);

	/* 3-레벨 초기화 */
	tree.InsertItem(_T("AND 게이트"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("OR 게이트"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NOT 게이트"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NAND 게이트"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NOR 게이트"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("XOR 게이트"), 2, 2, SubTree[0], TVI_LAST);

	tree.InsertItem(_T("D-플립플롭"), 2, 2, SubTree[1], TVI_LAST);
	tree.InsertItem(_T("JK-플립플롭"), 2, 2, SubTree[1], TVI_LAST);
	tree.InsertItem(_T("T-플립플롭"), 2, 2, SubTree[1], TVI_LAST);
	
	tree.InsertItem(_T("1비트 입력 스위치"), 2, 2, SubTree[2], TVI_LAST);
	
	tree.InsertItem(_T("1비트 출력 램프"), 2, 2, SubTree[3], TVI_LAST);
	tree.InsertItem(_T("7-세그먼트"), 2, 2, SubTree[3], TVI_LAST);

	tree.InsertItem(_T("와이어"), 2, 2, SubTree[4], TVI_LAST);
	
}

#ifdef _DEBUG
void TreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void TreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// TreeView 메시지 처리기입니다.

void TreeView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	CStatusBar* pStatusBar = (CStatusBar *)(AfxGetMainWnd()->GetDlgItem(AFX_IDW_STATUS_BAR));
	pStatusBar->SetPaneText(0, str);

	if (str == _T("AND 게이트")){
		listvalue = 100;
	}
	else if (str == _T("OR 게이트")){
		listvalue = 101;
	}
	else if (str == _T("NOT 게이트")) {
		listvalue = 102;
	}
	else if (str == _T("NAND 게이트")) {
		listvalue = 103;
	}
	else if (str == _T("NOR 게이트")) {
		listvalue = 104;
	}
	else if (str == _T("XOR 게이트")) {
		listvalue = 105;
	}
	else if (str == _T("D-플립플롭")) {
		listvalue = 200;
	}
	else if (str == _T("JK-플립플롭")) {
		listvalue = 201;
	}
	else if (str == _T("T-플립플롭")) {
		listvalue = 202;
	}
	else if (str == _T("1비트 입력 스위치")) {
		listvalue = 300;
	}
	else if (str == _T("1비트 출력 램프")) {
		listvalue = 400;
	}
	else if (str == _T("와이어")) {
		listvalue = 500;
	}
	*pResult = 0;
}

void TreeView::init() {
	AfxMessageBox(_T("OK"));
}