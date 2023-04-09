#pragma once
#include "util.h"
#include <io.h>
#define _O_U16TEXT 0x20000
#define _O_TEXT 0x4000

void drawUI(int);

void drawStory();

void drawEnding();	// 매개변수로 게임 승리여부 전달하기

void drawTime(int, int, int);

void drawIntro();
