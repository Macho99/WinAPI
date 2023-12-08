#pragma once

class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();

	const float ballPeriod = 3.f;

	random_device rd;
	uniform_real_distribution<float> dirDist;
	uniform_real_distribution<float> speedDist;
	uniform_real_distribution<float> sizeDist;
	float currentTime;
	float ballTime;

private:
	void Init() override;
	void Enter() override;
	void Update() override;
	void Render() override;
	void Exit() override;
	void Release() override;

	void AddMonster();
	void AddBall();
};

