
// ImageProcessingView.cpp : CImageProcessingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include "ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingView

IMPLEMENT_DYNCREATE(CImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CImageProcessingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_COMMAND(ID_UPSAMPLING, &CImageProcessingView::OnUpsampling)
ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessingView::OnDownSampling)
//ON_COMMAND(ID_UPSAMPLING, &CImageProcessingView::OnUpSampling)
ON_COMMAND(ID_UP_SAMPLING, &CImageProcessingView::OnUpSampling)
END_MESSAGE_MAP()

// CImageProcessingView ����/�Ҹ�

CImageProcessingView::CImageProcessingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CImageProcessingView::~CImageProcessingView()
{
}

BOOL CImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CImageProcessingView �׸���

void CImageProcessingView::OnDraw(CDC* pDC)
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i<pDoc->m_height; i++) {
		for (j = 0; j<pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i*pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	// ��ҵ� ���� ���
	for (i = 0; i<pDoc->m_Re_height; i++) {
		for (j = 0; j<pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

}


// CImageProcessingView �μ�


void CImageProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessingView ����

#ifdef _DEBUG
void CImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessingDoc* CImageProcessingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingDoc)));
	return (CImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingView �޽��� ó����


//void CImageProcessingView::OnUpsampling()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//}


void CImageProcessingView::OnDownSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CImageProcessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
	pDoc->OnDownSampling(); // Doc Ŭ������ OnDownSampling �Լ� ȣ��
	Invalidate(TRUE); // ȭ�� ����

}


//void CImageProcessingView::OnUpSampling()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	CImageProcessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
//	pDoc->OnUpSampling(); // Doc Ŭ������ OnUpSampling �Լ� ȣ��
//	Invalidate(TRUE); // ȭ�� ����
//
//}


void CImageProcessingView::OnUpSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CImageProcessingDoc* pDoc = GetDocument(); //Doc Ŭ���� ����
	pDoc->OnUpSampling(); // Doc Ŭ������ OnUpSampling �Լ� ȣ��
	Invalidate(TRUE); // ȭ�� ����
}
