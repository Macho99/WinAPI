#pragma once

enum class GroupScene;
class CCore;
class CScene;
class CCollisionManager;
class CEventManager;

class CSceneManager : public SingleTon<CSceneManager>
{
	friend SingleTon<CSceneManager>;
	friend CCore;
	friend CCollisionManager;
	friend CEventManager;

private:
	map<GroupScene, CScene*> mapScene;
	CScene* curScene;
	CScene* prevScene;

	CSceneManager();
	virtual ~CSceneManager();

	void Init();
	void Update();
	void Render();
	void Release();

public:
	CScene* GetPrevScene();
	CScene* GetCurScene();
	void ChangeScene(GroupScene scene);
	void InitScene(GroupScene scene);
};

#define SCENE			CSceneManager::GetInstance()