
// 14_MFC����View.h : CMy14_MFC����View ��Ľӿ�
//

#pragma once


class CMy14_MFC����View : public CView
{
protected: // �������л�����
	CMy14_MFC����View();
	DECLARE_DYNCREATE(CMy14_MFC����View)

// ����
public:
	CMy14_MFC����Doc* GetDocument() const;

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
	virtual ~CMy14_MFC����View();
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
};

#ifndef _DEBUG  // 14_MFC����View.cpp �еĵ��԰汾
inline CMy14_MFC����Doc* CMy14_MFC����View::GetDocument() const
   { return reinterpret_cast<CMy14_MFC����Doc*>(m_pDocument); }
#endif

