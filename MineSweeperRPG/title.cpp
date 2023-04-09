#include "title.h"


void titleDraw()
{
	int x = 10;
	int y = 2;
	setCursorView(false);

	_setmode(_fileno(stdout), _O_U16TEXT); // 출력 스트림의 인코딩 방식을 UTF-16LE로 변경
	
	ColorSet(0, 8);
	Sleep(1000);
	Sleep(150);	gotoxy(x, y + 0);		wprintf(L"	             ▄▄                                                       ");
	Sleep(150);	gotoxy(x, y + 1);		wprintf(L"                   ██                    ");
	Sleep(150);	gotoxy(x, y + 3);		wprintf(L"▀████████▄█████▄ ▀███ ▀████████▄   ▄▄█▀██");
	Sleep(150);	gotoxy(x, y + 4);		wprintf(L"  ██    ██    ██   ██   ██    ██  ▄█▀   █");
	Sleep(150);	gotoxy(x, y + 5);		wprintf(L"  ██    ██    ██   ██   ██    ██  ██▀▀▀▀▀");
	Sleep(150);	gotoxy(x, y + 6);		wprintf(L"  ██    ██    ██   ██   ██    ██  ██▄    ");
	Sleep(150);	gotoxy(x, y + 7);		wprintf(L"▄████  ████  ████▄████▄████  ████▄ ▀█████");

	ColorSet(0, 15);
	Sleep(150);	gotoxy(x, y + 10);		wprintf(L" ▄██▀█████▀    ▄█    ▀██▀ ▄▄█▀██  ▄▄█▀██▀████████▄  ▄▄█▀██▀███▄███   ");
	Sleep(150);	gotoxy(x, y + 11);		wprintf(L"███   ▀▀ ██   ▄███   ▄█  ▄█▀   ██▄█▀   ██ ██   ▀██ ▄█▀   ██ ██▀ ▀▀   ");
	Sleep(150);	gotoxy(x, y + 12);		wprintf(L"▀▀█████▄  ██ ▄█  ██ ▄█   ██▀▀▀▀▀▀██▀▀▀▀▀▀ ██    ██ ██▀▀▀▀▀▀ ██       ");
	Sleep(150);	gotoxy(x, y + 13);		wprintf(L"▄█▄   ██   ███    ███    ██▄    ▄██▄    ▄ ██   ▄██ ██▄    ▄ ██       ");
	Sleep(150);	gotoxy(x, y + 14);		wprintf(L"▀██████▀    █      █      ▀█████▀ ▀█████▀ ██████▀   ▀█████▀████▄     ");
	Sleep(150);	gotoxy(x + 42, y + 15);											  wprintf(L"██                         ");
	Sleep(150);	gotoxy(x + 40, y + 16);											wprintf(L"▄████▄                       ");

	ColorSet(0, 7);
	Sleep(150);
	Sleep(150);	gotoxy(x + 55, y + 17);	wprintf(L" ▀███▀▀▀██▄ ▀███▀▀▀██▄  ▄▄█▀▀▀█▄█");
	Sleep(150);	gotoxy(x + 55, y + 18);	wprintf(L"   ██   ▀██▄  ██   ▀██▄██▀     ▀█");
	Sleep(150);	gotoxy(x + 55, y + 19);	wprintf(L"   ██   ▄██   ██   ▄████▀       ▀");
	Sleep(150);	gotoxy(x + 55, y + 20);	wprintf(L"   ███████    ███████ ██           ");
	Sleep(150);	gotoxy(x + 55, y + 21);	wprintf(L"   ██  ██▄    ██      ██▄    ▀████");
	Sleep(150);	gotoxy(x + 55, y + 22);	wprintf(L"   ██   ▀██▄  ██      ▀██▄     ██");
	Sleep(150);	gotoxy(x + 55, y + 23);	wprintf(L"▄████▄   ▄███▄████▄      ▀▀███████");

	ColorSet(0, 4);
	Sleep(1000);
	Sleep(150);	gotoxy(10 + 55, 2 + 17);	wprintf(L" ▀███▀▀▀██▄ ▀███▀▀▀██▄  ▄▄█▀▀▀█▄█");
	Sleep(150);	gotoxy(10 + 55, 2 + 18);	wprintf(L"   ██   ▀██▄  ██   ▀██▄██▀     ▀█");
	Sleep(150);	gotoxy(10 + 55, 2 + 19);	wprintf(L"   ██   ▄██   ██   ▄████▀       ▀");
	Sleep(150);	gotoxy(10 + 55, 2 + 20);	wprintf(L"   ███████    ███████ ██           ");
	Sleep(150);	gotoxy(10 + 55, 2 + 21);	wprintf(L"   ██  ██▄    ██      ██▄    ▀████");
	Sleep(150);	gotoxy(10 + 55, 2 + 22);	wprintf(L"   ██   ▀██▄  ██      ▀██▄     ██");
	Sleep(150);	gotoxy(10 + 55, 2 + 23);	wprintf(L"▄████▄   ▄███▄████▄      ▀▀███████");
	ColorSet(0, 7);
	Sleep(1500);

	ColorSet(0, 7);

	_setmode(_fileno(stdout), _O_TEXT); // 출력 스트림의 인코딩 방식을 기본으로 변경
}


int menuDraw()
{
	int x = 48;
	int y = 28;
	gotoxy(x - 3, y);
	printf("▶");
	gotoxy(x + 1, y);
	printf("GAME START");
	gotoxy(x + 1, y + 1);
	printf("HOW TO PLAY");
	gotoxy(x + 1, y + 2);
	printf("EXIT");

	ColorSet(0, 8);
	gotoxy(x - 4, y + 6);
	printf("PRESS SPACE TO SELECT");
	ColorSet(0, 7);

	while (_kbhit()) // 모든 입력 버퍼를 초기화한다.
		_getch();

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