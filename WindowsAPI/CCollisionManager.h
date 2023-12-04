#pragma once

class CCore;

class CCollisionManager: public SingleTon<CCollisionManager>
{
	friend CCore;
	friend SingleTon<CCollisionManager>;

private:
	CCollisionManager();
	virtual ~CCollisionManager();

	bool arrLayer[(int) Layer::Size][(int) Layer::Size];

private:
	void Init();
	void Update();
	void Release();

private:
	void CollisionUpdate(Layer left, Layer right);

	void CheckLayer(Layer left, Layer right);
	void UnCheckLayer(Layer left, Layer right);
	void ResetCheck();
};

#define COLLISION CCollisionManager::GetInstance()