#include "framework.h"
#include "WinAPI.h"
#include "CWall.h"
#include "CCollider.h"
#include "CTimeManager.h"

CWall::CWall(TypeWall type)
{
	this->type = type;
	int offset = 5;
	int thickness = 5;
	switch (type)
	{
	case TypeWall::Top:
		pos = Vec2(WINSIZEX * 0.5f, -offset);
		size = Vec2(WINSIZEX, thickness);
		layer = Layer::HorizonWall;
		break;
	case TypeWall::Bottom:
		pos = Vec2(WINSIZEX * 0.5f, WINSIZEY + offset);
		size = Vec2(WINSIZEX, thickness);
		layer = Layer::HorizonWall;
		break;
	case TypeWall::Left:
		pos = Vec2(-offset, WINSIZEY * 0.5f);
		size = Vec2(thickness, WINSIZEY);
		layer = Layer::VerticalWall;
		break;
	case TypeWall::Right:
	default:
		pos = Vec2(WINSIZEX + offset, WINSIZEY * 0.5f);
		size = Vec2(thickness, WINSIZEY);
		layer = Layer::VerticalWall;
		break;
	}
	scale = size;
}

CWall::~CWall()
{
}

void CWall::Init()
{
	AddCollider(ColliderType::Rect, scale);
}

void CWall::Release()
{
}

void CWall::Update()
{
}

void CWall::Render()
{
}
