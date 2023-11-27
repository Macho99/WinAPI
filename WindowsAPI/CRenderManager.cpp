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

	//더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hdc);
	m_hBmp = CreateCompatibleBitmap(m_hMemDC, WINSIZEX, WINSIZEY);

	//이전 비트맵은 필요 없으니 지워줌
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
	//백버퍼를 모두 흰색으로 초기화
	PatBlt(m_hMemDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
}

void CRenderManager::EndDraw()
{
	//백버퍼의 이미지를 프론트 버퍼로 복사
	BitBlt(m_hdc, 0, 0, WINSIZEX, WINSIZEY,
		m_hMemDC, 0, 0, SRCCOPY);
	//StretchBlt: 이미지를 늘리거나 줄여서 복사
}

void CRenderManager::Line(float startX, float startY, float endX, float endY)
{
	//WinGDI 사용법
	//1. 현재 펜과 현재 브러시를 선택
	//2. 그리기 작업 진행
	//3. 이전펜과 이전 브러시로 복구
	//Why? 다른 영역에서 사용하다 잠시 빌려쓴 경우 대비

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
		//컴퓨터는 투명 표현이 불가능 -> 특별 처리
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
