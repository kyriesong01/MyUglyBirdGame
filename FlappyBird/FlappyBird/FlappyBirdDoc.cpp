
// FlappyBirdDoc.cpp : CFlappyBirdDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "FlappyBird.h"
#endif

#include "FlappyBirdDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFlappyBirdDoc

IMPLEMENT_DYNCREATE(CFlappyBirdDoc, CDocument)

BEGIN_MESSAGE_MAP(CFlappyBirdDoc, CDocument)
END_MESSAGE_MAP()


// CFlappyBirdDoc ����/����

CFlappyBirdDoc::CFlappyBirdDoc()
	: m_bird_y(150)
{
	// TODO: �ڴ����һ���Թ������

}

CFlappyBirdDoc::~CFlappyBirdDoc()
{
}

BOOL CFlappyBirdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CFlappyBirdDoc ���л�

void CFlappyBirdDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<m_bird_y;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>m_bird_y;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CFlappyBirdDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CFlappyBirdDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CFlappyBirdDoc::SetSearchContent(const CString& value)
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

// CFlappyBirdDoc ���

#ifdef _DEBUG
void CFlappyBirdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFlappyBirdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFlappyBirdDoc ����


void CFlappyBirdDoc::setBirdY(double& b_y)
{
	m_bird_y=b_y;
}


void CFlappyBirdDoc::getBirdY(double& b_y)
{
	b_y=m_bird_y;
}
