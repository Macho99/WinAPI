#pragma once

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
private:
	CGameManager();
	virtual ~CGameManager();

	float surviveTime;

public:
	float GetSurviveTime();
	void SetSurviveTime(float surviveTime);
};

