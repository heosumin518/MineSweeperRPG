#include <stdio.h>
#include <Windows.h>


/* �Լ� ���� */
void init();
void descOneDraw();		// ���ӽ��� ���� ���
void titleDraw();		// Ÿ��Ʋ ���
void menuDraw();		// ���� �޴� ���
void gotoxy(int, int);	//���콺 Ŀ���� �̵�

int main()
{
	titleDraw();
	menuDraw();
	descOneDraw();
	system("pause");
}

/* �Լ� ���� */
void init()
{
	system("mode con cols=120 lines=40 | title minesweeper_rpg");		// �ܼ�â ũ�� �ʱ�ȭ
}


void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void titleDraw()	// Ÿ��Ʋ ���� ���
{
	char print_temp[256];
	FILE* rfp = NULL;
	fopen_s(&rfp, "title.txt", "rt");

	if (rfp == NULL)
	{
		printf("���� �ҷ����⿡ �����߽��ϴ�. \n");
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
	printf("> ���ӽ���");
	gotoxy(35, 31);
	printf("��������");
	gotoxy(35, 32);
	printf("  ����  ");
}

void descOneDraw()
{
	char print_temp[256];
	FILE* rfp = NULL;
	fopen_s(&rfp, "desc1.txt", "rt");

	if (rfp == NULL)
	{
		printf("���� �ҷ����⿡ �����߽��ϴ�. \n");
		return;
	}

	for (int i = 0; fgets(print_temp, 255, rfp) != NULL; i++)
	{
		gotoxy(81, i);
		printf(print_temp);
	}
	puts("");
}