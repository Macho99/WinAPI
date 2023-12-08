#pragma once
class CCore;

class CTimeManager : public SingleTon<CTimeManager>
{
	friend SingleTon<CTimeManager>;
	friend CCore;
private:
	CTimeManager();
	virtual ~CTimeManager();

	UINT m_uiFPS;	//FPS
	float m_fDT;	//Delta Time: 1프레임당 소요시간
	float timeScale;

	UINT updateCount;		//1초 동안 업데이트 된 횟수
	float updateOneSecond;	//1초를 측정하기 위해 보관하는 자료

	chrono::high_resolution_clock::time_point prevTime;
	chrono::high_resolution_clock::time_point curTime;

	void Init();
	void Update();
	void Release();

public:
	UINT GetFPS();
	float GetDT();
	float GetScaledDT();
	void TimePause();
	void TimeRestart();
	bool IsTimeStop();
};

#define TIME	CTimeManager::GetInstance()
#define DT		CTimeManager::GetInstance()->GetScaledDT()
#define FPS		CTimeManager::GetInstance()->GetFPS()
