#pragma once

class CGameObject;

class CComponent
{
	friend CGameObject;
public:
	CComponent();
	virtual ~CComponent();

private:
	CGameObject* owner;

private:
	void SetOwner(CGameObject* owner);
public:
	CGameObject* GetOwner();

private:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void PhysicsUpdate() {};
	virtual void Render() = 0;
	virtual void Release() = 0;
};