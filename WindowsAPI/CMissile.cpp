#include "framework.h"

#include "CTimeManager.h"
#include "CRenderManager.h"

#include "CMissile.h"

CMissile::CMissile()
{
	speed = 300;
	size = Vec2(10, 10);
	dir = Vec2(1, 0);
}

CMissile::~CMissile()
{
}

void CMissile::Init()
{
	scale = size;
}

void CMissile::Update()
{
	pos += dir * speed * DT;
	//pos.x += direction.x * speed * DT;
	//pos.y += direction.y * speed * DT;
}

void CMissile::Render()
{
	RENDER->Circle(pos.x, pos.y, scale.x);
}

void CMissile::Release()
{
}

void CMissile::SetDir(Vec2 dir)
{
	this->dir = dir.Normalize();
}
