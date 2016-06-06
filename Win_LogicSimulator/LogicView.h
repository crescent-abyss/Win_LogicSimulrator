#pragma once


// LogicView 뷰입니다.

class LogicView : public CView
{
	DECLARE_DYNCREATE(LogicView)

protected:
	LogicView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~LogicView();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
	void LogicView::OnLButtonDown(UINT nFlags, CPoint point);
	void LogicView::OnRButtonDown(UINT nFlags, CPoint point);
	void LogicView::OnMouseMove(UINT nFlags, CPoint point);
	void LogicView::OnLButtonUP(UINT nFlags, CPoint point);
	void LogicView::OnButtonClicked(void);
	void LogicView::OnButtonClicked_CLock(void);
	void LogicView::BYTE_image_rotate_90();
	
	BOOL m_bDrawMode; // 현재 그리기 모드인지를 판단할 때 사용한다. 
	CPoint m_ptStart, m_ptEnd; // 시작점과 끝점을 저장할 때 사용한다. 
	
	bool move;
	int startx;
	int starty;
	CPoint m_pos;			//좌표값
	CString Clip_gateName;
	int Clip_bitmap;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnUndo();
	afx_msg void OnRedo();
	afx_msg void Cut();
	afx_msg void Paste();
	afx_msg void Copy();
};


