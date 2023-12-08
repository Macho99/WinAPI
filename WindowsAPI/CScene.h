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
	virtual void SceneRelease();	// TODO : SetListObj()�� ȣ���ϴ� ���� �̰� �������Ұ�
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
	//������ �̺�Ʈ �Ŵ����ܰ迡�� ����
	//void DeleteGameObject(CGameObject* gameObj);
};