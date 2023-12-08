#pragma once

class CSceneManager;
class CGameObject;
class CCollisionManager;

class CScene
{
	friend CCollisionManager;
	friend CSceneManager;
public:
	CScene();
	virtual ~CScene();

private:
	list<CGameObject*> listObj[(int)Layer::Size];

public:
	list<CGameObject*>* GetListObj();
protected:
	void SetListObj(list<CGameObject*>* listObj);

private:
	void SceneInit();
	virtual void SceneRelease();	// TODO : SetListObj()를 호출하는 씬은 이걸 재정의할것
	void SceneEnter();
	void SceneExit();
	void SceneUpdate();
	void ScenePhysicsUpdate();
	void SceneRender();

private:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	void AddGameObject(CGameObject* gameObj);
	//삭제는 이벤트 매니저단계에서 진행
	//void DeleteGameObject(CGameObject* gameObj);
};