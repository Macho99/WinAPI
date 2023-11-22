#include "framework.h"
#include "CRenderManager.h"
#include "WinAPI.h"

CRenderManager::CRenderManager()
{
	m_hdc = 0;
	m_hMemDC = 0;
	m_hBmp = 0;
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
}

void CRenderManager::Release()
{
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBmp);
	ReleaseDC(hWnd, m_hdc);

	m_hMemDC = 0;
	m_hBmp = 0;
	m_hdc = 0;
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
	MoveToEx(m_hMemDC, (int)startX, (int)startY, NULL);
	LineTo(m_hMemDC, (int)endX, (int)endY);
}

void CRenderManager::Rect(float startX, float startY, float endX, float endY)
{
	Rectangle(m_hMemDC, (int)startX, (int)startY, (int)endX, (int)endY);
}

void CRenderManager::Circle(float x, float y, float radius)
{
	Ellipse(m_hMemDC, (int)(x - radius), (int)(y - radius), 
		(int)(x + radius), (int)(y + radius));
}

void CRenderManager::Text(float x, float y, wstring str)
{
	TextOut(m_hMemDC, (int)x, (int)y, str.c_str(), (int)str.size());
}
