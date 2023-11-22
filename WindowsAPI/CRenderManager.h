#pragma once
class CCore;
class CRenderManager : public SingleTon<CRenderManager>
{
	friend SingleTon<CRenderManager>;
	friend CCore;
private:
	HDC m_hdc;		//���� ȭ���� ����DC, ����Ʈ����(���ȭ��)�� �׸� DC
	HDC m_hMemDC;	//�ӽ� ȭ���� DC, �����(�ӽ�ȭ��)�� �׸� DC
	HBITMAP m_hBmp;	//�ӽ� ȭ���� �׸�, ����ۿ� ��Ʈ��(�̹���)

	CRenderManager();
	virtual ~CRenderManager();

	void Init();
	void Release();
	void BeginDraw();
	void EndDraw();

public:
	void Line(float startX, float startY, float endX, float endY);
	void Rect(float startX, float startY, float endX, float endY);
	void Circle(float x, float y, float radius);
	void Text(float x, float y, wstring str);
};

#define RENDER CRenderManager::GetInstance()

