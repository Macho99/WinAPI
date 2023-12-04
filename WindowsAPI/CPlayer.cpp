#include "framework.h"
#include "WinAPI.h"

#include "CScene.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CSceneManager.h"
#include "CEventManager.h"

#include "CMissile.h"
#include "CPlayer.h"

CPlayer::CPlayer() : size(100, 100), speed(200.f)
{
	layer = Layer::Player;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	this->scale = size;
	AddCollider(Vec2(90, 90), Vec2(0, 0));
}

void CPlayer::Release()
{
}

void CPlayer::Update()
{
	float moveDistance = speed * DT;
	if (BUTTONSTAY(VK_LEFT) || BUTTONSTAY('A')) {
		pos.x -= moveDistance;
	}
	if (BUTTONSTAY(VK_RIGHT) || BUTTONSTAY('D')) {
		pos.x += moveDistance;
	}
	if (BUTTONSTAY(VK_UP) || BUTTONSTAY('W')) {
		pos.y -= moveDistance;
	}
	if (BUTTONSTAY(VK_DOWN) || BUTTONSTAY('S')) {
		pos.y += moveDistance;
	}

	if (BUTTONSTAY(VK_SPACE)) {
		Shot();
	}
}

void CPlayer::Render()
{
	RENDER->Rect(
		pos.x - scale.x * 0.5f,
		pos.y - scale.y * 0.5f,
		pos.x + scale.x * 0.5f,
		pos.y + scale.y * 0.5f
		);
}

void CPlayer::Shot()
{
	CMissile* missile = new CMissile();
	missile->SetPos(pos);
	POINT point = INPUT->GetMousePos();
	missile->SetDir(Vec2(point.x - pos.x, point.y - pos.y));
	ADDOBJECT(missile);
}
