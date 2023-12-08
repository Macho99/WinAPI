#include "framework.h"
#include "WinAPI.h"

#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"
#include "CScene.h"
#include "CSceneGameover.h"
#include "CGameManager.h"

CSceneGameover::CSceneGameover()
{
	float percent = 0.3f;
	left = WINSIZEX * percent;
	right = WINSIZEX * (1 - percent);
	top = WINSIZEY * percent;
	bottom = WINSIZEY * (1 - percent);
	surviveTime = 0.f;
}

CSceneGameover::~CSceneGameover()
{
}

void CSceneGameover::Init()
{
}

void CSceneGameover::Release()
{

}

void CSceneGameover::Enter()
{
	TIME->TimePause();
	SetListObj(SCENE->GetPrevScene()->GetListObj());
	surviveTime = CGameManager::GetInstance()->GetSurviveTime();
}

void CSceneGameover::Exit()
{
	TIME->TimeRestart();
}

void CSceneGameover::Update()
{
	if (INPUT->GetButtonDown(VK_SPACE)) {
		EVENT->EventChangeScene(GroupScene::Title);
	}
}

void CSceneGameover::Render()
{
	RENDER->SetBrush(BrushType::Solid, RGB(255, 255, 255));
	RENDER->Rect(left, top, right, bottom);
	RENDER->SetText(TextType::Center);
	RENDER->Text(WINSIZEX * 0.5f, WINSIZEY * 0.5f - 50.f, L"생존시간: " + to_wstring(surviveTime));
	RENDER->Text(WINSIZEX * 0.5f, WINSIZEY * 0.5f - 30.f, L"게임 오버");
	RENDER->Text(WINSIZEX * 0.5f, WINSIZEY * 0.5f, L"메뉴로 가려면 '스페이스바'를 누르세요..");
}

void CSceneGameover::SceneRelease()
{
	Release();
}
