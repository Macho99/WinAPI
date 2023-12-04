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
			//������Ʈ�� ���� �����ΰ�� ������Ʈ�� �������� �ʰ�
			//�����ص� ������ ���·� ��ȯ
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
		//���� ���̾ ī�޶�� ǥ������ �ʾƾ� �ϴ� ���̾��� continue
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