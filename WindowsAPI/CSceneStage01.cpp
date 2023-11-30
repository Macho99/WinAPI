#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CInputManager.h"
#include "CRenderManager.h"
#include "CScene.h"
#include "CEventManager.h"
#include "CPlayer.h"

#include "CSceneStage01.h"

CSceneStage01::CSceneStage01()
{
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	CPlayer* player = new CPlayer();
	player->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(player);
}

void CSceneStage01::Release()
{
}

void CSceneStage01::Enter()
{
}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE)) {
		CHANGESCENE(GroupScene::Title);
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
}

