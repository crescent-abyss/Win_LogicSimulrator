
#pragma once


// ListView ���Դϴ�.

class ListView : public CView
{
	DECLARE_DYNCREATE(ListView)

protected:
	ListView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~ListView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void ListView::OnInitialUpdate();
	BOOL ListView::OnCommand(WPARAM wParam, LPARAM lParam);
	CButton *pButton;
	CButton *pButton2;
	CButton *pButton3;
	CButton *pTitle;
	bool Flag = TRUE;

	
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


