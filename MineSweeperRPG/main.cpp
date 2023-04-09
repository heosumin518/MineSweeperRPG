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
		PlaySound(TEXT("title.wav"), NULL, SND_ASYNC | SND_LOOP);
		titleDraw();
		int menuCode = menuDraw();
		bool isWin = false;
		if	(menuCode == 0) {
			PlaySound(NULL, 0, 0);
			drawStory();
			isWin = gamePlay();
			gotoxy(0, 35);
			printf("게임종료");
			if (isWin)
			{
				gotoxy(40, 35);
				printf("플레이어의 승리!");
			}
			else
			{
				gotoxy(40, 35);
				printf("패배..!");
			}
			system("pause");	// 디버깅용. 이후 삭제하기
		}
		else if (menuCode == 1) {
			PlaySound(NULL, 0, 0);
			howToPlay();	// 게임 방법
		}
		else if (menuCode == 2) {
			return 0;		// 종료
		}
		system("cls");		// 콘솔창의 모든 글자 클리어. 콘솔 좌표 0, 0 으로 초기화
	}

}
