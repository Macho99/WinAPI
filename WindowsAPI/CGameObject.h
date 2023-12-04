#pragma once

class CScene;
class CEventManager;
class CComponent;
class CCollider;
enum class Layer;

class CGameObject
{
	friend CScene;
	friend CEventManager;
public:
	CGameObject();
	virtual ~CGameObject();

protected:
	Vec2 pos;
	Vec2 scale;
	Layer layer;

private:
	list<CComponent*> listComponent;

	void AddComponent(CComponent* component);
	void RemoveComponent(CComponent* component);

private:
	CCollider* collider;

protected:
	CCollider* GetCollider();
	void AddCollider(Vec2 scale, Vec2 offset = Vec2());
	void RemoveCollider();

private:
	bool reserveDelete;
	bool safeToDelete;
	void SetReserveDelete();
	void SetSafeToDelete();
	bool GetSafeToDelete();

public:
	bool GetReserveDelete();

public:
	Vec2 GetPos();
	void SetPos(Vec2 pos);
	void SetPos(float x, float y);
	Vec2 GetScale();
	void SetScale(Vec2 scale);
	void SetScale(float x, float y);
	Layer GetLayer();
	void SetLayer(Layer layer);


	//게임 오브젝트 부모 전용 함수
private:
	void GameObjectInit();
	void GameObjectRelease();
	void GameObjectUpdate();
	void GameObjectPhysicsUpdate();
	void GameObjectRender();

private:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};