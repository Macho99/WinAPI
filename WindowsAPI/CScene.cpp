#include "framework.h"

#include "CGameObject.h"

#include "CScene.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::SceneInit()
{
	Init();

	for (CGameObject* gameObj : listObj) {
		gameObj->Init();
	}
}

void CScene::SceneRelease()
{
	for (CGameObject* gameObj : listObj) {
		gameObj->Release();
		delete gameObj;
	}
	Release();
}

void CScene::SceneEnter()
{
	Enter();
}

void CScene::SceneUpdate()
{
	for (CGameObject* gameObj : listObj) {
		//오브젝트가 삭제 예정인경우 업데이트는 진행하지 않고
		//삭제해도 괜찮은 상태로 전환
		if (gameObj->GetReserveDelete()) {
			gameObj->SetSafeToDelete();
		}
		else {
			gameObj->Update();
		}
	}

	Update();

	listObj.remove_if(
		[](CGameObject* target)
		{
			if (target->GetSafeToDelete()) {
				delete target;
				return true;
			}
			else {
				return false;
			}
		});
}

void CScene::SceneRender()
{
	for (CGameObject* gameObj : listObj) {
		gameObj->Render();
	}
	Render();
}

void CScene::SceneExit()
{
	Exit();
}

void CScene::AddGameObject(CGameObject* gameObj)
{
	listObj.push_back(gameObj);
	gameObj->Init();
}
