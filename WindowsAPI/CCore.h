#pragma once

class CCore : public SingleTon<CCore>
{
	friend SingleTon<CCore>;
private:
	float m_fPointX;
	float m_fPointY;

	CCore();
	virtual ~CCore();

public:
	void Init();
	void Release();
	void Update();
	void Render();
};

#define CORE	CCore::GetInstance()