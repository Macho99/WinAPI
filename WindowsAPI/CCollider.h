#pragma once
#include "CComponent.h"

class CGameObject;
class CCollisionManager;

enum class ColliderType { Rect, Circle };

class CCollider : public CComponent
{
	friend CCollisionManager;
	friend CGameObject;
public:
	CCollider();
	virtual ~CCollider();

private:
	static UINT32 staticID;
	UINT32 ID;
	UINT collisionCount;

	ColliderType type;
	Vec2 pos;
	Vec2 offset;
	Vec2 scale;

private:
	void SetPos(Vec2 pos);
	void SetOffset(Vec2 offset);
	void SetScale(Vec2 scale);
	void SetType(ColliderType type);

public:
	wstring GetName();
	UINT32 GetID();
	Vec2 GetPos();
	Vec2 GetOffset();
	Vec2 GetScale();
	ColliderType GetType();

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void PhysicsUpdate() override;
	void Render() override;

private:
	void OnCollisionEnter(CCollider* otherCollider);
	void OnCollisionStay(CCollider* otherCollider);
	void OnCollisionExit(CCollider* otherCollider);
};

