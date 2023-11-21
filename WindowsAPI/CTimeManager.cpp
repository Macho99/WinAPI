#include "framework.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{
	m_uiFPS = 1;
	m_fDT = 1;
	updateCount = 0;
	updateOneSecond = 0;

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
