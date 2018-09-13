
// 14_MFC����View.cpp : CMy14_MFC����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "14_MFC����.h"
#endif

#include "14_MFC����Doc.h"
#include "14_MFC����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy14_MFC����View

IMPLEMENT_DYNCREATE(CMy14_MFC����View, CView)

BEGIN_MESSAGE_MAP(CMy14_MFC����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy14_MFC����View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy14_MFC����View ����/����

CMy14_MFC����View::CMy14_MFC����View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy14_MFC����View::~CMy14_MFC����View()
{
}

BOOL CMy14_MFC����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy14_MFC����View ����

void CMy14_MFC����View::OnDraw(CDC* /*pDC*/)
{
	CMy14_MFC����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy14_MFC����View ��ӡ


void CMy14_MFC����View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy14_MFC����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy14_MFC����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy14_MFC����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CMy14_MFC����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy14_MFC����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy14_MFC����View ���

#ifdef _DEBUG
void CMy14_MFC����View::AssertValid() const
{
	CView::AssertValid();
}

void CMy14_MFC����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy14_MFC����Doc* CMy14_MFC����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy14_MFC����Doc)));
	return (CMy14_MFC����Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy14_MFC����View ��Ϣ�������
