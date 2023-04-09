#include "gameManager.h"


bool gamePlay()		// 승리 여부 반환하기
{
	int gameMode = 0;	// 0은 플레이어 1은 몬스터의 턴
	bool gameOver = false;		// 게임 종료 여부
	int monsterHP = 20;
	int playerHP = 10;
	int flag = 0;
	int round = 0;	// 라운드 수
	bool isWin = false;

	system("cls");
	Sleep(1000);
	PlaySound(TEXT("gameStart.wav"), NULL, SND_ASYNC | SND_LOOP);	// 타이틀 배경음 재생

	Sleep(2000);

	while (true)		// 여기에 몬스터 HP 변수를 넣어도?
	{

		gotoxy(49, 30);
		printf("HP: %2d / 10", playerHP);	// 플레이어 HP
		gotoxy(50, 5);
		printf("HP: %2d / 20", monsterHP);	// 몬스터 HP

		if (monsterHP <= 0)
		{
			isWin = true;
			break;	// 몬스터의  HP를 다 깎으면 게임종료
		}
		if (playerHP <= 0)
		{
			isWin = false;
			break;  // 플레이어의 HP가 0이 되면 게임종료
		}


		flag = 0;
		flag += mineSweeper(monsterHP, playerHP, gameMode);

		round++;

		if (gameMode == 0)	// 플레이어 턴
		{
			
			Sleep(1000);
			while (_kbhit()) // 현재까지의 입력 버퍼를 초기화한다.
				_getch();
			gotoxy(35, 34);
			printf("                                          ");
			gotoxy(50, 34);
			printf("라운드 종료!", flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                          ");
			gotoxy(43, 34);
			Sleep(500);
			printf("적에게 %2d 만큼의 데미지!", flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                          ");

			monsterHP -= flag;	// 깃발 표시한 수 만큼 몬스터의 HP를 깎는다.
			if (monsterHP < 0)
				monsterHP = 0;	// 몬스터의 HP 는 양수로만 표시하기 위해
			gameMode = 1;
		}
		else if (gameMode == 1)	// 몬스터의 턴
		{
			
			Sleep(1000);
			while (_kbhit()) // 현재까지의 입력 버퍼를 초기화한다.
				_getch();
			gotoxy(35, 34);
			printf("                                         ");
			gotoxy(49, 34);
			printf("라운드 종료!", flag);
			Sleep(100);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                         ");
			gotoxy(40, 34);
			Sleep(500);
			printf("적이 당신을 %d 의 데미지로 공격!", MINE_COUNT - flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                           ");

			playerHP -= (MINE_COUNT - flag);	// 깃발 표시한 수 만큼 몬스터의 공격을 방어한다.
			if (playerHP < 0) playerHP = 0;	// 플레이어의 HP 는 양수로만 표시하기 위해
			gameMode = 0;
		}

		gotoxy(49, 30);
		printf("HP: %2d / 10", playerHP);	// 플레이어 HP
		gotoxy(50, 5);
		printf("HP: %2d / 20", monsterHP);	// 몬스터 HP



	}
	return isWin;
}



int keyControl()
{
	char temp = _getch();	// 엔터를 입력하지 않아도 키가 눌리면 바로 변환해주는 입력 함수

	// 방향키로 이동
	if (temp == 72) {
		return UP;
	}
	else if (temp == 75) {
		return LEFT;
	}
	else if (temp == 80) {
		return DOWN;
	}
	else if (temp == 77) {
		return RIGHT;
	}
	else if (temp == ' ') {		// 스페이스바(공백)이 선택 버튼
		return SUBMIT;
	}
}