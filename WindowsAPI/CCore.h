#pragma once

class CCore : public SingleTon<CCore>
{
	friend SingleTon<CCore>;
private:
	CCore();
	virtual ~CCore();

	bool gameover;

public:
	void Init();
	void Release();
	void Update();
	void Render();
	
	bool GetGameover();
	void SetGameover();
};

#define CORE	CCore::GetInstance()