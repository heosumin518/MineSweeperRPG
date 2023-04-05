#include "title.h"


void titleDraw()
{
	int x = 10;
	int y = 7;
	gotoxy(x, y + 0);  printf("##     ## #### ##    ## ########  ######  ##      ## ######## ######## ########  ######## ########  ");
	gotoxy(x, y + 1);  printf("###   ###  ##  ###   ## ##       ##    ## ##  ##  ## ##       ##       ##     ## ##       ##     ## ");
	gotoxy(x, y + 2);  printf("#### ####  ##  ####  ## ##       ##       ##  ##  ## ##       ##       ##     ## ##       ##     ## ");
	gotoxy(x, y + 3);  printf("## ### ##  ##  ## ## ## ######    ######  ##  ##  ## ######   ######   ########  ######   ########  ");
	gotoxy(x, y + 4);  printf("##     ##  ##  ##  #### ##             ## ##  ##  ## ##       ##       ##        ##       ##   ##   ");
	gotoxy(x, y + 5);  printf("##     ##  ##  ##   ### ##       ##    ## ##  ##  ## ##       ##       ##        ##       ##    ##  ");
	gotoxy(x, y + 6);  printf("##     ## #### ##    ## ########  ######   ###  ###  ######## ######## ##        ######## ##     ## ");
	gotoxy(x, y + 8);  printf("                                    ########  ########   ######                                     ");
	gotoxy(x, y + 9);  printf("                                    ##     ## ##     ## ##    ##                                    ");
	gotoxy(x, y + 10); printf("                                    ##     ## ##     ## ##                                          ");
	gotoxy(x, y + 11); printf("                                    ########  ########  ##   ####                                   ");
	gotoxy(x, y + 12); printf("                                    ##   ##   ##        ##    ##                                    ");
	gotoxy(x, y + 13); printf("                                    ##    ##  ##        ##    ##                                    ");
	gotoxy(x, y + 14); printf("                                    ##     ## ##         ######                                     ");
}


int menuDraw()
{
	int x = 55;
	int y = 28;
	gotoxy(x - 3, y);
	printf("▶ GAME START");
	gotoxy(x, y + 1);
	printf("HOW TO PLAY");
	gotoxy(x, y + 2);
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