#pragma once

class CCore : public SingleTon<CCore>
{
	friend SingleTon<CCore>;
private:
	CCore();
	virtual ~CCore();

public:
	void Init();
	void Release();
	void Update();
	void Render();
};

#define CORE	CCore::GetInstance()