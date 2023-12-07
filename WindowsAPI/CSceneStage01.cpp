#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CInputManager.h"
#include "CRenderManager.h"
#include "CScene.h"
#include "CEventManager.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBall.h"
#include "CWall.h"

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
	CBall* ball = new CBall(Vec2(30,30), 100.f, Vec2(1,-1));
	ball->SetPos(500.f, 200.f);
	AddGameObject(ball);
	CWall* topWall = new CWall(TypeWall::Top);
	CWall* bottomWall = new CWall(TypeWall::Bottom);
	CWall* leftWall = new CWall(TypeWall::Left);
	CWall* rightWall = new CWall(TypeWall::Right);
	AddGameObject(topWall);
	AddGameObject(bottomWall);
	AddGameObject(leftWall);
 	AddGameObject(rightWall);
}


void CSceneStage01::Release()
{
}

void CSceneStage01::AddMonster()
{
	CMonster* monster = new CMonster();
	monster->SetPos(500, 500);
	AddGameObject(monster);
}

void CSceneStage01::Enter()
{
}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE)) {
		CHANGESCENE(GroupScene::Title);
	}
	if (BUTTONDOWN('R')) {
		AddMonster();
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
}

