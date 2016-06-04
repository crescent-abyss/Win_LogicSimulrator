// TreeView.cpp : ���� �����Դϴ�.
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

	// �̹��� ����Ʈ ������ �ʱ�ȭ
	CImageList il;
	il.Create(IDR_Win_LogicSimulaTYPE, 16, 1, RGB(255, 255, 255));

	// �̹��� ����Ʈ ����
	CTreeCtrl& tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	// �׸� �߰�
	/* 1-���� �ʱ�ȭ */
	HTREEITEM LogicTree = tree.InsertItem(_T("��ȸ��"), 0, 0, TVI_ROOT, TVI_LAST);
	HTREEITEM LibTree = tree.InsertItem(_T("���̺귯��"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-���� �ʱ�ȭ */
	HTREEITEM SubTree[5];
	CString Tree[] = {
		_T("������Ʈ"), _T("�ø��÷�(FF)"), _T("�Է�"), _T("���"), _T("���̾�")
	};
	for (int i = 0; i<5; i++)
		SubTree[i] = tree.InsertItem(Tree[i], 1, 1, LogicTree, TVI_LAST);

	/* 3-���� �ʱ�ȭ */
	tree.InsertItem(_T("AND ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("OR ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NOT ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NAND ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("NOR ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);
	tree.InsertItem(_T("XOR ����Ʈ"), 2, 2, SubTree[0], TVI_LAST);

	tree.InsertItem(_T("D-�ø��÷�"), 2, 2, SubTree[1], TVI_LAST);
	tree.InsertItem(_T("JK-�ø��÷�"), 2, 2, SubTree[1], TVI_LAST);
	tree.InsertItem(_T("T-�ø��÷�"), 2, 2, SubTree[1], TVI_LAST);
	
	tree.InsertItem(_T("1��Ʈ �Է� ����ġ"), 2, 2, SubTree[2], TVI_LAST);
	
	tree.InsertItem(_T("1��Ʈ ��� ����"), 2, 2, SubTree[3], TVI_LAST);
	tree.InsertItem(_T("7-���׸�Ʈ"), 2, 2, SubTree[3], TVI_LAST);

	tree.InsertItem(_T("���̾�"), 2, 2, SubTree[4], TVI_LAST);
	
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


// TreeView �޽��� ó�����Դϴ�.

void TreeView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	CStatusBar* pStatusBar = (CStatusBar *)(AfxGetMainWnd()->GetDlgItem(AFX_IDW_STATUS_BAR));
	pStatusBar->SetPaneText(0, str);

	if (str == _T("AND ����Ʈ")){
		listvalue = 100;
	}
	else if (str == _T("OR ����Ʈ")){
		listvalue = 101;
	}
	else if (str == _T("NOT ����Ʈ")) {
		listvalue = 102;
	}
	else if (str == _T("NAND ����Ʈ")) {
		listvalue = 103;
	}
	else if (str == _T("NOR ����Ʈ")) {
		listvalue = 104;
	}
	else if (str == _T("XOR ����Ʈ")) {
		listvalue = 105;
	}
	else if (str == _T("D-�ø��÷�")) {
		listvalue = 200;
	}
	else if (str == _T("JK-�ø��÷�")) {
		listvalue = 201;
	}
	else if (str == _T("T-�ø��÷�")) {
		listvalue = 202;
	}
	else if (str == _T("1��Ʈ �Է� ����ġ")) {
		listvalue = 300;
	}
	else if (str == _T("1��Ʈ ��� ����")) {
		listvalue = 400;
	}
	else if (str == _T("���̾�")) {
		listvalue = 500;
	}
	*pResult = 0;
}

void TreeView::init() {
	AfxMessageBox(_T("OK"));
}