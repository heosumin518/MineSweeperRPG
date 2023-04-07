#include "minesweeper.h"

#include <io.h>
#define _O_U16TEXT 0x20000
#define _O_TEXT 0x4000



void ColorSet(int backColor, int textColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backColor << 4) + textColor);
}



// 지뢰찾기 
int mineSweeper(int monster, int player)
{
	system("cls");

	gotoxy(54, 30);
	printf("HP: %2d / 10", player);	// 플레이어 HP
	gotoxy(54, 5);
	printf("HP: %2d / 15", monster);	// 몬스터 HP

	char mine_table[Y_COUNT][X_COUNT];	// 폭탄이 설치된 정보를 저장할 변수
	char check_table[Y_COUNT][X_COUNT]; // 사용자가 선택한 위치를 기억할 변수
	char flag_table[Y_COUNT][X_COUNT];	// 깃발이 설치된 정보를 저장할 변수
	srand((unsigned)time(NULL));		// 현재 시간을 기준으로 난수를 설정.

	createMineTable(mine_table, check_table, flag_table);		// 폭탄 설치 정보를 구성한다.


	// 몬스터 출력
	/*gotoxy(51, 10);
	printf(" QQQQQ  RRRRRR  \n");
	gotoxy(51, 11);
	printf("QQ   QQ RR   RR \n");
	gotoxy(51, 12);
	printf("QQ   QQ RRRRRR  \n");
	gotoxy(51, 13);
	printf("QQ  QQ  RR  RR  \n");
	gotoxy(51, 14);
	printf(" QQQQ Q RR   RR \n");*/

	// 이동키 설명
	gotoxy(20, 8);
	printf("왼쪽:   ←");
	gotoxy(20, 10);
	printf("오른쪽: →");
	gotoxy(20, 12);
	printf("위:     ↑");
	gotoxy(20, 14);
	printf("아래:   ↓");

	// 기능키 설명
	gotoxy(85, 10);
	printf("깃발: F");
	gotoxy(85, 12);
	printf("열기: Space bar");

	// 지뢰보드 외곽네모상자 그리기
	gotoxy(49, 18);
	printf("┌─────────────────┐");
	gotoxy(49, 19);
	printf("│                 │");
	gotoxy(49, 20);
	printf("│                 │");
	gotoxy(49, 21);
	printf("│                 │");
	gotoxy(49, 22);
	printf("│                 │");
	gotoxy(49, 23);
	printf("│                 │");
	gotoxy(49, 24);
	printf("│                 │");
	gotoxy(49, 25);
	printf("│                 │");
	gotoxy(49, 26);
	printf("│                 │");
	gotoxy(49, 27);
	printf("└─────────────────┘");


	gotoxy(47, 0);
	printf("│ time left:          │");
	gotoxy(47, 1);
	printf("└─────────────────────┘");



	_setmode(_fileno(stdout), _O_U16TEXT); // 출력 스트림의 인코딩 방식을 UTF-16LE로 변경
	ColorSet(0, 9);
	gotoxy(80, 20);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤\n");
	gotoxy(80, 21);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠛⠛⠛⠛⣿⣿\n");
	gotoxy(80, 22);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⠀⠀⠀⠀⣿⣿\n");
	gotoxy(80, 23);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⣠⣄⠀⠀⠀⢀⣿⣿\n");
	gotoxy(80, 24);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋\n");
	gotoxy(80, 25);
	wprintf(L"⠀⠀⠀⢀⣄⠀⣠⣾⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀\n");
	gotoxy(80, 26);
	wprintf(L"⠀⠀⠀⠻⣿⣿⣿⠟⠁⠀⣠⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀⠀⠀\n");
	gotoxy(80, 27);
	wprintf(L"⠀⠀⠀⠀⠈⣻⣿⣷⣤⣾⡿⠋⠀⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀\n");
	gotoxy(80, 28);
	wprintf(L"⠀⠀⠀⣠⣾⣿⠟⠻⣿⣿⣄⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀\n");
	gotoxy(80, 29);
	wprintf(L"⠀ ⣠⣾⣿⣿⣅⢀⣴⣿⡿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	gotoxy(80, 30);
	wprintf(L" ⣼⣿⠟⠉⢻⣿⣿⡿⠋⠀⠈⠻⣿⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	gotoxy(80, 31);
	wprintf(L" ⢻⣿⣦⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	gotoxy(80, 32);
	wprintf(L"⠀ ⠉⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

	ColorSet(0, 7);
	gotoxy(12, 18);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 19);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 20);
	wprintf(L"⠀⠀⠀⠀⠀⠀⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣤⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 21);
	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 22);
	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 23);
	wprintf(L"⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 24);
	wprintf(L"⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 25);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 26);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 27);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 28);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 29);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 30);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 31);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	gotoxy(12, 32);
	wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	_setmode(_fileno(stdout), _O_TEXT); // 출력 스트림의 인코딩 방식을 기본으로 변경


	// 지뢰 보드 출력
	showCurrentState(mine_table, check_table);

	setCursorView(true);	// 커서 보이게 설정

	int x = 0;
	int y = 0;

	int xx = 53;	// 지뢰판 위치 옮김용 // 이 수치값과 showCurrentState 함수에 있는 xx, yy 값을 조정하면 지뢰판의 위치를 이동시킬 수 있음
	int yy = 20;

	int flag = 0;
	int count = 0;
	int m_col;
	int m_row;
	int ch = 0;

	gotoxy(xx + x, yy + y);
	while (true) {
		m_col = x / 2;
		m_row = y;
		int ch = _getch();
		if (ch == 112)  // P 를 눌렀을 경우 게임 종료
		{
			gotoxy(0, 35);
			break;
		}
		if (ch == 32)	// 스페이스 키를 칠 경우 칸을 연다
		{
			if (mine_table[m_row][m_col] == '*')	// 폭탄일 경우
			{
				printf(" *");
				gotoxy(0, 35);
				printf("라운드 종료");
				Sleep(2000);
				break;
			}
			else		// 폭탄이 아닐 경우
			{
				//if (mine_table[y][m_col] == '^')		// 깃발을 눌렀을 경우 아무일도 일어나지 않음
				//{
				//	continue; 
				//}
				
				//int col = (x / 2);

				if (mine_table[m_row][m_col] == '0') printf("  ");
				else printf(" %c", mine_table[m_row][m_col]);
				check_table[m_row][m_col]++;	// 확인한 곳으로 체크

				gotoxy(xx + x, yy + y);

			}
		}
		if (ch == 70 || ch == 102)	// 사용자가 F 키를 누를 경우 깃발 꽃기
		{
			
			

			if (flag_table[m_row][m_col] == '^')	// 이미 깃발 표시를 한 곳일 경우
			{
				flag_table[m_row][m_col] = '0';
				check_table[m_row][m_col] = 0;	// 확인 하지 않은곳으로 표시
				flag -= 1;		// 맵 내의 전체 깃발 수 감소

				printf("■");
				gotoxy(xx + x, yy + y);

				continue;
			}

			if (mine_table[m_row][m_col] != '*')	// 폭탄이 아닐경우
			{
				if (check_table[m_row][m_col] >= 1)
				{
					continue;		// 숫자 칸에는 깃발 표시 안함
				}
				flag += 1;
				printf("◈");
				gotoxy(xx + x, yy + y);
				flag_table[m_row][m_col] = '^';
			}
			else if (mine_table[m_row][m_col] == '*')	// 폭탄일 경우
			{
				
				if (check_table[m_row][m_col] == 0)		// 했던 곳인지 확인
				{
					check_table[m_row][m_col]++;
					flag_table[m_row][m_col] = '^';
					flag += 1;
					printf("◈");
					gotoxy(xx + x, yy + y);

					if (flag == MINE_COUNT)		// 지뢰를 모두 깃발표시 하였을 경우
					{
						gotoxy(0, 9);
						printf("지뢰를 모두 찾았습니다!\n");

						

						Sleep(2000);
						break;
					}
				}
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
					if ((m_col - 1) >= 0)	// 범위 나가지 않게
						x -= 2;
					break;
				}
				case 77: {	// 오른쪽으로 이동
					if ((m_col + 1) < X_COUNT)	// 범위 나가지 않게
						x += 2;
					break;
				}
			}
			gotoxy(xx + x, yy + y);
		}
		
	}

	//showMineTable(mine_table);			// 전체 설치 정보를 확인한다.

	return flag; // 임시. 이 함수 완성하면서 삭제하기
}

void createMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT], char flag_table[][X_COUNT])
{
	int x, y, mine_count;
	// mine 정보를 저장할 메모리에 모두 0을 채운다.
	memset(mine_table, 0, Y_COUNT * X_COUNT);
	// 사용자의 선택 정보를 저장할 메모리에 모두 0을 채운다.
	memset(check_table, 0, Y_COUNT * X_COUNT);
	// flag 정보를 저장할 메모리에 모두 0을 채운다.
	memset(flag_table, 0, Y_COUNT * X_COUNT);

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
	//system("cls");	// 화면 한번 지우기 // 임 ******** 시
	printf("\n");
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
	int xx = 53;
	int yy = 20;
	int size = 6;

	for (int i = 0; i < size; i++)
	{
		gotoxy(xx, yy);
		for (int j = 0; j < size; j++)
		{
			printf("■");
		}
		yy = yy + 1;
	}

	//for (int y = 0; y < Y_COUNT; y++) {
	//	// 한 줄의 정보를 출력한다.
	//	for (int x = 0; x <= X_COUNT; x++) {
	//		if (check_table[y][x])
	//		{
	//			gotoxy(x, y);
	//			printf("% 2c", mine_table[y][x]);
	//		}
	//		else
	//		{
	//			gotoxy(x, y);
	//			printf("■");
	//		}
	//			
	//	}
	//	printf("\n"); // 줄바꿈
	//}
	//printf("\n");	// 줄바꿈



}