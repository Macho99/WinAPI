#include "framework.h"
#include "WinAPI.h"
#include "CCollisionManager.h"
#include "CScene.h"
#include "CSceneManager.h"

CCollisionManager::CCollisionManager()
{
	arrLayer[0][0] = { false };
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::Init()
{
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

void CCollisionManager::Release()
{
}

void CCollisionManager::CollisionUpdate(Layer left, Layer right)
{
	CScene* curScene = 
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
