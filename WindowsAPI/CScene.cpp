#include "framework.h"
#include "WinAPI.h"

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

	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->Init();
		}
	}
}

void CScene::SceneRelease()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->Release();
			delete gameObj;
		}
	}
	Release();
}

void CScene::SceneEnter()
{
	Enter();
}

void CScene::SceneUpdate()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			//오브젝트가 삭제 예정인경우 업데이트는 진행하지 않고
			//삭제해도 괜찮은 상태로 전환
			if (gameObj->GetReserveDelete()) {
				gameObj->SetSafeToDelete();
			}
			else {
				gameObj->Update();
			}
		}
	}

	Update();

	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		listObj[layer].remove_if(
			[](CGameObject* target)
			{
				if (target->GetSafeToDelete()) {
					//target.Release();
					delete target;
					return true;
				}
				else {
					return false;
				}
			});
	}
}

void CScene::SceneRender()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		//만약 레이어가 카메라로 표현되지 않아야 하는 레이어라면 continue
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->Render();
		}
	}
	Render();
}

void CScene::SceneExit()
{
	Exit();
}

void CScene::AddGameObject(CGameObject* gameObj)
{
	listObj[(int) gameObj->GetLayer()].push_back(gameObj);
	gameObj->Init();
}