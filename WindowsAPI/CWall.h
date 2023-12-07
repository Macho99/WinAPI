#pragma once
#include "CGameObject.h"

enum class TypeWall { Top, Bottom, Left, Right };
class CWall : public CGameObject
{
public:
	CWall(TypeWall type);
	virtual ~CWall();

private:
	TypeWall type;
	Vec2 size;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;
};

