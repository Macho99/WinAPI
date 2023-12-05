#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"

#include "CCollider.h"
#include "CMissile.h"
CMissile::CMissile()
{
	name = L"πÃªÁ¿œ";
	speed = 300;
	size = Vec2(10, 10);
	dir = Vec2(1, 0);
	layer = Layer::Missile;
}

CMissile::~CMissile()
{
}

void CMissile::Init()
{
	scale = size;
	AddCollider(ColliderType::Circle, Vec2(scale.x - 3, scale.y - 3));
}

void CMissile::Update()
{
	pos += dir * speed * DT;
	//pos.x += direction.x * speed * DT;
	//pos.y += direction.y * speed * DT;

 	if (pos.x < 0 || pos.x > WINSIZEX || pos.y < 0 || pos.y > WINSIZEY) {
		DELETEOBJECT(this);
	}
}

void CMissile::Render()
{
	RENDER->Circle(pos.x, pos.y, scale.x);
}

void CMissile::Release()
{

}

void CMissile::OnCollisionEnter(CCollider* otherCollider)
{
	DELETEOBJECT(this);
}

void CMissile::SetDir(Vec2 dir)
{
	this->dir = dir.Normalize();
}