#pragma once


// TreeView ���Դϴ�.

class TreeView : public CTreeView
{
	DECLARE_DYNCREATE(TreeView)

protected:
	TreeView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~TreeView();

	// Ư���Դϴ�.
public:
	
	// �۾��Դϴ�.
public:

	// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.


#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


