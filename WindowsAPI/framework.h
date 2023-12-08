﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <cassert>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <clocale>
#include <chrono>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

//Util
#include "SingleTon.h"
#include <crtdbg.h>
#include "Struct.h"
#include "Logger.h"