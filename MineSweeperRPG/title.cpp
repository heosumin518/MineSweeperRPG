#include "title.h"


void titleDraw()
{
	int x = 8;
	int y = 5;
	setCursorView(false);

	gotoxy(x, y + 0);  printf("              d8b                                                                                      ");
	gotoxy(x, y + 1);  printf("              Y8P                                                                                      ");
	gotoxy(x, y + 3);  printf("88888b.d88b.  888 88888b.   .d88b.  .d8888b  888  888  888  .d88b.   .d88b.  88888b.   .d88b.  888d888 ");
	gotoxy(x, y + 4);  printf("888 \"888 \"88b 888 888 \"88b d8P  Y8b 88K      888  888  888 d8P  Y8b d8P  Y8b 888 \"88b d8P  Y8b 888P\"   ");
	gotoxy(x, y + 5);  printf("888  888  888 888 888  888 88888888 \"Y8888b. 888  888  888 88888888 88888888 888  888 88888888 888     ");
	gotoxy(x, y + 6);  printf("888  888  888 888 888  888 Y8b.          X88 Y88b 888 d88P Y8b.     Y8b.     888 d88P Y8b.     888     ");
	gotoxy(x, y + 7);  printf("888  888  888 888 888  888  \"Y8888   88888P'  \"Y8888888P\"   \"Y8888   \"Y8888  88888P\"   \"Y8888  888     ");
	gotoxy(x, y + 8);  printf("                                                                             888                       ");
	gotoxy(x, y + 9); printf("                                                                             888                       ");
	gotoxy(x, y + 10); printf("                                                                             888                       ");
	gotoxy(x, y + 11); printf("                                  8888888b.  8888888b.   .d8888b.                                      ");
	gotoxy(x, y + 12); printf("                                  888   Y88b 888   Y88b d88P  Y88b                                     ");
	gotoxy(x, y + 13); printf("                                  888    888 888    888 888    888                                     ");
	gotoxy(x, y + 14); printf("                                  888   d88P 888   d88P 888                                            ");
	gotoxy(x, y + 15); printf("                                  8888888P\"  8888888P\"  888  88888                                     ");
	gotoxy(x, y + 16); printf("                                  888 T88b   888        888    888                                     ");
	gotoxy(x, y + 17); printf("                                  888  T88b  888        Y88b  d88P                                     ");
	gotoxy(x, y + 18); printf("                                  888   T88b 888         \"Y8888P88                                     ");
}


int menuDraw()
{
	int x = 55;
	int y = 28;
	gotoxy(x - 3, y);
	printf("��");
	gotoxy(x + 1, y);
	printf("GAME START");
	gotoxy(x + 1, y + 1);
	printf("HOW TO PLAY");
	gotoxy(x + 1, y + 2);
	printf("EXIT");


	while (true)	// Ű���� �Է��� ������ �ް� ��ٸ��� �ϴ� �κ�
	{
		int n = keyControl();		// Ű���� �̺�Ʈ�� Ű������ �޾ƿ��� // Ű������ Ű�ڵ带 �ӽ÷� �����ϴ� ����
		switch (n) {
		case UP: {
			if (y > 28) {	// �޴� ���� ����� �ʱ�
				gotoxy(x - 3, y);	// ">"�� ��ĭ ������ ����ϱ� ���� x-2 �� ��
				printf("   ");		// ���� �ִ� ">"�� ����
				gotoxy(x - 3, --y);	// �� ��ġ�� �̵��Ͽ�
				printf("��");		// �ٽ� ">" �׸���
			}
			break;
		}
		case DOWN: {
			if (y < 30) {	// �޴� �Ʒ��� ����� �ʱ�
				gotoxy(x - 3, y);
				printf("   ");
				gotoxy(x - 3, ++y);
				printf("��");
			}
			break;
		}
		case SUBMIT: {
			return y - 28;
			// y ���� ��ġ�� 30�����Ƿ� y-30�� �ϸ� 0, 1, 2 �� ���ڸ� �޾ƿ� �� �ִ�.
		}
		}
	}
}


void howToPlay()
{
	int x = 5; int y = 5;
	
	system("cls");

	gotoxy(x + 29, y); printf("<<���� �÷��� ���>>");

	while (true)
	{
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}