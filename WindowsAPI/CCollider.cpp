#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"
#include "CRenderManager.h"

CCollider::CCollider()
{
	pos = Vec2();
	offset = Vec2();
	scale = Vec2();
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

Vec2 CCollider::GetPos()
{
	return pos;
}

Vec2 CCollider::GetOffset()
{
	return offset;
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
	RENDER->SetPen(PenType::Dot, RGB(0,255,0));
	RENDER->SetBrush(BrushType::Null);

	RENDER->Rect(
		pos.x - scale.x * 0.5f,
		pos.y - scale.y * 0.5f,
		pos.x + scale.x * 0.5f,
		pos.y + scale.y * 0.5f
	);

	RENDER->SetPen();
	RENDER->SetBrush();
}

void CCollider::Update()
{
}

void CCollider::PhysicsUpdate()
{
	pos = GetOwner()->GetPos() + offset;
}

void CCollider::OnCollision(CCollider* otherCollider)
{
	//Logger::Debug(L"충돌 발생");
	GetOwner()
}
