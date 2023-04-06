#include "minesweeper.h"


// ����ã�� 
int mineSweeper()
{
	system("cls");

	char mine_table[Y_COUNT][X_COUNT];	// ��ź�� ��ġ�� ������ ������ ����
	char check_table[Y_COUNT][X_COUNT]; // ����ڰ� ������ ��ġ�� ����� ����
	char flag_table[Y_COUNT][X_COUNT];	// ����� ��ġ�� ������ ������ ����
	srand((unsigned)time(NULL));		// ���� �ð��� �������� ������ ����.

	createMineTable(mine_table, check_table, flag_table);		// ��ź ��ġ ������ �����Ѵ�.

	// ���� ������ �ݿ��Ͽ� ���� ������ ����Ѵ�.
	// @ ���ڷ� ��µ� ���� ���� Ȯ���� �ȵ� �׸��̴�.
	showCurrentState(mine_table, check_table);

	setCursorView(true);	// Ŀ�� ���̰� ����

	int x = 0;
	int y = 0;
	int flag = 0;
	int count = 0;
	int m_col;
	gotoxy(x, y);
	while (true) {
		m_col = (x / 2);
		int ch = _getch();
		if (ch == 112)  // P �� ������ ��� �÷��� ����
			break;
		if (ch == 32)	// �����̽� Ű�� ĥ ��� ĭ�� ����
		{
			if (mine_table[y][m_col] == '*')	// ��ź�� ���
			{
				printf("*");
				gotoxy(50, 50);
				printf("Ŭ���� ����");
				Sleep(2000);
				break;
			}
			else		// ��ź�� �ƴ� ���
			{
				//if (mine_table[y][m_col] == '^')		// ����� ������ ��� �ƹ��ϵ� �Ͼ�� ����
				//{
				//	continue; 
				//}
				int col = (x / 2);
				if (mine_table[y][m_col] == '0') printf("  ");
				else printf(" %c", mine_table[y][m_col]);
				check_table[y][m_col]++;
				gotoxy(x, y);
				// ���� �˻��ؼ� ���ڰ� ��� ���ٸ� �� ���� (�װ� ����)
			}
		}
		if (ch == 70 || ch == 102)	// ����ڰ� F Ű�� ���� ��� ��� �ɱ�
		{
			
			

			if (flag_table[y][m_col] == '^')	// �̹� ��� ǥ�ø� �� ���� ���
			{
				flag_table[y][m_col] = '0';
				check_table[y][m_col] = 0;	// Ȯ�� ���� ���������� ǥ��
				flag -= 1;		// �� ���� ��ü ��� �� ����

				printf("��");
				gotoxy(x, y);

				continue;
			}

			if (mine_table[y][m_col] != '*')	// ��ź�� �ƴҰ��
			{
				if (check_table[y][m_col] >= 1)
				{
					continue;		// ���� ĭ���� ��� ǥ�� ����
				}
				printf("��");
				gotoxy(x, y);
				flag_table[y][m_col] = '^';
			}
			else if (mine_table[y][m_col] == '*')	// ��ź�� ���
			{
				
				if (check_table[y][m_col] == 0)		// �ߴ� ������ Ȯ��
				{
					check_table[y][m_col]++;
					flag_table[y][m_col] = '^';
					flag += 1;
					printf("��");
					gotoxy(x, y);

					if (flag == MINE_COUNT)		// ���ڸ� ��� ���ǥ�� �Ͽ��� ���
					{
						gotoxy(0, 9);
						printf("���ڸ� ��� ã�ҽ��ϴ�!\n");
						Sleep(2000);
						break;
					}
				}
			}
			
		}

		if (ch == 224)	// ������ �̵�
		{
			ch = _getch();
			switch (ch)
			{
				case 72: {	// ���� �̵�
					if ((y - 1) >= 0)	// ���� ������ �ʰ�
						y -= 1;
					break;
				}
				case 80: {	// �Ʒ��� �̵�
					if ((y + 1) < Y_COUNT)	// ���� ������ �ʰ�
						y += 1;
					break;
				}
				case 75: {	// �������� �̵�
					if ((m_col-1) >= 0)	// ���� ������ �ʰ�
						x -= 2;
					break;
				}
				case 77: {	// ���������� �̵�
					if ((m_col+1) < X_COUNT)	// ���� ������ �ʰ�
						x += 2;
					break;
				}
			}
			gotoxy(x, y);
		}
		
	}

	showMineTable(mine_table);			// ��ü ��ġ ������ Ȯ���Ѵ�.

	return 0; // �ӽ�. �� �Լ� �ϼ��ϸ鼭 �����ϱ�
}

void createMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT], char flag_table[][X_COUNT])
{
	int x, y, mine_count;
	// mine ������ ������ �޸𸮿� ��� 0�� ä���.
	memset(mine_table, 0, Y_COUNT * X_COUNT);
	// ������� ���� ������ ������ �޸𸮿� ��� 0�� ä���.
	memset(check_table, 0, Y_COUNT * X_COUNT);
	// flag ������ ������ �޸𸮿� ��� 0�� ä���.
	memset(flag_table, 0, Y_COUNT * X_COUNT);

	// ��ź�� MINE_COUNT �� ��ŭ �����Ѵ�.
	for (mine_count = 0; mine_count < MINE_COUNT; mine_count++) {
		// ������ ����Ͽ� ��ź�� ��ġ�� ���� �����Ѵ�.
		x = rand() % X_COUNT;
		y = rand() % Y_COUNT;
		// ��ź�� ��ġ�� ���� �ƴ϶�� ��ź�� ��ġ�ϰ� �̹� ��ġ�� ���̶��
		// ��ź�� ���� �ٿ��� �ٽ� �õ��ϰ� �Ѵ�.
		if (mine_table[y][x] == 0) mine_table[y][x] = '*';
		else mine_count--;
	}

	for (y = 0; y < Y_COUNT; y++) {
		for (x = 0; x < X_COUNT; x++) {
			// ��ź�� �ƴ϶�� ������ ��ġ�� ��ź�� � �ִ��� üũ�Ѵ�.
			if (mine_table[y][x] == 0) {
				// ��ź�� ���� �ʱ�ȭ�Ѵ�.
				mine_count = 0;

				// ���� ��ġ (C)�� �߽����� �� 8������ ��ġ�� ��ź�� �� �� �ִ��� üũ�Ѵ�.
				// 1, 2, 3
				// 4, C, 5
				// 6, 7, 8

				if ((y - 1) >= 0) {		// ������ ������ �ʰ� üũ�Ѵ�.
					// 1, 2, 3�� �׸��� üũ�Ѵ�.
					if ((x - 1) >= 0 && mine_table[y - 1][x - 1] == '*') mine_count++;
					if (mine_table[y - 1][x] == '*') mine_count++;
					if ((x + 1) < X_COUNT && mine_table[y - 1][x + 1] == '*') mine_count++;
				}

				// 4, 5�� �׸��� üũ�Ѵ�.
				if ((x - 1) >= 0 && mine_table[y][x - 1] == '*') mine_count++;
				if ((x + 1) < X_COUNT && mine_table[y][x + 1] == '*') mine_count++;

				// 6, 7, 8 �׸��� üũ�Ѵ�.
				if ((y + 1) < Y_COUNT) {	// ������ ����� �ʰ� üũ�Ѵ�.
					if ((x - 1) >= 0 && mine_table[y + 1][x - 1] == '*') mine_count++;
					if (mine_table[y + 1][x] == '*') mine_count++;
					if ((x + 1) < X_COUNT && mine_table[y + 1][x + 1] == '*') mine_count++;
				}

				// ���� ��ź ���� �������� ���ڷ� �����ؼ� ���� ��ġ�� �����Ѵ�.
				// ���� ���, 5��� '5�� �����Ѵ�.
				mine_table[y][x] = '0' + mine_count;
			}
		}
	}
}

void showMineTable(char mine_table[][X_COUNT])		// ���� ����� ��ü ���ڸ� �����ִ� �Լ�
{
	system("cls");	// ȭ�� �ѹ� ����� // �� ******** ��
	for (int y = 0; y < Y_COUNT; y++) {
		// �� ���� ������ ����Ѵ�.
		printf(" ");
		for (int x = 0; x < X_COUNT; x++) printf("%c", mine_table[y][x]);
		printf("\n");	// �ٹٲ�
	}
	printf("\n");	// �ٹٲ�
}

void showCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT])		// ���� ���ڰ��Ӻ��� ���¸� �����ִ� �Լ�
{
	for (int y = 0; y < Y_COUNT; y++) {
		// �� ���� ������ ����Ѵ�.
		for (int x = 0; x < X_COUNT; x++) {
			if (check_table[y][x])
			{
				printf("% 2c", mine_table[y][x]);
			}
			else printf("��");
		}
		printf("\n"); // �ٹٲ�
	}
	printf("\n");	// �ٹٲ�
}