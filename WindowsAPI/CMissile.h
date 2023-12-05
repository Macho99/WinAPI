#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
public:
	CMissile();
	virtual ~CMissile();

private:
	float speed;
	Vec2 size;
	Vec2 dir;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

protected:
	void OnCollisionEnter(CCollider* otherCollider) override;

public:
	void SetDir(Vec2 dir);
};

