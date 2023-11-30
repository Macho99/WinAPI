#pragma once

class CScene;
class CEventManager;

class CGameObject
{
	friend CScene;
	friend CEventManager;
public:
	CGameObject();
	virtual ~CGameObject();

protected:
	Vec2 pos;
	Vec2 scale;

private:
	bool reserveDelete;
	bool safeToDelete;
	void SetReserveDelete();
	void SetSafeToDelete();

public:
	bool GetReserveDelete();
	bool GetSafeToDelete();

public:
	Vec2 GetPos();
	void SetPos(Vec2 pos);
	void SetPos(float x, float y);
	Vec2 GetScale();
	void SetScale(Vec2 scale);
	void SetScale(float x, float y);

private:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};