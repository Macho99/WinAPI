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

	//���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hdc);
	m_hBmp = CreateCompatibleBitmap(m_hMemDC, WINSIZEX, WINSIZEY);

	//���� ��Ʈ���� �ʿ� ������ ������
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
