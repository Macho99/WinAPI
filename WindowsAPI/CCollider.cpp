#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"
#include "CRenderManager.h"

UINT CCollider::staticID = 0;

CCollider::CCollider()
{
	ID = staticID++;
	pos = Vec2();
	offset = Vec2();
	scale = Vec2();
	collisionCount = 0;
	type = ColliderType::Rect;
}

CCollider::~CCollider()
{
}

void CCollider::SetPos(Vec2 pos)
{
	this->pos = pos;
}

void CCollider::SetOffset(Vec2 offset)
{
	this->offset = offset;
}

void CCollider::SetScale(Vec2 scale)
{
	this->scale = scale;
}

void CCollider::SetType(ColliderType type)
{
	this->type = type;
}

Vec2 CCollider::GetPos()
{
	return pos;
}

UINT CCollider::GetID()
{
	return ID;
}

Vec2 CCollider::GetOffset()
{
	return offset;
}

wstring CCollider::GetName()
{
	return GetOwner()->GetName();
}

Vec2 CCollider::GetScale()
{
	return scale;
}

void CCollider::Init()
{
}

void CCollider::Release()
{
}

void CCollider::Render()
{
	if (collisionCount > 0) {
		//RENDER->SetPen(PenType::Solid, RGB(0,255,0));
		RENDER->SetBrush(BrushType::Solid, RGB(0, 0, 0));
	}
	else {
		//RENDER->SetPen(PenType::Dot);
		RENDER->SetBrush(BrushType::Null);
	}


	if (ColliderType::Rect == type) {
		RENDER->Rect(
			pos.x - scale.x * 0.5f,
			pos.y - scale.y * 0.5f,
			pos.x + scale.x * 0.5f,
			pos.y + scale.y * 0.5f
		);
	}
	else if (ColliderType::Circle == type) {
		RENDER->Circle(
			pos.x,
			pos.y,
			scale.x
		);
	}

	RENDER->SetPen();
	RENDER->SetBrush();
}

ColliderType CCollider::GetType()
{
	return type;
}

void CCollider::Update()
{
}

void CCollider::PhysicsUpdate()
{
	pos = GetOwner()->GetPos() + offset;
}

void CCollider::OnCollisionEnter(CCollider* otherCollider)
{
	collisionCount++;
	GetOwner()->OnCollisionEnter(otherCollider);
}

void CCollider::OnCollisionStay(CCollider* otherCollider)
{
	GetOwner()->OnCollisionStay(otherCollider);
}

void CCollider::OnCollisionExit(CCollider* otherCollider)
{
	collisionCount--;
	GetOwner()->OnCollisionExit(otherCollider);
}
