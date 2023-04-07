#include "title.h"


void titleDraw()
{
	int x = 8;
	int y = 5;
	setCursorView(false);

	gotoxy(x, y + 0);  printf("              d8b                                                                                      ");
	gotoxy(x, y + 1);  printf("              Y8P                                                                                      ");
	gotoxy(x, y + 3);  printf("88888b.d88b.  888 88888b.   .d88b.  .d8888b  888  888  888  .d88b.   .d88b.  88888b.   .d88b.  888d888 ");
	gotoxy(x, y + 4);  printf("888 \"888 \"88b 888 888 \"88b d8P  Y8b 88K      888  888  888 d8P  Y8b d8P  Y8b 888 \"88b d8P  Y8b 888P\"   ");
	gotoxy(x, y + 5);  printf("888  888  888 888 888  888 88888888 \"Y8888b. 888  888  888 88888888 88888888 888  888 88888888 888     ");
	gotoxy(x, y + 6);  printf("888  888  888 888 888  888 Y8b.          X88 Y88b 888 d88P Y8b.     Y8b.     888 d88P Y8b.     888     ");
	gotoxy(x, y + 7);  printf("888  888  888 888 888  888  \"Y8888   88888P'  \"Y8888888P\"   \"Y8888   \"Y8888  88888P\"   \"Y8888  888     ");
	gotoxy(x, y + 8);  printf("                                                                             888                       ");
	gotoxy(x, y + 9); printf("                                                                             888                       ");
	gotoxy(x, y + 10); printf("                                                                             888                       ");
	gotoxy(x, y + 11); printf("                                  8888888b.  8888888b.   .d8888b.                                      ");
	gotoxy(x, y + 12); printf("                                  888   Y88b 888   Y88b d88P  Y88b                                     ");
	gotoxy(x, y + 13); printf("                                  888    888 888    888 888    888                                     ");
	gotoxy(x, y + 14); printf("                                  888   d88P 888   d88P 888                                            ");
	gotoxy(x, y + 15); printf("                                  8888888P\"  8888888P\"  888  88888                                     ");
	gotoxy(x, y + 16); printf("                                  888 T88b   888        888    888                                     ");
	gotoxy(x, y + 17); printf("                                  888  T88b  888        Y88b  d88P                                     ");
	gotoxy(x, y + 18); printf("                                  888   T88b 888         \"Y8888P88                                     ");
}


int menuDraw()
{
	int x = 55;
	int y = 28;
	gotoxy(x - 3, y);
	printf("▶");
	gotoxy(x + 1, y);
	printf("GAME START");
	gotoxy(x + 1, y + 1);
	printf("HOW TO PLAY");
	gotoxy(x + 1, y + 2);
	printf("EXIT");


	while (true)	// 키보드 입력을 무한정 받고 기다리고 하는 부분
	{
		int n = keyControl();		// 키보드 이벤트를 키값으로 받아오기 // 키보드의 키코드를 임시로 저장하는 변수
		switch (n) {
		case UP: {
			if (y > 28) {	// 메뉴 위로 벗어나지 않기
				gotoxy(x - 3, y);	// ">"를 두칸 이전에 출력하기 위해 x-2 를 함
				printf("   ");		// 원래 있던 ">"를 지움
				gotoxy(x - 3, --y);	// 새 위치로 이동하여
				printf("▶");		// 다시 ">" 그리기
			}
			break;
		}
		case DOWN: {
			if (y < 30) {	// 메뉴 아래로 벗어나지 않기
				gotoxy(x - 3, y);
				printf("   ");
				gotoxy(x - 3, ++y);
				printf("▶");
			}
			break;
		}
		case SUBMIT: {
			return y - 28;
			// y 시작 위치가 30였으므로 y-30를 하면 0, 1, 2 세 숫자를 받아올 수 있다.
		}
		}
	}
}


void howToPlay()
{
	int x = 5; int y = 5;
	
	system("cls");

	gotoxy(x + 29, y); printf("<<게임 플레이 방법>>");

	while (true)
	{
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}