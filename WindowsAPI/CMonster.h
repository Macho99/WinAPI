#pragma once
class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

private:
	Vec2 size;
	int hp;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void OnCollisionEnter(CCollider* otherCollider) override;
	void OnCollisionStay(CCollider* otherCollider) override;
	void OnCollisionExit(CCollider* otherCollider) override;
};

