#include "framework.h"
#include "WinAPI.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CRenderManager.h"
#include "CTimeManager.h"
#include "CEventManager.h"
#include "CMonster.h"

CMonster::CMonster() : size(100, 100)
{
	name = L"¸ó½ºÅÍ";
	hp = 200;
	layer = Layer::Monster;
}

CMonster::~CMonster()
{
}

void CMonster::Init()
{
	scale = size;
	AddCollider(ColliderType::Circle, Vec2(50, 50));
}

void CMonster::Release()
{

}

void CMonster::Update()
{

}

void CMonster::Render()
{
	RENDER->SetPen(PenType::Dash);
	RENDER->Rect(
		pos.x - scale.x * 0.5f,
		pos.y - scale.y * 0.5f,
		pos.x + scale.x * 0.5f,
		pos.y + scale.y * 0.5f
	);
	RENDER->SetText(TextType::Center);
	RENDER->Text(pos.x, pos.y, to_wstring(hp));
}

void CMonster::OnCollisionEnter(CCollider* otherCollider)
{
	hp--;
	if (hp <= 0) {
		DELETEOBJECT(this);
	}

}

void CMonster::OnCollisionStay(CCollider* otherCollider)
{

}

void CMonster::OnCollisionExit(CCollider* otherCollider)
{

}
