
#pragma once


// ListView 뷰입니다.

class ListView : public CView
{
	DECLARE_DYNCREATE(ListView)

protected:
	ListView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~ListView();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
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


