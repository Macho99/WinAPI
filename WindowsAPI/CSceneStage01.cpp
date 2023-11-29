#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CInputManager.h"
#include "CRenderManager.h"
#include "CSceneManager.h"
#include "CScene.h"


#include "CSceneStage01.h"

CSceneStage01::CSceneStage01()
{
	pointX = 0.f;
	pointY = 0.f;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
}

void CSceneStage01::Enter()
{
}

void CSceneStage01::Update()
{
	float moveDistance = 100 * DT;
	if (BUTTONSTAY(VK_LEFT)) {
		pointX -= moveDistance;
	}
	if (BUTTONSTAY(VK_RIGHT)) {
		pointX += moveDistance;
	}
	if (BUTTONSTAY(VK_UP)) {
		pointY -= moveDistance;
	}
	if (BUTTONSTAY(VK_DOWN)) {
		pointY += moveDistance;
	}

	if (BUTTONDOWN(VK_SPACE)) {
		pointY -= 200;
	}
	if (BUTTONUP(VK_SPACE)) {
		pointY += 200;
	}

	if (BUTTONDOWN(VK_ESCAPE)) {
		SCENE->ChangeScene(GroupScene::Title);
	}
}

void CSceneStage01::Render()
{
	RENDER->Circle(pointX, pointY, 200);
}

void CSceneStage01::Exit()
{
}

void CSceneStage01::Release()
{
}
