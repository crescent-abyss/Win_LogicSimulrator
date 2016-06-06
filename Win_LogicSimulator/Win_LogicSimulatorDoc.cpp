
// Win_LogicSimulatorDoc.cpp : CWin_LogicSimulatorDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Win_LogicSimulator.h"
#endif

#include "Win_LogicSimulatorDoc.h"
#include "TreeView.h"
#include "Win_LogicSimulatorView.h"
#include "LogicView.h"
#include "MainFrm.h"
#include <afxtempl.h>
#include <afxcoll.h>
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWin_LogicSimulatorDoc

IMPLEMENT_DYNCREATE(CWin_LogicSimulatorDoc, CDocument)

BEGIN_MESSAGE_MAP(CWin_LogicSimulatorDoc, CDocument)
END_MESSAGE_MAP()


// CWin_LogicSimulatorDoc ����/�Ҹ�

CWin_LogicSimulatorDoc::CWin_LogicSimulatorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
}

CWin_LogicSimulatorDoc::~CWin_LogicSimulatorDoc()
{
}

BOOL CWin_LogicSimulatorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	listvalue = -1;

	for (int i = 0; i < 100; ++i) {
		m_ptBitmapX[i] = NULL;
		m_ptBitmapY[i] = NULL;
		bitmap_name[i] = NULL;
		input_data[i] = NULL;
	}
	i = 0;
	current = 0;
	max = 0;
	input_count = 0;
	test = 0;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.


	return TRUE;
}




// CWin_LogicSimulatorDoc serialization

void CWin_LogicSimulatorDoc::Serialize(CArchive& ar)
{

	if (ar.IsStoring())
	{
		m_BitmapX.SetSize(max);
		m_BitmapY.SetSize(max);
		m_BitmapName.SetSize(max);
		
		ar << i << current << max << input_count << test;

		for (int i = 0; i < m_BitmapX.GetSize(); ++i) {
			m_BitmapX[i] = m_ptBitmapX[i];
		}
		for (int i = 0; i < m_BitmapY.GetSize(); ++i) {
			m_BitmapY[i] = m_ptBitmapY[i];
		}
		for (int i = 0; i < m_BitmapName.GetSize(); ++i) {
			m_BitmapName[i] = bitmap_name[i];
		}

		m_BitmapX.Serialize(ar);
		m_BitmapY.Serialize(ar);
		m_BitmapName.Serialize(ar);
		

		//m_GateName.Serialize(ar);
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{

		for (int i = 0; i < 100; ++i) {
			m_ptBitmapX[i] = NULL;
			m_ptBitmapY[i] = NULL;
			bitmap_name[i] = NULL;
		}
		ar >> i >> current >> max >> input_count >> test;

		m_BitmapX.SetSize(max);
		m_BitmapY.SetSize(max);
		m_BitmapName.SetSize(max);

		m_BitmapX.Serialize(ar);
		m_BitmapY.Serialize(ar);
		m_BitmapName.Serialize(ar);
		
		//m_GateName.Serialize(ar);

		for (int i = 0; i < m_BitmapX.GetSize(); ++i) {
			m_ptBitmapX[i] = m_BitmapX[i];
		}
		for (int i = 0; i < m_BitmapY.GetSize(); ++i) {
			m_ptBitmapY[i] = m_BitmapY[i];
		}
		for (int i = 0; i < m_BitmapName.GetSize(); ++i) {
			bitmap_name[i] = m_BitmapName[i];
		}
		
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CWin_LogicSimulatorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CWin_LogicSimulatorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWin_LogicSimulatorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWin_LogicSimulatorDoc ����

#ifdef _DEBUG
void CWin_LogicSimulatorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWin_LogicSimulatorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWin_LogicSimulatorDoc ���