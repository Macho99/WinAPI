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
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5 - 50.f, L"닷지 게임!!");
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5, L"시작하려면 '스페이스바'를 누르세요..");
	RENDER->Text(WINSIZEX * 0.5, WINSIZEY * 0.5 + 30.f, L"종료하려면 'esc키'를 누르세요");
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}
