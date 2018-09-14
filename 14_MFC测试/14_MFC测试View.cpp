
// 14_MFC测试View.cpp : CMy14_MFC测试View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "14_MFC测试.h"
#endif

#include "14_MFC测试Doc.h"
#include "14_MFC测试View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy14_MFC测试View

IMPLEMENT_DYNCREATE(CMy14_MFC测试View, CView)

BEGIN_MESSAGE_MAP(CMy14_MFC测试View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy14_MFC测试View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy14_MFC测试View 构造/析构

CMy14_MFC测试View::CMy14_MFC测试View()
{
	// TODO:  在此处添加构造代码

}

CMy14_MFC测试View::~CMy14_MFC测试View()
{
}

BOOL CMy14_MFC测试View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy14_MFC测试View 绘制

void CMy14_MFC测试View::OnDraw(CDC* /*pDC*/)
{
	CMy14_MFC测试Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy14_MFC测试View 打印


void CMy14_MFC测试View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy14_MFC测试View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy14_MFC测试View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy14_MFC测试View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CMy14_MFC测试View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy14_MFC测试View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy14_MFC测试View 诊断

#ifdef _DEBUG
void CMy14_MFC测试View::AssertValid() const
{
	CView::AssertValid();
}

void CMy14_MFC测试View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy14_MFC测试Doc* CMy14_MFC测试View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy14_MFC测试Doc)));
	return (CMy14_MFC测试Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy14_MFC测试View 消息处理程序
