#include "framework.h"
#include "CCore.h"
#include "WinAPI.h"
#include "CTimeManager.h"

CCore::CCore()
{
	this->m_hdc = 0;
	m_fPointX = 100;
	m_fPointY = 100;
}

CCore::~CCore()
{

}

void CCore::Init()
{
	TIME->Init();
	m_hdc = GetDC(hWnd);
}

void CCore::Release()
{
	TIME->Release();

	ReleaseDC(hWnd, m_hdc);
}

void CCore::Update()
{
	TIME->Update();

	float moveDistance = 100 * DT;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_fPointX -= moveDistance;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_fPointX += moveDistance;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		m_fPointY -= moveDistance;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		m_fPointY += moveDistance;
	}
}

void CCore::Render()
{
	Rectangle(m_hdc, m_fPointX - 50, m_fPointY - 50, m_fPointX + 50, m_fPointY + 50);

	wstring fps = to_wstring(FPS);
	TextOut(m_hdc, WINSIZEX - 50, 10, fps.c_str(), fps.size());
}