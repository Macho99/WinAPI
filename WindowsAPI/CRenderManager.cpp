#include "framework.h"
#include "CRenderManager.h"
#include "WinAPI.h"

CRenderManager::CRenderManager()
{
	m_hdc = 0;
	m_hMemDC = 0;
	m_hBmp = 0;

	hPen = 0;
	typePen = PenType::Solid;
	widthPen = 1;
	colorPen = RGB(0, 0, 0);

	hBrush = 0;
	typeBrush = BrushType::Solid;
	colorBrush = RGB(255, 255, 255);
	typeText = TextType::Left;
}

CRenderManager::~CRenderManager()
{

}

void CRenderManager::Init()
{
	m_hdc = GetDC(hWnd);

	//���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hdc);
	m_hBmp = CreateCompatibleBitmap(m_hMemDC, WINSIZEX, WINSIZEY);

	//���� ��Ʈ���� �ʿ� ������ ������
	HBITMAP hOldBitmap = static_cast<HBITMAP>(SelectObject(m_hMemDC, m_hBmp));
	DeleteObject(hOldBitmap);

	SetPen(PenType::Solid);
	SetBrush(BrushType::Solid);
	SetText(TextType::Left);
}

void CRenderManager::Release()
{
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBmp);
	ReleaseDC(hWnd, m_hdc);

	m_hMemDC = 0;
	m_hBmp = 0;
	m_hdc = 0;

	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void CRenderManager::BeginDraw()
{
	//����۸� ��� ������� �ʱ�ȭ
	PatBlt(m_hMemDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
}

void CRenderManager::EndDraw()
{
	//������� �̹����� ����Ʈ ���۷� ����
	BitBlt(m_hdc, 0, 0, WINSIZEX, WINSIZEY,
		m_hMemDC, 0, 0, SRCCOPY);
	//StretchBlt: �̹����� �ø��ų� �ٿ��� ����
}

void CRenderManager::Line(float startX, float startY, float endX, float endY)
{
	//WinGDI ����
	//1. ���� ��� ���� �귯�ø� ����
	//2. �׸��� �۾� ����
	//3. ������� ���� �귯�÷� ����
	//Why? �ٸ� �������� ����ϴ� ��� ������ ��� ���

	HPEN prevPen = static_cast<HPEN> (SelectObject(m_hMemDC, hPen));
	HBRUSH prevBrush = static_cast<HBRUSH>(SelectObject(m_hMemDC, hBrush));

	MoveToEx(m_hMemDC, (int)startX, (int)startY, NULL);
	LineTo(m_hMemDC, (int)endX, (int)endY);

	SelectObject(m_hMemDC, prevPen);
	SelectObject(m_hMemDC, prevBrush);
}

void CRenderManager::Rect(float startX, float startY, float endX, float endY)
{
	HPEN prevPen = static_cast<HPEN> (SelectObject(m_hMemDC, hPen));
	HBRUSH prevBrush = static_cast<HBRUSH>(SelectObject(m_hMemDC, hBrush));

	Rectangle(m_hMemDC, (int)startX, (int)startY, (int)endX, (int)endY);

	SelectObject(m_hMemDC, prevPen);
	SelectObject(m_hMemDC, prevBrush);
}

void CRenderManager::Circle(float x, float y, float radius)
{
	HPEN prevPen = static_cast<HPEN> (SelectObject(m_hMemDC, hPen));
	HBRUSH prevBrush = static_cast<HBRUSH>(SelectObject(m_hMemDC, hBrush));

	Ellipse(m_hMemDC, (int)(x - radius), (int)(y - radius), 
		(int)(x + radius), (int)(y + radius));

	SelectObject(m_hMemDC, prevPen);
	SelectObject(m_hMemDC, prevBrush);
}

void CRenderManager::Text(float x, float y, wstring str)
{
	TextOut(m_hMemDC, (int)x, (int)y, str.c_str(), (int)str.size());
}

void CRenderManager::SetPen(PenType type, COLORREF color, int width)
{
	if (typePen == type && colorPen == color && widthPen == width) return;

	DeleteObject(hPen);

	typePen = type;
	colorPen = color;
	widthPen = width;

	int style;
	switch (type)
	{
	case PenType::Solid:
		style = PS_SOLID;
		break;
	case PenType::Dot:
		style = PS_DOT;
		break;
	case PenType::Dash:
		style = PS_DASH;
		break;
	case PenType::Null:
		style = PS_NULL;
		break;
	default:
		style = PS_SOLID;
		break;
	}
	hPen = CreatePen(style, width, color);
}

void CRenderManager::SetBrush(BrushType type, COLORREF color)
{
	if (typeBrush == type && colorBrush == color) return;

	DeleteObject(hBrush);

	typeBrush = type;
	colorBrush = color;

	switch (type)
	{
	case BrushType::Solid:
		hBrush = CreateSolidBrush(color);
		break;
	case BrushType::Null:
		//��ǻ�ʹ� ���� ǥ���� �Ұ��� -> Ư�� ó��
		hBrush = static_cast<HBRUSH> (GetStockObject(NULL_BRUSH));
		break;
	default:
		hBrush = CreateSolidBrush(color);
		break;
	}
}

void CRenderManager::SetText(TextType type)
{
	if (typeText == type) return;

	int align;
	switch (type)
	{
	case TextType::Left:
		align = TA_LEFT;
		break;
	case TextType::Center:
		align = TA_CENTER;
		break;
	case TextType::Right:
		align = TA_RIGHT;
		break;
	default:
		align = TA_LEFT;
		break;
	}
	SetTextAlign(m_hMemDC, align);
}
