#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	Vec2 size;
	float speed;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void Shot();
};

