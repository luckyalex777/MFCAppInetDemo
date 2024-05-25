
// MFCAppInetDemoView.cpp : implementation of the CMFCAppInetDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCAppInetDemo.h"
#endif

#include "MFCAppInetDemoDoc.h"
#include "MFCAppInetDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppInetDemoView

IMPLEMENT_DYNCREATE(CMFCAppInetDemoView, CView)

BEGIN_MESSAGE_MAP(CMFCAppInetDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCAppInetDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCAppInetDemoView construction/destruction

CMFCAppInetDemoView::CMFCAppInetDemoView() noexcept
{
	// TODO: add construction code here

}

CMFCAppInetDemoView::~CMFCAppInetDemoView()
{
}

BOOL CMFCAppInetDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCAppInetDemoView drawing

void CMFCAppInetDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFCAppInetDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCAppInetDemoView printing


void CMFCAppInetDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCAppInetDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCAppInetDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCAppInetDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCAppInetDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppInetDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppInetDemoView diagnostics

#ifdef _DEBUG
void CMFCAppInetDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppInetDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppInetDemoDoc* CMFCAppInetDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppInetDemoDoc)));
	return (CMFCAppInetDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppInetDemoView message handlers
