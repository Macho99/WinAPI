#include "framework.h"
#include "WinAPI.h"
#include "CBall.h"
#include "CCollider.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"

CBall::CBall(Vec2 size, float speed, Vec2 dir)
{
	this->size = size;
	scale = size;
	this->speed = speed;
	this->dir = dir;
	this->layer = Layer::Ball;
}

CBall::~CBall()
{
}

void CBall::Init()
{
	AddCollider(ColliderType::Circle, scale, Vec2());
}

void CBall::Release()
{
}

void CBall::Update()
{
	pos += dir * speed * DT;
}

void CBall::Render()
{
	RENDER->Circle(pos.x, pos.y, scale.x);
}

void CBall::OnCollisionEnter(CCollider* otherCollider)
{

	Layer otherLayer = otherCollider->GetOwner()->GetLayer();

	switch (otherLayer) {
	case Layer::VerticalWall:
		dir.x = -dir.x;
		break;
	case Layer::HorizonWall:
		dir.y = -dir.y;
		break;
	case Layer::Missile:
		DELETEOBJECT(this);
		break;
	default:
		break;
	}
}
