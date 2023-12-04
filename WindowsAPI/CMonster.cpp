#include "framework.h"
#include "WinAPI.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CRenderManager.h"
#include "CTimeManager.h"
#include "CMonster.h"

CMonster::CMonster() : size(100, 100)
{
	layer = Layer::Monster;
}

CMonster::~CMonster()
{
}

void CMonster::Init()
{
	scale = size;
	AddCollider(Vec2(70, 70));
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
}
