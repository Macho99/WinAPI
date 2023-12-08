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

list<CGameObject*>* CScene::GetListObj()
{
	return listObj;
}

void CScene::SetListObj(list<CGameObject*>* listObj)
{
	for (int i = 0; i < (int)Layer::Size; i++) {
		//깊은 복사 생략
		this->listObj[i] = listObj[i];
	}
}


void CScene::SceneInit()
{
	Init();

	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->GameObjectInit();
		}
	}
}

void CScene::SceneRelease()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->GameObjectRelease();
			delete gameObj;
		}
		listObj[layer].clear();
	}
	Release();
}

void CScene::SceneEnter()
{
	Enter();
}

void CScene::SceneUpdate()
{
	//씬 내에 삭제해도 안전한 게임 오브젝트를 삭제
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		listObj[layer].remove_if(
			[](CGameObject* target)
			{
				if (target->GetSafeToDelete()) {
					target->GameObjectRelease();
					delete target;
					return true;
				}
				else {
					return false;
				}
			});
	}


	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObj : listObj[layer]) {
			//오브젝트가 삭제 예정인경우 업데이트는 진행하지 않고
			//삭제해도 괜찮은 상태로 전환
			if (gameObj->GetReserveDelete()) {
				gameObj->SetSafeToDelete();
			}
			else {
				gameObj->GameObjectUpdate();
			}
		}
	}

	Update();
}

void CScene::ScenePhysicsUpdate()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		for (CGameObject* gameObject : listObj[layer]) {
			gameObject->GameObjectPhysicsUpdate();
		}
	}
}

void CScene::SceneRender()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++) {
		//만약 레이어가 카메라로 표현되지 않아야 하는 레이어라면 continue
		for (CGameObject* gameObj : listObj[layer]) {
			gameObj->GameObjectRender();
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
	gameObj->GameObjectInit();
}