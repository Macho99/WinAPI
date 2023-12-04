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
	HDC		m_hdc;		//���� ȭ���� ����DC, ����Ʈ����(���ȭ��)�� �׸� DC
	HDC		m_hMemDC;	//�ӽ� ȭ���� DC, �����(�ӽ�ȭ��)�� �׸� DC
	HBITMAP m_hBmp;	//�ӽ� ȭ���� �׸�, ����ۿ� ��Ʈ��(�̹���)

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