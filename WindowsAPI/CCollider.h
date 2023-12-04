#pragma once
#include "CComponent.h"

class CGameObject;

class CCollider : public CComponent
{
	friend CGameObject;
public:
	CCollider();
	virtual ~CCollider();

private:
	Vec2 pos;
	Vec2 offset;
	Vec2 scale;

private:
	void SetPos(Vec2 pos);
	void SetOffset(Vec2 offset);
	void SetScale(Vec2 scale);

public:
	Vec2 GetPos();
	Vec2 GetOffset();
	Vec2 GetScale();

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void PhysicsUpdate() override;
	void Render() override;

private:
	void OnCollision(CCollider* otherCollider);
};

