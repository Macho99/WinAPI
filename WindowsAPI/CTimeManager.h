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
	float m_fDT;	//Delta Time: 1�����Ӵ� �ҿ�ð�
	float timeScale;

	UINT updateCount;		//1�� ���� ������Ʈ �� Ƚ��
	float updateOneSecond;	//1�ʸ� �����ϱ� ���� �����ϴ� �ڷ�

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
