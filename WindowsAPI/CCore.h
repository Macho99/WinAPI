#pragma once

class CCore : public SingleTon<CCore>
{
	friend SingleTon<CCore>;
private:
	float m_fPointX;
	float m_fPointY;
	HDC m_hdc;
	HINSTANCE hInst;
	HWND hWnd;

	CCore();
	virtual ~CCore();

public:
	void Init();
	void Release();
	void Update();
	void Render();
	HINSTANCE GetHInst() { return hInst; }
	HWND GetHWnd() { return hWnd; }
};

#define CORE	CCore::GetInstance()