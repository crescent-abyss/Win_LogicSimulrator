
// Win_LogicSimulatorDoc.cpp : CWin_LogicSimulatorDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CWin_LogicSimulatorDoc 생성/소멸

CWin_LogicSimulatorDoc::CWin_LogicSimulatorDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
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

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.


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
		// TODO: 여기에 저장 코드를 추가합니다.
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
		
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CWin_LogicSimulatorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CWin_LogicSimulatorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CWin_LogicSimulatorDoc 진단

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


// CWin_LogicSimulatorDoc 명령