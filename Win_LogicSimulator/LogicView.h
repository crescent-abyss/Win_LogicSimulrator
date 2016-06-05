#pragma once


// LogicView ���Դϴ�.

class LogicView : public CView
{
	DECLARE_DYNCREATE(LogicView)

protected:
	LogicView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~LogicView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void LogicView::OnLButtonDown(UINT nFlags, CPoint point);
	void LogicView::OnRButtonDown(UINT nFlags, CPoint point);
	void LogicView::OnMouseMove(UINT nFlags, CPoint point);
	void LogicView::OnLButtonUP(UINT nFlags, CPoint point);
	void LogicView::OnButtonClicked(void);
	void LogicView::OnButtonClicked_CLock(void);
	void LogicView::BYTE_image_rotate_90();
	BOOL m_bDrawMode; // ���� �׸��� ��������� �Ǵ��� �� ����Ѵ�. 
	CPoint m_ptStart, m_ptEnd; // �������� ������ ������ �� ����Ѵ�. 
	
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
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};


