#include "framework.h"
#include "WinAPI.h"

#include "CScene.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CSceneManager.h"
#include "CEventManager.h"

#include "CCollider.h"
#include "CMissile.h"
#include "CPlayer.h"


CPlayer::CPlayer(Vec2 size, float speed)
{
	name = L"플레이어";
	layer = Layer::Player;
	this->size = size;
	this->speed = speed;
	this->scale = size;
	prevPos = Vec2();
}

CPlayer::~CPlayer()
{

}

void CPlayer::Init()
{
	AddCollider(ColliderType::Rect, size, Vec2(0, 0));
	prevPos = pos;
}

void CPlayer::Release()
{
}

void CPlayer::Update()
{
	if (BUTTONSTAY(VK_SPACE)) {
		Shot();
	}

	Vec2 dir = Vec2(0, 0);
	if (BUTTONSTAY(VK_LEFT) || BUTTONSTAY('A')) {
		dir.x -= 1.f;
	}
	if (BUTTONSTAY(VK_RIGHT) || BUTTONSTAY('D')) {
		dir.x += 1.f;
	}
	if (BUTTONSTAY(VK_UP) || BUTTONSTAY('W')) {
		dir.y -= 1.f;
	}
	if (BUTTONSTAY(VK_DOWN) || BUTTONSTAY('S')) {
		dir.y += 1.f;
	}

	if (dir.x != 0 && dir.y != 0) {
		dir /= 1.414f;
	}
	pos += dir * speed * DT;

	if (pos.x < 0) {
		pos.x = 0;
	}
	if (pos.x > WINSIZEX) {
		pos.x = WINSIZEX;
	}
	if (pos.y < 0) {
		pos.y = 0;
	}
	if (pos.y > WINSIZEY) {
		pos.y = WINSIZEY;
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
