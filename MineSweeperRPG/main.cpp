#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 키보드 값
#define UP     0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// 선택 (스페이스바


/* 함수 선언 */
void init();		// 콘솔 화면 크기 지정
int keyControl();
void descOneDraw();		// 게임시작 정보 출력
void titleDraw();		// 타이틀 출력
int menuDraw();		// 메인 메뉴 출력
void gotoxy(int, int);	// 마우스 커서를 이동

int main()
{
	titleDraw();
	descOneDraw();
	int menuCode = menuDraw();
	system("pause");
}

/* 함수 구현 */

void init()
{
	system("mode con cols=120 lines=30 | title minesweeper_rpg");		// 콘솔창 크기 초기화
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void titleDraw()
{
	char print_temp[256];
	FILE* rfp = NULL;
	fopen_s(&rfp, "title.txt", "rt");

	if (rfp == NULL)
	{
		printf("파일 불러오기에 실패했습니다. \n");
		return;
	}

	while (fgets(print_temp, 255, rfp) != NULL)
	{
		printf(print_temp);
	}
	puts("");

}

int menuDraw()
{
	int x = 35;
	int y = 30;
	gotoxy(x - 2, y);
	printf("> 게임시작");
	gotoxy(x, y+1);
	printf("게임정보");
	gotoxy(x, y+2);
	printf("  종료  ");

	while (true)	// 키보드 입력을 무한정 받고 기다리고 하는 부분
	{
		int n = keyControl();		// 키보드 이벤트를 키값으로 받아오기 // 키보드의 키코드를 임시로 저장하는 변수
		switch (n) {
			case UP: {
				if (y > 30) {	// 메뉴 위로 벗어나지 않기
					gotoxy(x - 2, y);	// ">"를 두칸 이전에 출력하기 위해 x-2 를 함
					printf(" ");		// 원래 있던 ">"를 지움
					gotoxy(x - 2, --y);	// 새 위치로 이동하여
					printf(">");		// 다시 ">" 그리기
				}
				break;
			}
			case DOWN: {
				if (y < 32) {	// 메뉴 아래로 벗어나지 않기
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 30;
				// y 시작 위치가 30였으므로 y-30를 하면 0, 1, 2 세 숫자를 받아올 수 있다.
			}
		}
	}
}

int keyControl()
{
	char temp = _getch();	// 엔터를 입력하지 않아도 키가 눌리면 바로 변환해주는 입력 함수

	if		(temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {		// 스페이스바(공백)이 선택 버튼
		return SUBMIT;
	}
}

void descOneDraw()
{
	char print_temp[256];
	FILE* rfp = NULL;
	fopen_s(&rfp, "desc1.txt", "rt");

	if (rfp == NULL)
	{
		printf("파일 불러오기에 실패했습니다. \n");
		return;
	}

	for (int i = 0; fgets(print_temp, 255, rfp) != NULL; i++)
	{
		gotoxy(81, i);
		printf(print_temp);
	}
	puts("");
}