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
		PlaySound(TEXT("title.wav"), NULL, SND_ASYNC | SND_LOOP);	// 타이틀 배경음 재생
		titleDraw();
		int menuCode = menuDraw();
		bool isWin = false;
		if	(menuCode == 0) {
			PlaySound(NULL, 0, 0);
			drawStory();
			drawIntro();
			isWin = gamePlay();
			PlaySound(NULL, 0, 0);

			drawEnding(isWin);	// 엔딩 출력 후 게임 종료

			PlaySound(NULL, 0, 0);
		}
		else if (menuCode == 1) {
			PlaySound(NULL, 0, 0);
			drawHowTo();	// 게임 방법
		}
		else if (menuCode == 2) {
			return 0;		// 종료
		}
		system("cls");		// 콘솔창의 모든 글자 클리어. 콘솔 좌표 0, 0 으로 초기화
	}

}
