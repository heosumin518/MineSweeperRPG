#pragma once
#include "util.h"
#include <io.h>
#define _O_U16TEXT 0x20000
#define _O_TEXT 0x4000

void drawUI(int);

void drawStory();

void drawEnding(bool);	// 굿엔딩, 베드엔딩 총 두가지 엔딩이 존재

void drawTime(int, int, int);

void drawIntro();

void drawHowTo();
