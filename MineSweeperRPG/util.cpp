#include "util.h"


void init()
{
	system("mode con cols=120 lines=36 | title 지뢰찾기 RPG");		// 콘솔창 크기 초기화

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;		// false 또는 0 : 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}