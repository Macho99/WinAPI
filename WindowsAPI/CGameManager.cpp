#include "framework.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

float CGameManager::GetSurviveTime()
{
	return surviveTime;
}

void CGameManager::SetSurviveTime(float surviveTime)
{
	this->surviveTime = surviveTime;
}
