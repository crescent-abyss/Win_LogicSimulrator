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
	void LogicView::OnButtonClicked(void);
	bool move;
	int startx;
	int starty;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


