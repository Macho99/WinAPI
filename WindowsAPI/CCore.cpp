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
	//���� �����ӿ��� �߰��� �̺�Ʈ�� ������ �ʱ⿡ �Ѳ����� ó��
	EVENT->Update();

	TIME->Update();
	INPUT->Update();
	SCENE->Update();

	//���� ������Ʈ���� ������Ʈ �� �� �浹ó�� ����
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