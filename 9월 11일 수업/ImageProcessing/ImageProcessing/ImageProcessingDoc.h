
// ImageProcessingDoc.h : CImageProcessingDoc Ŭ������ �������̽�
//


#pragma once


class CImageProcessingDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageProcessingDoc();
	DECLARE_DYNCREATE(CImageProcessingDoc)

// Ư���Դϴ�.
public:
	unsigned char* m_InputImage;
	int m_width, m_height, m_size;

	unsigned char* m_OutputImage;
	int m_Re_width, m_Re_height, m_Re_size;

// �۾��Դϴ�.
public:
	void OnDownSampling();
	void OnUpSampling();
// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CImageProcessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};
