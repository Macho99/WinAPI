#pragma once

enum class GroupScene;
class CCore;
class CScene;

class CSceneManager : public SingleTon<CSceneManager>
{
	friend SingleTon<CSceneManager>;
	friend CCore;

private:
	map<GroupScene, CScene*> mapScene;
	CScene* curScene;

	CSceneManager();
	virtual ~CSceneManager();

	void Init();
	void Update();
	void Render();
	void Release();

public:
	CScene* GetCurScene();
	void ChangeScene(GroupScene scene);
};

#define SCENE			CSceneManager::GetInstance()
#define ADDOBJECT(obj)	CSceneManager::GetInstance()->GetCurScene()->AddGameObject(obj)
