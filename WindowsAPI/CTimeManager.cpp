#include "framework.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{
	m_uiFPS = 1;
	m_fDT = 1.f;
	updateCount = 0;
	updateOneSecond = 0;
	timeScale = 1.f;

	prevTime = {};
	curTime = {};
}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::Init()
{
	prevTime = chrono::high_resolution_clock::now();
}

void CTimeManager::Update()
{
	curTime = chrono::high_resolution_clock::now();
	chrono::duration<float> elapsed = curTime - prevTime;
	
	m_fDT = elapsed.count();
	if (m_fDT > 0.1f) m_fDT = 0.1f;
	prevTime = curTime;

	updateCount++;
	updateOneSecond += m_fDT;
	if (updateOneSecond > 1.0f)
	{
		m_uiFPS = updateCount;
		updateCount = 0;
		updateOneSecond = 0;
	}
}

void CTimeManager::Release()
{
}

UINT CTimeManager::GetFPS()
{
	return m_uiFPS;
}

float CTimeManager::GetDT()
{
	return m_fDT;
}

float CTimeManager::GetScaledDT()
{
	return m_fDT * timeScale;
}

void CTimeManager::TimePause()
{
	timeScale = 0.f;
}

void CTimeManager::TimeRestart()
{
	timeScale = 1.f;
}

bool CTimeManager::IsTimeStop()
{
	if (timeScale > 0.1f) {
		return false;
	}
	return true;
}
