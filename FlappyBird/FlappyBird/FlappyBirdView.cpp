
// FlappyBirdView.cpp : CFlappyBirdView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FlappyBird.h"
#endif

#include "FlappyBirdDoc.h"
#include "FlappyBirdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlappyBirdView

IMPLEMENT_DYNCREATE(CFlappyBirdView, CView)

BEGIN_MESSAGE_MAP(CFlappyBirdView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFlappyBirdView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CFlappyBirdView 构造/析构

CFlappyBirdView::CFlappyBirdView()
	: bird_x(10)
	, bird_y(250)
	, bird_die(false)
	, up_stop1_x(600)
	, up_stop2_x(0)
	, down_stop_x(1100)
	, down_stop_flag(0)
	, cloud_x(1000)
	, cloud_y(50)
{
	// TODO: 在此处添加构造代码
	//m_Back.LoadBitmap(IDB_BACK);
	m_Bird.LoadBitmap(IDB_BIRD);
	m_Bird_Bg.LoadBitmap(IDB_BIRD_BG);


}

CFlappyBirdView::~CFlappyBirdView()
{
}

BOOL CFlappyBirdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式


	return CView::PreCreateWindow(cs);
}

// CFlappyBirdView 绘制

void CFlappyBirdView::OnDraw(CDC* pDC)
{
	CFlappyBirdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200,0,L"通过w和s键控制小鸟的上下来躲避管道吧！");

	CBrush NewBrush;
	CBrush *pOldBrush;
	NewBrush.CreateSolidBrush(RGB(200,228,242));
	pOldBrush=pDC->SelectObject(&NewBrush);
	pDC->Rectangle(0,348,900,600);
	pDC->SelectObject(pOldBrush);

	CBrush NewBrush2;
	CBrush *pOldBrush2;
	NewBrush2.CreateSolidBrush(RGB(0,0,242));
	pOldBrush2=pDC->SelectObject(&NewBrush2);
	pDC->Rectangle(900,348,1000,600);
	pDC->SelectObject(pOldBrush2);


	pDoc->getBirdY(bird_y);
	CBitmap bm;  bm.LoadBitmap(IDB_BIRD);
	CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bm);
	BITMAP info;  bm.GetBitmap(&info);
	pDC->BitBlt(bird_x,bird_y,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCCOPY);
	bm.DeleteObject();
	//
	CBitmap bm2;  
	bm2.LoadBitmap(IDB_UP_STOP);
	CDC MemDC2; 
	MemDC2.CreateCompatibleDC(pDC);
	MemDC2.SelectObject(&bm2);
	BITMAP info2;  
	bm2.GetBitmap(&info2);
	pDC->BitBlt(up_stop1_x,0,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
	bm2.DeleteObject();
	//
	CBitmap bm3;  
	bm3.LoadBitmap(IDB_DOWN_STOP);
	CDC MemDC3; 
	MemDC3.CreateCompatibleDC(pDC);
	MemDC3.SelectObject(&bm3);
	BITMAP info3;  
	bm3.GetBitmap(&info3);
	pDC->BitBlt(down_stop_x,248,info3.bmWidth, info3.bmHeight,&MemDC3,0,0,SRCCOPY);
	bm3.DeleteObject();
	///============///
	if(!bird_die)
	{
		SetTimer(1,6,NULL);
		SetTimer(2,10,NULL);
		SetTimer(3,12,NULL);
	}
	else
	{
		pDC->TextOutW(200,200,L"You Lost!Try Again!");
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);KillTimer(4);
		//pDC->BitBlt(bird_x,bird_y,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCCOPY);
	}


}


// CFlappyBirdView 打印


void CFlappyBirdView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFlappyBirdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFlappyBirdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFlappyBirdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFlappyBirdView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFlappyBirdView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFlappyBirdView 诊断

#ifdef _DEBUG
void CFlappyBirdView::AssertValid() const
{
	CView::AssertValid();
}

void CFlappyBirdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlappyBirdDoc* CFlappyBirdView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlappyBirdDoc)));
	return (CFlappyBirdDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlappyBirdView 消息处理程序


void CFlappyBirdView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC=GetDC();
	if(nIDEvent==1)
	{
		pDC->TextOutW(200,0,L"通过w和s键控制小鸟的上下来躲避管道吧！");

		CBitmap bm;  bm.LoadBitmap(IDB_BIRD_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(bird_x,bird_y,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();

		//
		CBitmap bm3;  
		bm3.LoadBitmap(IDB_CLOUD_BG);
		CDC MemDC3; 
		MemDC3.CreateCompatibleDC(pDC);
		MemDC3.SelectObject(&bm3);
		BITMAP info3;  
		bm3.GetBitmap(&info3);
		pDC->BitBlt(cloud_x,cloud_y,info3.bmWidth, info3.bmHeight,&MemDC3,0,0,SRCCOPY);
		bm3.DeleteObject();

		srand((unsigned)time(NULL));
		bird_x+=0.1;
		bird_y+=0.5;
		cloud_x-=3;
		cloud_y+=3-rand()%6;
		//if(cloud_y<=0)
			//cloud_y+=10;
		if(cloud_y>60)
			cloud_y-=20;

		CBitmap bm2;  
		bm2.LoadBitmap(IDB_BIRD);
		CDC MemDC2; 
		MemDC2.CreateCompatibleDC(pDC);
		MemDC2.SelectObject(&bm2);
		BITMAP info2;  
		bm2.GetBitmap(&info2);
		pDC->BitBlt(bird_x,bird_y,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
		bm2.DeleteObject();
		
		///
		if(cloud_x>=-160)
		{
			//up_stop1_x-=5;
			CBitmap bm4;  
			bm4.LoadBitmap(IDB_CLOUD);
			CDC MemDC4; 
			MemDC4.CreateCompatibleDC(pDC);
			MemDC4.SelectObject(&bm4);
			BITMAP info4;  
			bm4.GetBitmap(&info4);
			pDC->BitBlt(cloud_x,cloud_y,info4.bmWidth, info4.bmHeight,&MemDC4,0,0,SRCCOPY);
			bm4.DeleteObject();
		}
		else
		{
			srand((unsigned)time(NULL));
			cloud_x = up_stop1_x+700+rand()%200;
			cloud_y=40;
		}
		///
		if(bird_x>=900)
		{
			pDC->TextOutW(200,200,L"You WIN!Try Again!");
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			KillTimer(4);
		}
		if(bird_x+48>=up_stop1_x-5 && bird_x+48<=up_stop1_x+165 && bird_y<=212)//撞柱死亡
		{
			pDC->TextOutW(200,200,L"You Lost!Try Again!");
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);KillTimer(4);
		}
		if(bird_x+48>=down_stop_x-5 && bird_x+48<=down_stop_x+165 && bird_y>=197 &&down_stop_flag==0)//撞下面的矮柱死亡
		{
			pDC->TextOutW(200,200,L"You Lost!Try Again!");
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);KillTimer(4);
		}
		if(bird_x+48>=down_stop_x-5 && bird_x+48<=down_stop_x+165 && bird_y>=97 &&down_stop_flag==1)//撞下面的高柱死亡
		{
			pDC->TextOutW(200,200,L"You Lost!Try Again!");
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);KillTimer(4);
		}
		/*if(bird_die)
		{
			//pDC->TextOutW(0,0,L"You Lost!Try Again!");
			//pDC->BitBlt(bird_x,bird_y,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
			KillTimer(1);
		}*/
	}
	if(nIDEvent==2)
	{
		CBitmap bm;  bm.LoadBitmap(IDB_UP_STOP_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(up_stop1_x,0,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();
		//
		if(up_stop1_x>=-160)
		{
			up_stop1_x-=5;
			CBitmap bm2;  
			bm2.LoadBitmap(IDB_UP_STOP);
			CDC MemDC2; 
			MemDC2.CreateCompatibleDC(pDC);
			MemDC2.SelectObject(&bm2);
			BITMAP info2;  
			bm2.GetBitmap(&info2);
			pDC->BitBlt(up_stop1_x,0,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
			bm2.DeleteObject();
		}
		else
		{
			srand((unsigned)time(NULL));
			up_stop1_x = 900+rand()%500;
		}
	}
	if(nIDEvent==3)
	{
		CBitmap bm;  bm.LoadBitmap(IDB_DOWN_STOP_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(down_stop_x,248,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();
		//
		if(down_stop_x>=-160)
		{
			down_stop_x-=5;
			CBitmap bm2;  
			bm2.LoadBitmap(IDB_DOWN_STOP);
			CDC MemDC2; 
			MemDC2.CreateCompatibleDC(pDC);
			MemDC2.SelectObject(&bm2);
			BITMAP info2;  
			bm2.GetBitmap(&info2);
			pDC->BitBlt(down_stop_x,248,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
			bm2.DeleteObject();
		}
		else
		{
			srand((unsigned)time(NULL));
			down_stop_x = up_stop1_x+400+rand()%500;
			int ranflg=rand()%3;
			if(ranflg<=1)
			{
				down_stop_flag=1;
				KillTimer(3);
				SetTimer(4,10,NULL);
			}
		}
	}
	if(nIDEvent==4)
	{
		CBitmap bm;  bm.LoadBitmap(IDB_DOWN_STOP2_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(down_stop_x,148,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();
		//
		if(down_stop_x>=-160)
		{
			down_stop_x-=5;
			CBitmap bm2;  
			bm2.LoadBitmap(IDB_DOWN_STOP2);
			CDC MemDC2; 
			MemDC2.CreateCompatibleDC(pDC);
			MemDC2.SelectObject(&bm2);
			BITMAP info2;  
			bm2.GetBitmap(&info2);
			pDC->BitBlt(down_stop_x,148,info2.bmWidth, info2.bmHeight,&MemDC2,0,0,SRCCOPY);
			bm2.DeleteObject();
		}
		else
		{
			srand((unsigned)time(NULL));
			down_stop_x = up_stop1_x+600+rand()%100;
			int ranflg=rand()%3;
			if(ranflg<=1)
			{
				down_stop_flag=0;
				KillTimer(4);
				SetTimer(3,10,NULL);
			}
		}
	}

	CView::OnTimer(nIDEvent);
}


void CFlappyBirdView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	KillTimer(1);
}


void CFlappyBirdView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nChar=='w')
	{
		CDC *pDC=GetDC();
		CBitmap bm;  bm.LoadBitmap(IDB_BIRD_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(bird_x,bird_y,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();

		KillTimer(1);
		if(!bird_die)
		{
			bird_y-=45;
			bird_x+=9;
		}
		if(bird_y<=0 || bird_y>=300)
		{
			pDC->TextOutW(200,200,L"You Lost!Try Again!");
			bird_die=true;
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);KillTimer(4);
		    return;
		}
		CFlappyBirdDoc* pDoc=GetDocument();
		pDoc->setBirdY(bird_y);
		SetTimer(1,6,NULL);
	}
	else if(nChar=='s')
	{
		CDC *pDC=GetDC();
		CBitmap bm;  bm.LoadBitmap(IDB_BIRD_BG);
		CDC MemDC;  MemDC.CreateCompatibleDC(pDC);
		MemDC.SelectObject(&bm);
		BITMAP info;  bm.GetBitmap(&info);
		pDC->BitBlt(bird_x,bird_y,info.bmWidth, info.bmHeight,&MemDC,0,0,SRCPAINT);
		bm.DeleteObject();

		KillTimer(1);
		if(!bird_die)
		{
			bird_x+=2;
			bird_y+=40;
		}
		if(bird_y>=300 || bird_y <= 0)
		{
			pDC->TextOutW(200,200,L"You Lost!Try Again!");
			bird_die=true;
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);KillTimer(4);
		    return;
		}
		CFlappyBirdDoc* pDoc=GetDocument();
		pDoc->setBirdY(bird_y);
		SetTimer(1,6,NULL);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}
