#include "minesweeper.h"


// 지뢰찾기 
int mineSweeper()
{
	system("cls");

	char mine_table[Y_COUNT][X_COUNT];	// 폭탄이 설치된 정보를 저장할 변수
	char check_table[Y_COUNT][X_COUNT]; // 사용자가 선택한 위치를 기억할 변수
	srand((unsigned)time(NULL));		// 현재 시간을 기준으로 난수를 설정.

	createMineTable(mine_table, check_table);		// 폭탄 설치 정보를 구성한다.

	// 선택 정보를 반영하여 지뢰 정보를 출력한다.
	// @ 문자로 출력된 것은 아직 확인이 안된 항목이다.
	showCurrentState(mine_table, check_table);

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = true;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	

	int x = 0;
	int y = 0;
	int flag = 0;
	int count = 0;
	gotoxy(x, y);
	while (true) {
		int ch = _getch();
		if (ch == 112)  // P 를 눌렀을 경우 플레이 종료
			break;
		if (ch == 32)	// 스페이스 키를 칠 경우 칸을 연다
		{
			if (mine_table[y][x] == '*')	// 폭탄일 경우
			{
				printf("*");
				gotoxy(50, 50);
				printf("클리어 실패");
				Sleep(2000);
				break;
			}
			else		// 폭탄이 아닐 경우
			{
				if (mine_table[y][x] == '0') printf(" ");
				else printf("%c", mine_table[y][x]);
				gotoxy(x, y);
				// 주위 검색해서 지뢰가 모두 없다면 다 열기 (그거 구현)
			}
		}
		if (ch == 70 || ch == 102)	// 사용자가 F 키를 누를 경우 깃발 꽃기
		{
			printf("^");
			gotoxy(x, y);
			if (mine_table[y][x] == '*')	// 폭탄일 경우
			{
				if (check_table[y][x] == 0)		// 했던 곳인지 확인
				{
					check_table[y][x]++;
					flag += 1;

					if (flag == MINE_COUNT)		// 지뢰를 모두 깃발표시 하였을 경우
					{
						gotoxy(0, 0);
						printf("지뢰를 모두 찾았습니다!\n");
						Sleep(2000);
						break;
					}
				}
			}
			else	// 폭탄이 아닐경우, 깃발 꽂기
			{
				mine_table[y][x] = '^';
			}
		}

		if (ch == 224)	// 방향이 이동
		{
			ch = _getch();
			switch (ch)
			{
				case 72: {	// 위로 이동
					if ((y - 1) >= 0)	// 범위 나가지 않게
						y -= 1;
					break;
				}
				case 80: {	// 아래로 이동
					if ((y + 1) < Y_COUNT)	// 범위 나가지 않게
						y += 1;
					break;
				}
				case 75: {	// 왼쪽으로 이동
					if ((x - 1) >= 0)	// 범위 나가지 않게
						x -= 1;
					break;
				}
				case 77: {	// 오른쪽으로 이동
					if ((x + 1) < X_COUNT)	// 범위 나가지 않게
						x += 1;
					break;
				}
			}
			gotoxy(x, y);
		}
		
	}

	showMineTable(mine_table);			// 전체 설치 정보를 확인한다.

	return 0; // 임시. 이 함수 완성하면서 삭제하기
}

void createMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT])
{
	int x, y, mine_count;
	// mine 정보를 저장할 메모리에 모두 0을 채운다.
	memset(mine_table, 0, Y_COUNT * X_COUNT);
	// 사용자의 선택 정보를 저장할 메모리에 모두 0을 채운다.
	memset(check_table, 0, Y_COUNT * X_COUNT);

	// 폭탄을 MINE_COUNT 개 만큼 생성한다.
	for (mine_count = 0; mine_count < MINE_COUNT; mine_count++) {
		// 난수를 사용하여 폭탄이 위치할 곳을 생성한다.
		x = rand() % X_COUNT;
		y = rand() % Y_COUNT;
		// 폭탄이 설치된 곳이 아니라면 폭탄을 설치하고 이미 설치된 곳이라면
		// 폭탄의 수를 줄여서 다시 시도하게 한다.
		if (mine_table[y][x] == 0) mine_table[y][x] = '*';
		else mine_count--;
	}

	for (y = 0; y < Y_COUNT; y++) {
		for (x = 0; x < X_COUNT; x++) {
			// 폭탄이 아니라면 인접한 위치에 폭탄이 몇개 있는지 체크한다.
			if (mine_table[y][x] == 0) {
				// 폭탄의 수를 초기화한다.
				mine_count = 0;

				// 현재 위치 (C)를 중심으로 총 8방향의 위치에 폭탄이 몇 개 있는지 체크한다.
				// 1, 2, 3
				// 4, C, 5
				// 6, 7, 8

				if ((y - 1) >= 0) {		// 음수가 나오지 않게 체크한다.
					// 1, 2, 3번 항목을 체크한다.
					if ((x - 1) >= 0 && mine_table[y - 1][x - 1] == '*') mine_count++;
					if (mine_table[y - 1][x] == '*') mine_count++;
					if ((x + 1) < X_COUNT && mine_table[y - 1][x + 1] == '*') mine_count++;
				}

				// 4, 5번 항목을 체크한다.
				if ((x - 1) >= 0 && mine_table[y][x - 1] == '*') mine_count++;
				if ((x + 1) < X_COUNT && mine_table[y][x + 1] == '*') mine_count++;

				// 6, 7, 8 항목을 체크한다.
				if ((y + 1) < Y_COUNT) {	// 범위를 벗어나지 않게 체크한다.
					if ((x - 1) >= 0 && mine_table[y + 1][x - 1] == '*') mine_count++;
					if (mine_table[y + 1][x] == '*') mine_count++;
					if ((x + 1) < X_COUNT && mine_table[y + 1][x + 1] == '*') mine_count++;
				}

				// 계산된 폭탄 수를 정수에서 문자로 변경해서 현재 위치에 대입한다.
				// 예를 들어, 5라면 '5로 저장한다.
				mine_table[y][x] = '0' + mine_count;
			}
		}
	}
}

void showMineTable(char mine_table[][X_COUNT])		// 게임 종료시 전체 지뢰를 보여주는 함수
{
	system("cls");	// 화면 한번 지우기 // 임 ******** 시
	for (int y = 0; y < Y_COUNT; y++) {
		// 한 줄의 정보를 출력한다.
		printf(" ");
		for (int x = 0; x < X_COUNT; x++) printf("%c", mine_table[y][x]);
		printf("\n");	// 줄바꿈
	}
	printf("\n");	// 줄바꿈
}

void showCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT])		// 현재 지뢰게임보드 상태를 보여주는 함수
{
	for (int y = 0; y < Y_COUNT; y++) {
		// 한 줄의 정보를 출력한다.
		for (int x = 0; x < X_COUNT; x++) {
			if (check_table[y][x]) printf("%c", mine_table[y][x]);
			else printf("@");
		}
		printf("\n"); // 줄바꿈
	}
	printf("\n");	// 줄바꿈
}