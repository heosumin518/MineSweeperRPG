#pragma once
#include "main.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void init();		// 콘솔 화면 크기 지정
void gotoxy(int, int);	// 마우스 커서를 이동
void setCursorView(bool);	// 커서 켜고 끄기
void ColorSet(int backColor, int textColor);	// 텍스트 색상 변경