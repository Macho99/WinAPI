#include "framework.h"
#include "WinAPI.h"

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
	if (INPUT->GetButtonUp(VK_SPACE)) {
		CHANGESCENE(GroupScene::Stage01);
	}
}

void CSceneTitle::Render()
{
	RENDER->SetText(TextType::Center);
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5, L"시작하려면 '스페이스바'를 누르세요..");
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}
