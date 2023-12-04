#include "framework.h"
#include "WinAPI.h"

#include "CScene.h"
#include "CSceneManager.h"
#include "CGameObject.h"
#include "CCollider.h"

#include "CCollisionManager.h"

CCollisionManager::CCollisionManager()
{
	arrLayer[0][0] = { false };
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::Init()
{
	CheckLayer(Layer::Player, Layer::Monster);
}

void CCollisionManager::Update()
{
	for (int left = 0; left < (int)Layer::Size; left++) {
		for (int right = left; right < (int)Layer::Size; right++) {
			if (arrLayer[left][right]) {
				CollisionUpdate((Layer) left, (Layer) right);
			}
		}
	}
}

void CCollisionManager::CollisionUpdate(Layer left, Layer right)
{
	CScene* curScene = SCENE->GetCurScene();
	const list<CGameObject*>& leftListObj = curScene->listObj[(int)left];
	const list<CGameObject*>& rightListObj = curScene->listObj[(int)right];

	for (CGameObject* leftObj : leftListObj) {
		if (nullptr == leftObj) continue;

		for (CGameObject* rightObj : rightListObj) {
			if (nullptr == rightObj) continue;
			if (leftObj == rightObj) continue;
			
			CCollider* leftCollider = leftObj->GetCollider();
			CCollider* rightCollider = rightObj->GetCollider();

			if (IsCollision(leftCollider, rightCollider)) {
				leftCollider->OnCollision(rightCollider);
				rightCollider->OnCollision(leftCollider);
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* leftCollider, CCollider* rightCollider)
{
	Vec2 leftPos, leftScale, rightPos, rightScale;
	leftPos = leftCollider->GetPos();
	leftScale = leftCollider->GetScale();

	rightPos = rightCollider->GetPos();
	rightScale = rightCollider->GetScale();

	if (abs(leftPos.x - rightPos.x) < (leftScale.x + rightScale.x) * 0.5f
		&& abs(leftPos.y - rightPos.y) < (leftScale.y + rightScale.y) * 0.5f) {
		return true;
	}
	return false;
}

void CCollisionManager::Release()
{
}

void CCollisionManager::CheckLayer(Layer left, Layer right)
{
	arrLayer[(int)left][(int)right] = true;
	arrLayer[(int)right][(int)left] = true;
}

void CCollisionManager::UnCheckLayer(Layer left, Layer right)
{
	arrLayer[(int)left][(int)right] = false;
	arrLayer[(int)right][(int)left] = false;
}

void CCollisionManager::ResetCheck()
{
	memset(arrLayer, false, sizeof(bool) * (int)Layer::Size * (int)Layer::Size);
}
