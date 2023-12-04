#pragma once

class CSceneManager;
class CGameObject;

class CScene
{
	friend CSceneManager;
public:
	CScene();
	virtual ~CScene();

private:
	list<CGameObject*> listObj[(int)Layer::Size];

	void SceneInit();
	void SceneRelease();
	void SceneEnter();
	void SceneUpdate();
	void SceneRender();
	void SceneExit();

private:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

public:
	void AddGameObject(CGameObject* gameObj);
	//삭제는 이벤트 매니저단계에서 진행
	//void DeleteGameObject(CGameObject* gameObj);
};