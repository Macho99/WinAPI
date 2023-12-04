#include "framework.h"
#include "CComponent.h"

CComponent::CComponent()
{
	owner = nullptr;
}

CComponent::~CComponent()
{

}

void CComponent::SetOwner(CGameObject* owner)
{
	this->owner = owner;
}

CGameObject* CComponent::GetOwner()
{
	return owner;
}
