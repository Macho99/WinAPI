#pragma once
class CSceneGameover : public CScene
{
public:
	CSceneGameover();
	virtual ~CSceneGameover();
private:
	void Init() override;
	void Release() override;
	void Enter() override;
	void Exit() override;
	void Update() override;
	void Render() override;

	//void SceneUpdate() override { Update(); };
};