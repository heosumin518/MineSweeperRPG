#include "draw.h"

void drawTime(int timeLeft, int x, int y)
{
	// 남은시간 출력
	gotoxy(28, 2);
	printf("남은시간: %2d", timeLeft);
}

void drawUI(int gameMode)
{

	// 조작키 설명
	gotoxy(81, 8);	printf("이동: ← ↑ ↓ →");	
	gotoxy(81, 10);	printf("깃발: F");		
	gotoxy(81, 12);	printf("열기: Space bar");


	// 게임 정보 출력
	if (gameMode == 0)
	{
		ColorSet(0, 3);
		gotoxy(15, 8);	printf(" Player");	
		ColorSet(0, 7);
		gotoxy(12, 10);	printf("가능한 많은 폭탄을 찾아");	
		gotoxy(12, 12);	printf("    적을 공격하자!    ");
	}
	else if (gameMode == 1)
	{
		ColorSet(0, 13);
		gotoxy(15, 8);	printf("QR Code");		
		ColorSet(0, 7);
		gotoxy(12, 10);	printf("가능한 많은 방패를 찾아");	
		gotoxy(12, 12);	printf(" 적의 공격을 막아내자! ");
	}
	gotoxy(22, 8);	printf("의 턴이다!");


	// 지뢰보드 외곽네모상자 그리기
	gotoxy(45, 20);	printf("┌─────────────────┐");	
	gotoxy(45, 21);	printf("│                 │");	
	gotoxy(45, 22); printf("│                 │");	
	gotoxy(45, 23);	printf("│                 │");	
	gotoxy(45, 24);	printf("│                 │");	
	gotoxy(45, 25);	printf("│                 │");	
	gotoxy(45, 26);	printf("│                 │");	
	gotoxy(45, 27);	printf("│                 │");	
	gotoxy(45, 28);	printf("│                 │");	
	gotoxy(45, 29);	printf("└─────────────────┘");


	_setmode(_fileno(stdout), _O_U16TEXT); // 출력 스트림의 인코딩 방식을 UTF-16LE로 변경
	if (gameMode == 0)
		ColorSet(0, 14);		// 밝은 레드 6 그린 10
	else
		ColorSet(0, 7);		// 흰색
	gotoxy(74, 20);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤");	
	gotoxy(74, 21);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠛⠛⠛⠛⣿⣿");	
	gotoxy(74, 22);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⠀⠀⠀⠀⣿⣿");	
	gotoxy(74, 23); wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⣠⣄⠀⠀⠀⢀⣿⣿");	
	gotoxy(74, 24); wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋");	
	gotoxy(74, 25); wprintf(L"⠀⠀⠀⢀⣄⠀⣠⣾⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀");	
	gotoxy(74, 26); wprintf(L"⠀⠀⠀⠻⣿⣿⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀⠀⠀");	
	gotoxy(74, 27); wprintf(L"⠀⠀⠀⠀⠈⣻⣿⣷⣤⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀");	
	gotoxy(74, 28); wprintf(L"⠀⠀⠀⣠⣾⣿⠟⠻⣿⣿⣄⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀");	
	gotoxy(74, 29); wprintf(L"⠀⣠⣾⣿⣿⣅⢀⣴⣿⡿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");	
	gotoxy(74, 30); wprintf(L"⣼⣿⠟⠉⢻⣿⣿⡿⠋⠀⠈⠻⣿⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");	
	gotoxy(74, 31); wprintf(L"⢻⣿⣦⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");	
	gotoxy(74, 32); wprintf(L"⠀⠉⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	// 검 (=플레이어의 턴)

	if (gameMode == 1)
		ColorSet(0, 14);		// 스카이블루 3 그린 10
	else
		ColorSet(0, 7);		// 흰색
	gotoxy(8, 18);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 19);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 20);	wprintf(L"⠀⠀⠀⠀⠀⠀⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣤⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 21);	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 22);	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 23);	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 24);	wprintf(L"⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 25);	wprintf(L"⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 26);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 27);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 28);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 29);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 30);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 31);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(8, 32);	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	// 방패 (=몬스터의 턴)

	ColorSet(0, 4);
	gotoxy(54, 32);	wprintf(L"❤");

	ColorSet(0, 15);	// 진한 흰색
	gotoxy(44, 6);	wprintf(L" ▄▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄▄▄▄ ");
	gotoxy(44, 7);	wprintf(L" █ ▄▄▄ █  █▄▀  █ ▄▄▄ █ ");
	gotoxy(44, 8);	wprintf(L" █ ███ █  ▀█▀▄ █ ███ █ ");
	gotoxy(44, 9);	wprintf(L" █▄▄▄▄▄█ ▄ ▄▀█ █▄▄▄▄▄█ ");
	gotoxy(44, 10);	wprintf(L" ▄▄ ▄▄ ▄ ▀██▀█ ▄     ▄ ");
	gotoxy(44, 11);	wprintf(L" ▄ █▄ █▄ ▀▀▄ ▀ ▀█▄█▄   ");
	gotoxy(44, 12);	wprintf(L" ▄▀▀▀▄█▄▀ ▀▄▀  ▀▄ ▀ █▀ ");
	gotoxy(44, 13);	wprintf(L" ▄▄▄▄▄▄▄ ▀▀  ██▀ ▀▀█▀▄ ");
	gotoxy(44, 14);	wprintf(L" █ ▄▄▄ █ ▄█▀▀▀▀ ▄██ ▄▀ ");
	gotoxy(44, 15);	wprintf(L" █ ███ █ ▀▄▀▄▀██▄ ▀ ▄▄ ");
	gotoxy(44, 16);	wprintf(L" █▄▄▄▄▄█ █▀▄▄██ █▀ ▄▀▀ ");
	// 몬스터 (=무단결석)


	ColorSet(0, 7);
	_setmode(_fileno(stdout), _O_TEXT); // 출력 스트림의 인코딩 방식을 기본으로 변경
}

void drawStory()
{
	system("cls");

	Sleep(500);

	while (_kbhit()) // 현재까지의 입력 버퍼를 초기화한다.
		_getch();

	ColorSet(0, 15);	// 진한 흰색

	char story1 [255] = "오후 5시.수업이 끝나는 시간";
	char* ptr = story1;

	gotoxy(15, 15);

	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}

		if (*ptr == '.')
		{
			Sleep(1000);
			gotoxy(15, 17);
			ptr += 1;
		}
	}

	setCursorView(true);
	_getch();
	setCursorView(false);

	char story2[255] = "당신은 버스시간에 늦지않게 부리나케 짐을 챙겨 집으로 향한다.";
	ptr = story2;

	system("cls");
	gotoxy(15, 15);
	Sleep(1000);
	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}
	}

	char story3[255] = "그런데 이런..!너무 급하게 나가버려 하원 QR 찍는 것을 깜빡하고 마는데..";
	ptr = story3;

	setCursorView(true);
	_getch();
	setCursorView(false);

	system("cls");
	gotoxy(15, 15);
	Sleep(1000);
	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}
		if (*ptr == '!')
		{
			Sleep(1000);
			gotoxy(15, 17);
			ptr += 1;
		}
	}

	setCursorView(true);
	_getch();
	setCursorView(false);

	char story4[255] = "출석률은 이미 80퍼센트대로 내려간 상태.무언가 조치를 취해야만 한다";
	ptr = story4;

	system("cls");
	gotoxy(15, 15);
	Sleep(1000);
	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}
		if (*ptr == '.')
		{
			Sleep(1000);
			gotoxy(15, 17);
			ptr += 1;
		}
	}

	setCursorView(true);
	_getch();
	setCursorView(false);

	char story5[255] = "출석경고의 위협을 받고 있는 당신!!";
	ptr = story5;

	system("cls");
	gotoxy(15, 15);
	Sleep(1000);
	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}
	}

	char story6[255] = "QR 코드를 물리쳐 출석률을 100퍼센트로 되돌려라!!!";
	ptr = story6;

	gotoxy(15, 17);
	Sleep(1000);
	while (*ptr)
	{
		if (_kbhit())
			break;

		if (*ptr <= 128 && *ptr >= 0)
		{
			printf("%c", *ptr); Sleep(50);
			ptr += 1;
		}
		else
		{
			printf("%c%c", *ptr, *(ptr + 1)); Sleep(50);
			ptr += 2;
		}
	}



	ColorSet(0, 7);

	while (_kbhit()) // 현재까지의 입력 버퍼를 초기화한다.
		_getch();

	int _frames = 0;

	for (_frames = 0;; _frames++)
	{
		if (_kbhit())
			break;

		if (_frames % 150 == 0) // 200 프레임마다 띄움
		{
			gotoxy(40, 30); printf("아무 키나 눌러서 출석률 높이러 가기"); // 반짝거리게 하고 싶은 욕심 PRESS ANY KEY TO START GAME
		}
		else if ((_frames % 150 - 100) == 0) // 100 프레임 간격으로 지움 (1초 + @) 
		{
			gotoxy(40, 30); printf("                                       "); // 반짝거리게 하고 싶은 욕심
		}

		Sleep(10);
	}

	system("cls");
}