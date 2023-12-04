#include "framework.h"
#include "WinAPI.h"

#include "CGameObject.h"

CGameObject::CGameObject()
{
	reserveDelete = false;
	safeToDelete = false;
	pos = Vec2();
	scale = Vec2();
	layer = Layer::Default;
}

CGameObject::~CGameObject()
{
}

void CGameObject::SetReserveDelete()
{
	reserveDelete = true;
}

void CGameObject::SetSafeToDelete()
{
	safeToDelete = true;
}

bool CGameObject::GetSafeToDelete()
{
	return safeToDelete;
}

bool CGameObject::GetReserveDelete()
{
	return reserveDelete;
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

Layer CGameObject::GetLayer()
{
	return layer;
}

void CGameObject::SetLayer(Layer layer)
{
	this->layer = layer;
}
