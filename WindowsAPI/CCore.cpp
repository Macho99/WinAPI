#include "framework.h"
#include "CCore.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CSceneManager.h"
#include "CEventManager.h"
#include "CCollisionManager.h"

CCore::CCore()
{

}

CCore::~CCore()
{

}

void CCore::Init()
{
	TIME->Init();
	RENDER->Init();
	INPUT->Init();
	SCENE->Init();
	EVENT->Init();
	COLLISION->Init();
}

void CCore::Release()
{
	TIME->Release();
	RENDER->Release();
	INPUT->Release();
	SCENE->Release();
	EVENT->Release();
	COLLISION->Release();
}

void CCore::Update()
{
	//이전 프레임에서 추가된 이벤트를 프레임 초기에 한꺼번에 처리
	EVENT->Update();

	TIME->Update();
	INPUT->Update();
	SCENE->Update();

	//게임 오브젝트들이 업데이트 된 후 충돌처리 진행
	COLLISION->Update();
}

void CCore::Render()
{
	RENDER->BeginDraw();

	SCENE->Render();

	wstring fps = to_wstring(FPS);
	RENDER->Text(WINSIZEX - 80, 10, fps);

	RENDER->EndDraw();
}