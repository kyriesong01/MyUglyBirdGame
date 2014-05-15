
// FlappyBirdView.h : CFlappyBirdView ��Ľӿ�
//

#pragma once


class CFlappyBirdView : public CView
{
protected: // �������л�����
	CFlappyBirdView();
	DECLARE_DYNCREATE(CFlappyBirdView)

// ����
public:
	CFlappyBirdDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFlappyBirdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
  CBitmap m_Back;
  CBitmap m_Bird;
  CBitmap m_Bird_Bg;

  double bird_x;
  double bird_y;
public:
	afx_msg void OnDestroy();
	//BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	bool bird_die;
	int up_stop1_x;
	int up_stop2_x;
	int down_stop_x;
	int down_stop_flag;
	int cloud_x;
	int cloud_y;
};

#ifndef _DEBUG  // FlappyBirdView.cpp �еĵ��԰汾
inline CFlappyBirdDoc* CFlappyBirdView::GetDocument() const
   { return reinterpret_cast<CFlappyBirdDoc*>(m_pDocument); }
#endif

