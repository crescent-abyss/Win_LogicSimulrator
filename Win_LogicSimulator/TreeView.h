#pragma once


// TreeView 뷰입니다.

class TreeView : public CTreeView
{
	DECLARE_DYNCREATE(TreeView)

protected:
	TreeView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~TreeView();

	// 특성입니다.
public:
	
	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.


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


