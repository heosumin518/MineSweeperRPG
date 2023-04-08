#include "ui.h"

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
		gotoxy(12, 10);	printf("가능한 많은 지뢰를 찾아");	
		gotoxy(12, 12);	printf("    적을 공격하자!    ");
	}
	else if (gameMode == 1)
	{
		ColorSet(0, 13);
		gotoxy(15, 8);	printf("QR Code");		
		ColorSet(0, 7);
		gotoxy(12, 10);	printf("가능한 많은 지뢰를 찾아");	
		gotoxy(12, 12);	printf(" 적의 공격을 회피하자! ");
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

	gotoxy(44, 0);	printf("│ time left:          │");	
	gotoxy(44, 1);	printf("└─────────────────────┘");


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

	ColorSet(0, 7);
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

	_setmode(_fileno(stdout), _O_TEXT); // 출력 스트림의 인코딩 방식을 기본으로 변경
}