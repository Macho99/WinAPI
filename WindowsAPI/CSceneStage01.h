#pragma once
#include "CScene.h"
class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();

	float pointX;
	float pointY;

private:
	void Init() override;
	void Enter() override;
	void Update() override;
	void Render() override;
	void Exit() override;
	void Release() override;
};

