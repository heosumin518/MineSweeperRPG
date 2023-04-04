#include <stdio.h>
#include <Windows.h>


/* 함수 선언 */
void init();
void descOneDraw();		// 게임시작 정보 출력
void titleDraw();		// 타이틀 출력
void menuDraw();		// 메인 메뉴 출력
void gotoxy(int, int);	//마우스 커서를 이동

int main()
{
	titleDraw();
	menuDraw();
	descOneDraw();
	system("pause");
}

/* 함수 구현 */
void init()
{
	system("mode con cols=120 lines=40 | title minesweeper_rpg");		// 콘솔창 크기 초기화
}


void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void titleDraw()	// 타이틀 제목 출력
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

void menuDraw()
{
	gotoxy(35 - 2, 30);
	printf("> 게임시작");
	gotoxy(35, 31);
	printf("게임정보");
	gotoxy(35, 32);
	printf("  종료  ");
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