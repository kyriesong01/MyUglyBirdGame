
// FlappyBirdView.h : CFlappyBirdView 类的接口
//

#pragma once


class CFlappyBirdView : public CView
{
protected: // 仅从序列化创建
	CFlappyBirdView();
	DECLARE_DYNCREATE(CFlappyBirdView)

// 特性
public:
	CFlappyBirdDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFlappyBirdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // FlappyBirdView.cpp 中的调试版本
inline CFlappyBirdDoc* CFlappyBirdView::GetDocument() const
   { return reinterpret_cast<CFlappyBirdDoc*>(m_pDocument); }
#endif

