#include "framework.h"
#include "CCore.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CRenderManager.h"

CCore::CCore()
{
	m_fPointX = 100;
	m_fPointY = 100;
}

CCore::~CCore()
{

}

void CCore::Init()
{
	TIME->Init();
	RENDER->Init();
}

void CCore::Release()
{
	TIME->Release();
	RENDER->Release();
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
	RENDER->BeginDraw();

	RENDER->Rect(
		m_fPointX - 50.f,
		m_fPointY - 50.f,
		m_fPointX + 50.f,
		m_fPointY + 50.f
	);

	wstring fps = to_wstring(FPS);
	RENDER->Text(WINSIZEX - 80, 10, fps);

	RENDER->EndDraw();
}