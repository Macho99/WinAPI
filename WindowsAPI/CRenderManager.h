#pragma once
class CCore;
class CRenderManager : public SingleTon<CRenderManager>
{
	friend SingleTon<CRenderManager>;
	friend CCore;
private:
	HDC m_hdc;		//게임 화면의 메인DC, 프론트버퍼(결과화면)에 그릴 DC
	HDC m_hMemDC;	//임시 화면의 DC, 백버퍼(임시화면)에 그릴 DC
	HBITMAP m_hBmp;	//임시 화면의 그림, 백버퍼용 비트맵(이미지)

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

