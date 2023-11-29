#include "framework.h"
#include "WinAPI.h"

#include "CSceneManager.h"
#include "CScene.h"
#include "CSceneTitle.h"
#include "CSceneStage01.h"

CSceneManager::CSceneManager()
{
	curScene = nullptr;
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Init()
{
	// TODO : 게임에 필요한 씬 추가
	CScene* sceneTitle = new CSceneTitle();
	mapScene.insert(make_pair(GroupScene::Title, sceneTitle));
	CScene* sceneStage01 = new CSceneStage01();
	mapScene.insert(make_pair(GroupScene::Stage01, sceneStage01));

	for (auto iter = mapScene.begin(); iter != mapScene.end(); iter++) {
		iter->second->Init();
	}

	curScene = sceneTitle;
	curScene->Enter();
}

void CSceneManager::Update()
{
	curScene->Update();
}

void CSceneManager::Render()
{
	curScene->Render();
}

void CSceneManager::Release()
{
	for (auto iter = mapScene.begin(); iter != mapScene.end(); iter++) {
		iter->second->Release();
		delete iter->second;
	}
	mapScene.clear();
}

CScene* CSceneManager::GetCurScene()
{
	return curScene;
}


void CSceneManager::ChangeScene(GroupScene scene)
{
	curScene->Exit();
	curScene = mapScene[scene];
	curScene->Enter();
}
