#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
	pos = Vec2();
	scale = Vec2();
}

CGameObject::~CGameObject()
{
}

Vec2 CGameObject::GetPos()
{
	return pos;
}

void CGameObject::SetPos(Vec2 pos)
{
	this->pos = pos;
}

void CGameObject::SetPos(float x, float y)
{
	this->pos.x = x;
	this->pos.y = y;
}

Vec2 CGameObject::GetScale()
{
	return scale;
}

void CGameObject::SetScale(Vec2 scale)
{
	this->scale = scale;
}

void CGameObject::SetScale(float x, float y)
{
	this->scale.x = x;
	this->scale.y = y;
}
