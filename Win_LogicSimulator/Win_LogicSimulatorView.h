
// Win_LogicSimulatorView.h : CWin_LogicSimulatorView Ŭ������ �������̽�
//

#pragma once


class CWin_LogicSimulatorView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWin_LogicSimulatorView();
	DECLARE_DYNCREATE(CWin_LogicSimulatorView)

// Ư���Դϴ�.
public:
	CWin_LogicSimulatorDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CWin_LogicSimulatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Win_LogicSimulatorView.cpp�� ����� ����
inline CWin_LogicSimulatorDoc* CWin_LogicSimulatorView::GetDocument() const
   { return reinterpret_cast<CWin_LogicSimulatorDoc*>(m_pDocument); }
#endif

