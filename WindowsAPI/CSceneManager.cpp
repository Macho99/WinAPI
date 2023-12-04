#include "framework.h"
#include "WinAPI.h"

#include "CScene.h"
#include "CSceneTitle.h"
#include "CSceneStage01.h"
#include "CSceneManager.h"

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

	for (auto& pair : mapScene) {
		pair.second->SceneInit();
	}

	curScene = sceneTitle;
	curScene->SceneEnter();
}

void CSceneManager::Update()
{
	curScene->SceneUpdate();
	curScene->ScenePhysicsUpdate();
}

void CSceneManager::Render()
{
	curScene->SceneRender();
}

void CSceneManager::Release()
{
	for (auto& pair: mapScene) {
		pair.second->SceneRelease();
		delete pair.second;
	}
	mapScene.clear();
}

CScene* CSceneManager::GetCurScene()
{
	return curScene;
}


void CSceneManager::ChangeScene(GroupScene scene)
{
	curScene->SceneExit();
	curScene = mapScene[scene];
	curScene->SceneEnter();
}
