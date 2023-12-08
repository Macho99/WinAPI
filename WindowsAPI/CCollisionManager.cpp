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
	// TODO : 충돌할 레이어 지정
	CheckLayer(Layer::Player, Layer::Monster);
	CheckLayer(Layer::Missile, Layer::Monster);
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

			UINT64 id = CollisionID(leftCollider->GetID(),
				rightCollider->GetID());

			if (umapPrevCollision.find(id) == umapPrevCollision.end()) {
				umapPrevCollision[id] = false;
			}

			bool prevCollision = umapPrevCollision[id];
			bool curCollision = IsCollision(leftCollider, rightCollider);

			if (curCollision) {
				//현재 o, 이전 o
				if (prevCollision) {
					if (leftObj->GetReserveDelete() || rightObj->GetReserveDelete()){
						leftCollider->OnCollisionExit(rightCollider);
						rightCollider->OnCollisionExit(leftCollider);
					}
					else{
						leftCollider->OnCollisionStay(rightCollider);
						rightCollider->OnCollisionStay(leftCollider);
					}
				}
				//현재 o, 이전 x
				else {
					if (leftObj->GetReserveDelete() || rightObj->GetReserveDelete()) {
						//nothing
					}
					else {
						leftCollider->OnCollisionEnter(rightCollider);
						rightCollider->OnCollisionEnter(leftCollider);
						umapPrevCollision[id] = true;
					}
				}
			}
			else {
				//현재 x, 이전 o
				if (prevCollision) {
					leftCollider->OnCollisionExit(rightCollider);
					rightCollider->OnCollisionExit(leftCollider);
					umapPrevCollision[id] = false;
				}
				//현재 x, 이전 x
				//nothing
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* leftCollider, CCollider* rightCollider)
{
	ColliderType leftType = leftCollider->GetType();
	ColliderType rightType = rightCollider->GetType();
	
	if (leftType == ColliderType::Rect
		&& rightType == ColliderType::Rect) {
		return RectCollision(
			leftCollider->GetPos(),
			leftCollider->GetScale(),
			rightCollider->GetPos(),
			rightCollider->GetScale()
		);
	}
	else if (leftType == ColliderType::Circle
		&& rightType == ColliderType::Circle) {
		return CircleCollision(
			leftCollider->GetPos(),
			leftCollider->GetScale().x,
			rightCollider->GetPos(),
			rightCollider->GetScale().x
		);
	}
	else if (leftType == ColliderType::Rect
		&& rightType == ColliderType::Circle){
		return RectCircleCollision(
			leftCollider->GetPos(),
			leftCollider->GetScale(),
			rightCollider->GetPos(),
			rightCollider->GetScale().x
		);
	}
	else if (leftType == ColliderType::Circle
		&& rightType == ColliderType::Rect) {
		return RectCircleCollision(
			rightCollider->GetPos(),
			rightCollider->GetScale(),
			leftCollider->GetPos(),
			leftCollider->GetScale().x
		);
	}

	return false;
}

bool CCollisionManager::RectCollision(Vec2 leftPos, Vec2 leftScale, Vec2 rightPos, Vec2 rightScale)
{
	if (abs(leftPos.x - rightPos.x) < (leftScale.x + rightScale.x) * 0.5f
		&& abs(leftPos.y - rightPos.y) < (leftScale.y + rightScale.y) * 0.5f) {
		return true;
	}
	return false;
}

bool CCollisionManager::CircleCollision(Vec2 leftPos, float leftRadios, Vec2 rightPos, float rightRadios)
{
	if (pow(leftPos.x - rightPos.x, 2) + pow(leftPos.y - rightPos.y, 2)
		< pow(leftRadios + rightRadios, 2)) {
		return true;
	}
	return false;
}

bool CCollisionManager::RectCircleCollision(
	Vec2 rectPos, Vec2 rectScale, Vec2 circlePos, float circleRadios)
{
	float leftX = rectPos.x - rectScale.x * 0.5f;
	float rightX = rectPos.x + rectScale.x * 0.5f;
	float topY = rectPos.y - rectScale.y * 0.5f;
	float bottomY = rectPos.y + rectScale.y * 0.5f;

	//원의 중심이 사각형의 위아래에 있을때
	if(leftX <= circlePos.x && circlePos.x <= rightX){
		if (pow(circlePos.y - rectPos.y, 2)
			< pow(circleRadios + rectScale.y * 0.5f, 2))
			return true;
	}
	//원의 중심이 사각형의 좌우에 있을 때
	else if (topY <= circlePos.y && circlePos.y <= bottomY) {
		if (pow(circlePos.x - rectPos.x, 2)
			< pow(circleRadios + rectScale.x * 0.5f, 2))
			return true;
	}
	//원의 중심이 사각형 모서리쪽에 있을 때
	else {
		float pointX = (circlePos.x < rectPos.x) ? leftX : rightX;
		float pointY = (circlePos.y < rectPos.y) ? topY : bottomY;

		if (pow(pointX - circlePos.x, 2) + pow(pointY - circlePos.y, 2)
			< pow(circleRadios, 2)) {
			return true;
		}
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

UINT64 CCollisionManager::CollisionID(UINT32 leftID, UINT32 rightID)
{
	UINT64 result = 0;

	if (rightID < leftID)
		swap(leftID, rightID);
	result += (UINT64)leftID << 32;
	result += (UINT64)rightID;

	return result;
}
