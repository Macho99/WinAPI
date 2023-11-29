#include "framework.h"
#include "CCore.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CInputManager.h"

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
	INPUT->Init();
}

void CCore::Release()
{
	TIME->Release();
	RENDER->Release();
	INPUT->Init();
}

void CCore::Update()
{
	TIME->Update();
	INPUT->Update();


}

void CCore::Render()
{
	RENDER->BeginDraw();

	RENDER->SetPen(PenType::Dash, RGB(255, 0, 0), 1);
	RENDER->SetBrush(BrushType::Null, RGB(255, 255, 255));

	RENDER->SetText(TextType::Center);
	RENDER->Text(100, 100, L"여기가 100, 100 입니다");

	RENDER->Line(100, 100, 500, 500);
	RENDER->SetPen(PenType::Solid);
	RENDER->Circle(300, 300, 220);
	
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