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
		//���� ���� ����
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
	//�� ���� �����ص� ������ ���� ������Ʈ�� ����
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
			//������Ʈ�� ���� �����ΰ�� ������Ʈ�� �������� �ʰ�
			//�����ص� ������ ���·� ��ȯ
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
		//���� ���̾ ī�޶�� ǥ������ �ʾƾ� �ϴ� ���̾��� continue
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