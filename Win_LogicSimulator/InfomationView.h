#pragma once


// InfomationView ���Դϴ�.

class InfomationView : public CView
{
	DECLARE_DYNCREATE(InfomationView)

protected:
	
public:
	int time = 0;
	InfomationView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~InfomationView();
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


