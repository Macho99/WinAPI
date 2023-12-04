#pragma once
class CCore;

enum class PenType { Solid, Dot, Dash, Null };
enum class BrushType { Solid, Null };
enum class TextType { Left, Center, Right };

class CRenderManager : public SingleTon<CRenderManager>
{
	friend SingleTon<CRenderManager>;
	friend CCore;
private:
	HDC		m_hdc;		//게임 화면의 메인DC, 프론트버퍼(결과화면)에 그릴 DC
	HDC		m_hMemDC;	//임시 화면의 DC, 백버퍼(임시화면)에 그릴 DC
	HBITMAP m_hBmp;	//임시 화면의 그림, 백버퍼용 비트맵(이미지)

	HPEN	hPen;
	int		widthPen;
	PenType typePen;
	COLORREF colorPen;

	HBRUSH hBrush;
	BrushType typeBrush;
	COLORREF colorBrush;

	TextType typeText;

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

	void SetPen(PenType type = PenType::Solid, COLORREF color = RGB(0, 0, 0), int width = 1);
	void SetBrush(BrushType type = BrushType::Null, COLORREF color = RGB(255, 255, 255));
	void SetText(TextType type);
};

#define RENDER CRenderManager::GetInstance()