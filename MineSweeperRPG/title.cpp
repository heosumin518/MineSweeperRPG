#include "title.h"


void titleDraw()
{
	int x = 10;
	int y = 7;
	gotoxy(x, y + 0);  printf("##     ## #### ##    ## ########  ######  ##      ## ######## ######## ########  ######## ########  ");
	gotoxy(x, y + 1);  printf("###   ###  ##  ###   ## ##       ##    ## ##  ##  ## ##       ##       ##     ## ##       ##     ## ");
	gotoxy(x, y + 2);  printf("#### ####  ##  ####  ## ##       ##       ##  ##  ## ##       ##       ##     ## ##       ##     ## ");
	gotoxy(x, y + 3);  printf("## ### ##  ##  ## ## ## ######    ######  ##  ##  ## ######   ######   ########  ######   ########  ");
	gotoxy(x, y + 4);  printf("##     ##  ##  ##  #### ##             ## ##  ##  ## ##       ##       ##        ##       ##   ##   ");
	gotoxy(x, y + 5);  printf("##     ##  ##  ##   ### ##       ##    ## ##  ##  ## ##       ##       ##        ##       ##    ##  ");
	gotoxy(x, y + 6);  printf("##     ## #### ##    ## ########  ######   ###  ###  ######## ######## ##        ######## ##     ## ");
	gotoxy(x, y + 8);  printf("                                    ########  ########   ######                                     ");
	gotoxy(x, y + 9);  printf("                                    ##     ## ##     ## ##    ##                                    ");
	gotoxy(x, y + 10); printf("                                    ##     ## ##     ## ##                                          ");
	gotoxy(x, y + 11); printf("                                    ########  ########  ##   ####                                   ");
	gotoxy(x, y + 12); printf("                                    ##   ##   ##        ##    ##                                    ");
	gotoxy(x, y + 13); printf("                                    ##    ##  ##        ##    ##                                    ");
	gotoxy(x, y + 14); printf("                                    ##     ## ##         ######                                     ");
}


int menuDraw()
{
	int x = 55;
	int y = 28;
	gotoxy(x - 3, y);
	printf("�� GAME START");
	gotoxy(x, y + 1);
	printf("HOW TO PLAY");
	gotoxy(x, y + 2);
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