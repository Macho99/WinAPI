#include "framework.h"
#include "WinAPI.h"

#include "CGameObject.h"
#include "CComponent.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	reserveDelete = false;
	safeToDelete = false;
	pos = Vec2();
	scale = Vec2();
	layer = Layer::Default;
	collider = nullptr;
}

CGameObject::~CGameObject()
{
}

void CGameObject::AddComponent(CComponent* component)
{
	listComponent.push_back(component);
	component->Init();
	component->SetOwner(this);
}

void CGameObject::RemoveComponent(CComponent* component)
{
	component->Release();
	listComponent.remove(component);
	delete component;
}

CCollider* CGameObject::GetCollider()
{
	return collider;
}

void CGameObject::AddCollider(Vec2 scale, Vec2 offset)
{
	if (collider != nullptr) return;

	collider = new CCollider();
	collider->SetScale(scale);
	collider->SetOffset(offset);
	AddComponent(collider);
}

void CGameObject::RemoveCollider()
{
	if (collider == nullptr) return;

	RemoveComponent(collider);
	collider = nullptr;
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

void CGameObject::GameObjectInit()
{
	for (CComponent* component : listComponent) {
		component->Init();
	}
	Init();
}

void CGameObject::GameObjectRelease()
{
	for (CComponent* component : listComponent) {
		component->Release();
		delete component;
	}
	listComponent.clear();

	Release();
}

void CGameObject::GameObjectUpdate()
{
	Update();
	for (CComponent* component : listComponent) {
		component->Update();
	}
}

void CGameObject::GameObjectPhysicsUpdate()
{
	for (CComponent* component : listComponent) {
		component->PhysicsUpdate();
	}
}

void CGameObject::GameObjectRender()
{
	Render();
	for (CComponent* component : listComponent) {
		component->Render();
	}
}
