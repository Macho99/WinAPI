#include "framework.h"
#include "WinAPI.h"

#include "CSceneManager.h"
#include "CScene.h"
#include "CGameObject.h"

#include "CEventManager.h"

CEventManager::CEventManager()
{
}

CEventManager::~CEventManager()
{
}

void CEventManager::Init()
{
}

void CEventManager::Release()
{
}

void CEventManager::Update()
{
	ProgressAddObject();
	ProgressDeleteObject();

	ProgressChangeScene();
}


void CEventManager::ProgressAddObject()
{
	while (!queueAddObject.empty()) {
		CGameObject* gameObject = queueAddObject.front();
		queueAddObject.pop();
		SCENE->GetCurScene()->AddGameObject(gameObject);
	}
}

void CEventManager::ProgressDeleteObject()
{
	//프레임 초기에 삭제될 게임 오브젝트에 표시
	while (!queueDeleteObject.empty()) {
		CGameObject* gameObject = queueDeleteObject.front();
		queueDeleteObject.pop();
		gameObject->SetReserveDelete();
	}
}

void CEventManager::ProgressChangeScene()
{
	while (!queueChangeScene.empty()) {
		GroupScene scene = queueChangeScene.front();
		queueChangeScene.pop();
		SCENE->ChangeScene(scene);
	}
}

void CEventManager::EventAddObject(CGameObject* gameObject)
{
	queueAddObject.push(gameObject);
}

void CEventManager::EventDeleteObject(CGameObject* gameObject)
{
	queueDeleteObject.push(gameObject);
}

void CEventManager::EventChangeScene(GroupScene scene)
{
	queueChangeScene.push(scene);
}
