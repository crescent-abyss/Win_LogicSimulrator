#pragma once


// InfomationView ���Դϴ�.

class InfomationView : public CView
{
	DECLARE_DYNCREATE(InfomationView)

protected:
	InfomationView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~InfomationView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void InfomationView::DrawOption();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


