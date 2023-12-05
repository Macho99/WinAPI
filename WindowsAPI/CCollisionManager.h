#pragma once

class CCore;
class CCollider;

class CCollisionManager: public SingleTon<CCollisionManager>
{
	friend CCore;
	friend SingleTon<CCollisionManager>;

private:
	CCollisionManager();
	virtual ~CCollisionManager();

	bool arrLayer[(int) Layer::Size][(int) Layer::Size];
	unordered_map<UINT64, bool> umapPrevCollision;

private:
	void Init();
	void Update();
	void Release();

private:
	void CollisionUpdate(Layer left, Layer right);
	bool IsCollision(CCollider* leftCollider, CCollider* rightCollider);
	bool RectCollision(Vec2 leftPos, Vec2 leftScale, Vec2 rightPos, Vec2 rightScale);
	bool CircleCollision(Vec2 leftPos, float leftRadios, Vec2 rightPos, float rightRadios);
	bool RectCircleCollision(Vec2 rectPos, Vec2 rectScale, Vec2 circlePos, float circleRadios);

	void CheckLayer(Layer left, Layer right);
	void UnCheckLayer(Layer left, Layer right);
	void ResetCheck();

	UINT64 CollisionID(UINT32 leftID, UINT32 rightID);
};

#define COLLISION CCollisionManager::GetInstance()