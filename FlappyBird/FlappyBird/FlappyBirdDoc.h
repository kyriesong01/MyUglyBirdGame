
// FlappyBirdDoc.h : CFlappyBirdDoc ��Ľӿ�
//


#pragma once


class CFlappyBirdDoc : public CDocument
{
protected: // �������л�����
	CFlappyBirdDoc();
	DECLARE_DYNCREATE(CFlappyBirdDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CFlappyBirdDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void setBirdY(double& b_y);
	void getBirdY(double& b_y);
private:
	double m_bird_y;
};
