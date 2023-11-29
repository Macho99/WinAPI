#pragma once

class CCore;

class CInputManager : public SingleTon<CInputManager>
{
	friend SingleTon<CInputManager>;
	friend CCore;
private:
	static const int VKEY_SIZE = 255;	//VK�� �ִ� ����

	bool m_arrPrevKey[VKEY_SIZE];		//���� Ű�� �Է»���
	bool m_arrCurKey[VKEY_SIZE];		//���� Ű�� �Է»���
	POINT m_ptMousePos;					//���� ���콺 ��ġ

	CInputManager();
	virtual ~CInputManager();

	void Init();
	void Update();
	void Release();

public:
	bool GetButton(const int key);		//Ű�� ������ �ִ� ��
	bool GetButtonDown(const int key);	//Ű�� ������ ����
	bool GetButtonUp(const int key);	//Ű�� �÷��� ����
	POINT GetMousePos();				//���� ���콺 ��ġ
};

#define INPUT					CInputManager::GetInstance()
#define BUTTONSTAY(key)			CInputManager::GetInstance()->GetButton(key)
#define BUTTONDOWN(key)			CInputManager::GetInstance()->GetButtonDown(key)
#define BUTTONUP(key)			CInputManager::GetInstance()->GetButtonUp(key)
#define MOUSEPOS				CInputManager::GetInstance()->GetMousePos()
