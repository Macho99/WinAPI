#include "framework.h"
#include "WinAPI.h"

#include "CCore.h"
#include "CSceneManager.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"

#include "CSceneTitle.h"

CSceneTitle::CSceneTitle()
{

}

CSceneTitle::~CSceneTitle()
{

}

void CSceneTitle::Init()
{
}

void CSceneTitle::Enter()
{
}

void CSceneTitle::Update()
{
	if (INPUT->GetButtonDown(VK_SPACE)) {
		SCENE->InitScene(GroupScene::Stage01);
		CHANGESCENE(GroupScene::Stage01);
	}
	else if (INPUT->GetButtonDown(VK_ESCAPE)) {
		CORE->SetGameover();
	}
}

void CSceneTitle::Render()
{
	RENDER->SetText(TextType::Center);
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5 - 50.f, L"���� ����!!");
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5, L"�����Ϸ��� '�����̽���'�� ��������..");
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5 + 30.f, L"�����Ϸ��� 'escŰ'�� ��������");
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}
