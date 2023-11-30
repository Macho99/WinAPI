#pragma once

enum class GroupScene;
class CCore;
class CGameObject;

class CEventManager : public SingleTon<CEventManager>
{
	friend CCore;
	friend SingleTon<CEventManager>;
private:
	queue<CGameObject*> queueAddObject;
	queue<CGameObject*> queueDeleteObject;
	queue<GroupScene> queueChangeScene;

private:
	CEventManager();
	virtual ~CEventManager();

	void Init();
	void Update();
	void Release();

private:
	void ProgressAddObject();
	void ProgressDeleteObject();
	void ProgressChangeScene();

public:
	void EventAddObject(CGameObject* gameObject);
	void EventDeleteObject(CGameObject* gameObject);
	void EventChangeScene(GroupScene scene);
};

#define EVENT				CEventManager::GetInstance()
#define ADDOBJECT(obj)		CEventManager::GetInstance()->EventAddObject(obj)
#define DELETEOBJECT(obj)	CEventManager::GetInstance()->EventDeleteObject(obj)
#define CHANGESCENE(scene)	CEventManager::GetInstance()->EventChangeScene(scene)