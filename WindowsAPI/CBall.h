#pragma once
#include "CGameObject.h"
class CBall : public CGameObject
{
public:
	CBall(Vec2 size = Vec2(50, 50), float speed = 50.f, Vec2 dir = Vec2(0, 1));
	virtual ~CBall();

private:
	Vec2 size;
	float speed;
	Vec2 dir;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void OnCollisionEnter(CCollider* otherCollider) override;
};

