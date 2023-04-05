#include "main.h"
#include "title.h"
#include "util.h"
#include "gameManager.h"
#include "minesweeper.h"


int main()
{
	init();
	while (true)
	{
		titleDraw();
		int menuCode = menuDraw();
		if		(menuCode == 0) {
			mineSweeper();	// 게임시작
			system("pause");	// 디버깅용. 이후 삭제하기
		}
		else if (menuCode == 1) {
			howToPlay();	// 게임 방법
		}
		else if (menuCode == 2) {
			return 0;		// 종료
		}
		system("cls");		// 콘솔창의 모든 글자 클리어. 콘솔 좌표 0, 0 으로 초기화
	}

}
