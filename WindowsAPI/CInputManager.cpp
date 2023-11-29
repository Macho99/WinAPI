#include "framework.h"
#include "CInputManager.h"
#include "WinAPI.h"

CInputManager::CInputManager()
{
	Init();
}

CInputManager::~CInputManager()
{
}

void CInputManager::Init()
{
	m_arrPrevKey[0] = { false };
	m_arrCurKey[0] = { false };
	m_ptMousePos = { 0,0 };
}

void CInputManager::Update()
{
	//0. 윈도우가 선택된 상황일때만 진행
	if (GetFocus() != hWnd) {
		for (int key = 0; key < VKEY_SIZE; key++) {
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}

	//1. 현재키 입력상태를 갱신
	for (int key = 0; key < VKEY_SIZE; key++) {
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000) {
			m_arrCurKey[key] = true;
		}
		else {
			m_arrCurKey[key] = false;
		}
	}
	
	//마우스 좌표 반환(모니터 좌상단 기준)
	GetCursorPos(&m_ptMousePos);
	//게임 윈도우 기준 좌표로 변환
	ScreenToClient(hWnd, &m_ptMousePos);
}

void CInputManager::Release()
{
}

bool CInputManager::GetButton(const int key)
{
	return (m_arrPrevKey[key] == true && m_arrCurKey[key] == true);
}

bool CInputManager::GetButtonDown(const int key)
{
	return (m_arrPrevKey[key] == false && m_arrCurKey[key] == true);
}

bool CInputManager::GetButtonUp(const int key)
{
	return (m_arrPrevKey[key] == true && m_arrCurKey[key] == false);
}

POINT CInputManager::GetMousePos()
{
	return m_ptMousePos;
}
