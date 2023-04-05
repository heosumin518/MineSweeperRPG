#include "title.h"


void titleDraw()
{
	int x = 5;
	int y = 7;
	gotoxy(x, y + 0);  printf("#    # # #    # ######  ####  #    # ###### ###### #####  ###### #####  ");
	gotoxy(x, y + 1);  printf("##  ## # ##   # #      #      #    # #      #      #    # #      #    # ");
	gotoxy(x, y + 2);  printf("# ## # # # #  # #####   ####  #    # #####  #####  #    # #####  #    # ");
	gotoxy(x, y + 3);  printf("#    # # #  # # #           # # ## # #      #      #####  #      #####  ");
	gotoxy(x, y + 4);  printf("#    # # #   ## #      #    # ##  ## #      #      #      #      #   #  ");
	gotoxy(x, y + 5);  printf("#    # # #    # ######  ####  #    # ###### ###### #      ###### #    # ");
	gotoxy(x, y + 7);  printf("                        ######  ######   #####                          ");
	gotoxy(x, y + 8);  printf("                        #     # #     # #     #                         ");
	gotoxy(x, y + 9);  printf("                        #     # #     # #                               ");
	gotoxy(x, y + 10); printf("                        ######  ######  #  ####                         ");
	gotoxy(x, y + 11); printf("                        #   #   #       #     #                         ");
	gotoxy(x, y + 12); printf("                        #    #  #       #     #                         ");
	gotoxy(x, y + 13); printf("                        #     # #        #####                          ");
}

int menuDraw()
{
	int x = 35;
	int y = 25;
	gotoxy(x - 3, y);
	printf("�� ���ӽ���");
	gotoxy(x, y + 1);
	printf("���ӹ��");
	gotoxy(x, y + 2);
	printf("  ����  ");

	while (true)	// Ű���� �Է��� ������ �ް� ��ٸ��� �ϴ� �κ�
	{
		int n = keyControl();		// Ű���� �̺�Ʈ�� Ű������ �޾ƿ��� // Ű������ Ű�ڵ带 �ӽ÷� �����ϴ� ����
		switch (n) {
		case UP: {
			if (y > 25) {	// �޴� ���� ����� �ʱ�
				gotoxy(x - 3, y);	// ">"�� ��ĭ ������ ����ϱ� ���� x-2 �� ��
				printf("   ");		// ���� �ִ� ">"�� ����
				gotoxy(x - 3, --y);	// �� ��ġ�� �̵��Ͽ�
				printf("��");		// �ٽ� ">" �׸���
			}
			break;
		}
		case DOWN: {
			if (y < 27) {	// �޴� �Ʒ��� ����� �ʱ�
				gotoxy(x - 3, y);
				printf("   ");
				gotoxy(x - 3, ++y);
				printf("��");
			}
			break;
		}
		case SUBMIT: {
			return y - 25;
			// y ���� ��ġ�� 30�����Ƿ� y-30�� �ϸ� 0, 1, 2 �� ���ڸ� �޾ƿ� �� �ִ�.
		}
		}
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