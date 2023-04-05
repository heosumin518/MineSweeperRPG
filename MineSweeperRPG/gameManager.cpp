#include "gameManager.h"


int keyControl()
{
	char temp = _getch();	// 엔터를 입력하지 않아도 키가 눌리면 바로 변환해주는 입력 함수

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {		// 스페이스바(공백)이 선택 버튼
		return SUBMIT;
	}
}