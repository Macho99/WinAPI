#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CInputManager.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CRenderManager.h"
#include "CScene.h"
#include "CEventManager.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBall.h"
#include "CWall.h"
#include "CGameManager.h"

#include "CSceneStage01.h"

CSceneStage01::CSceneStage01()
{
	currentTime = 0.f;
	ballTime = 0.f;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	//랜덤 엔진 초기화
	mt19937 mt(rd());
	dirDist = uniform_real_distribution<float>(-1.f, 1.f);
	speedDist = uniform_real_distribution<float>(200.f, 500.f);
	sizeDist = uniform_real_distribution<float>(5.f, 30.f);

	currentTime = 0.f;
	ballTime = 0.f;
	CGameManager::GetInstance()->SetSurviveTime(0.f);

	CPlayer* player = new CPlayer();
	player->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(player);
	CWall* topWall = new CWall(TypeWall::Top);
	CWall* bottomWall = new CWall(TypeWall::Bottom);
	CWall* leftWall = new CWall(TypeWall::Left);
	CWall* rightWall = new CWall(TypeWall::Right);
	AddGameObject(topWall);
	AddGameObject(bottomWall);
	AddGameObject(leftWall);
 	AddGameObject(rightWall);

	AddBall();
	AddBall();
	AddBall();
	AddBall();
	AddBall();
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

void CSceneStage01::AddBall()
{
	float size = sizeDist(rd);
	CBall* ball = new CBall(Vec2(size, size), speedDist(rd), Vec2(dirDist(rd), dirDist(rd)));
	ball->SetPos(100.f, 100.f);
	AddGameObject(ball);
}

void CSceneStage01::Enter()
{
}

void CSceneStage01::Update()
{
	float dt = DT;
	currentTime += dt;
	ballTime += dt;
	CGameManager::GetInstance()->SetSurviveTime(currentTime);

	if (ballTime > ballPeriod) {
		ballTime = 0;
		AddBall();
	}

	if (BUTTONDOWN(VK_ESCAPE)) {
		SCENE->InitScene(GroupScene::Stage01);
		CHANGESCENE(GroupScene::Title);
	}
	if (BUTTONDOWN('R')) {
		AddBall();
	}
}

void CSceneStage01::Render()
{
	RENDER->Text(WINSIZEX * 0.5f, 50, to_wstring(currentTime));
	//RENDER->Text(100, 100, to_wstring(INPUT->GetMousePos().x) + L", " + to_wstring(INPUT->GetMousePos().y));
}

void CSceneStage01::Exit()
{
}

