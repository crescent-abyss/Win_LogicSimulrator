
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
	
	
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


