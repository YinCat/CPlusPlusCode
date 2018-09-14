
// 14_MFC测试View.h : CMy14_MFC测试View 类的接口
//

#pragma once


class CMy14_MFC测试View : public CView
{
protected: // 仅从序列化创建
	CMy14_MFC测试View();
	DECLARE_DYNCREATE(CMy14_MFC测试View)

// 特性
public:
	CMy14_MFC测试Doc* GetDocument() const;

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
	virtual ~CMy14_MFC测试View();
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
};

#ifndef _DEBUG  // 14_MFC测试View.cpp 中的调试版本
inline CMy14_MFC测试Doc* CMy14_MFC测试View::GetDocument() const
   { return reinterpret_cast<CMy14_MFC测试Doc*>(m_pDocument); }
#endif

