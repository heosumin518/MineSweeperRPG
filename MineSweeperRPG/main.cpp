#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// Ű���� ��
#define UP     0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// ���� (�����̽���


/* �Լ� ���� */
void init();		// �ܼ� ȭ�� ũ�� ����
int keyControl();
void descOneDraw();		// ���ӽ��� ���� ���
void titleDraw();		// Ÿ��Ʋ ���
int menuDraw();		// ���� �޴� ���
void gotoxy(int, int);	// ���콺 Ŀ���� �̵�

int main()
{
	titleDraw();
	descOneDraw();
	int menuCode = menuDraw();
	system("pause");
}

/* �Լ� ���� */

void init()
{
	system("mode con cols=120 lines=30 | title minesweeper_rpg");		// �ܼ�â ũ�� �ʱ�ȭ
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// �ܼ� �ڵ� ��������
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
		printf("���� �ҷ����⿡ �����߽��ϴ�. \n");
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
	printf("> ���ӽ���");
	gotoxy(x, y+1);
	printf("��������");
	gotoxy(x, y+2);
	printf("  ����  ");

	while (true)	// Ű���� �Է��� ������ �ް� ��ٸ��� �ϴ� �κ�
	{
		int n = keyControl();		// Ű���� �̺�Ʈ�� Ű������ �޾ƿ��� // Ű������ Ű�ڵ带 �ӽ÷� �����ϴ� ����
		switch (n) {
			case UP: {
				if (y > 30) {	// �޴� ���� ����� �ʱ�
					gotoxy(x - 2, y);	// ">"�� ��ĭ ������ ����ϱ� ���� x-2 �� ��
					printf(" ");		// ���� �ִ� ">"�� ����
					gotoxy(x - 2, --y);	// �� ��ġ�� �̵��Ͽ�
					printf(">");		// �ٽ� ">" �׸���
				}
				break;
			}
			case DOWN: {
				if (y < 32) {	// �޴� �Ʒ��� ����� �ʱ�
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 30;
				// y ���� ��ġ�� 30�����Ƿ� y-30�� �ϸ� 0, 1, 2 �� ���ڸ� �޾ƿ� �� �ִ�.
			}
		}
	}
}

int keyControl()
{
	char temp = _getch();	// ���͸� �Է����� �ʾƵ� Ű�� ������ �ٷ� ��ȯ���ִ� �Է� �Լ�

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
	else if (temp == ' ') {		// �����̽���(����)�� ���� ��ư
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