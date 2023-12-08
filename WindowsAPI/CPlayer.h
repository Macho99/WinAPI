#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
public:
	CPlayer(Vec2 size = Vec2(50, 50), float speed = 200.f);
	virtual ~CPlayer();

private:
	int hp;
	Vec2 prevPos;
	Vec2 size;
	float speed;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void OnCollisionEnter(CCollider* otherCollider) override;

	void Move();
	void TakeDamage(int damage);
	void Shot();
};
