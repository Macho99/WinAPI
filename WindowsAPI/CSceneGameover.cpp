#include "framework.h"
#include "WinAPI.h"

#include "CSceneManager.h"
#include "CScene.h"
#include "CSceneGameover.h"

CSceneGameover::CSceneGameover()
{
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
	SCENE->GetPrevScene()->GetListObj();
}

void CSceneGameover::Exit()
{
}

void CSceneGameover::Update()
{
}

void CSceneGameover::Render()
{
}