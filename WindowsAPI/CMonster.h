#pragma once
class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

private:
	Vec2 size;

private:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;
};

