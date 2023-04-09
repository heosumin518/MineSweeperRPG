#include "gameManager.h"


bool gamePlay()		// �¸� ���� ��ȯ�ϱ�
{
	int gameMode = 0;	// 0�� �÷��̾� 1�� ������ ��
	bool gameOver = false;		// ���� ���� ����
	int monsterHP = 20;
	int playerHP = 10;
	int flag = 0;
	int round = 0;	// ���� ��
	bool isWin = false;

	system("cls");
	Sleep(1000);
	PlaySound(TEXT("gameStart.wav"), NULL, SND_ASYNC | SND_LOOP);	// Ÿ��Ʋ ����� ���

	Sleep(2000);

	while (true)		// ���⿡ ���� HP ������ �־?
	{

		gotoxy(49, 30);
		printf("HP: %2d / 10", playerHP);	// �÷��̾� HP
		gotoxy(50, 5);
		printf("HP: %2d / 20", monsterHP);	// ���� HP

		if (monsterHP <= 0)
		{
			isWin = true;
			break;	// ������  HP�� �� ������ ��������
		}
		if (playerHP <= 0)
		{
			isWin = false;
			break;  // �÷��̾��� HP�� 0�� �Ǹ� ��������
		}


		flag = 0;
		flag += mineSweeper(monsterHP, playerHP, gameMode);

		round++;

		if (gameMode == 0)	// �÷��̾� ��
		{
			
			Sleep(1000);
			while (_kbhit()) // ��������� �Է� ���۸� �ʱ�ȭ�Ѵ�.
				_getch();
			gotoxy(35, 34);
			printf("                                          ");
			gotoxy(50, 34);
			printf("���� ����!", flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                          ");
			gotoxy(43, 34);
			Sleep(500);
			printf("������ %2d ��ŭ�� ������!", flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                          ");

			monsterHP -= flag;	// ��� ǥ���� �� ��ŭ ������ HP�� ��´�.
			if (monsterHP < 0)
				monsterHP = 0;	// ������ HP �� ����θ� ǥ���ϱ� ����
			gameMode = 1;
		}
		else if (gameMode == 1)	// ������ ��
		{
			
			Sleep(1000);
			while (_kbhit()) // ��������� �Է� ���۸� �ʱ�ȭ�Ѵ�.
				_getch();
			gotoxy(35, 34);
			printf("                                         ");
			gotoxy(49, 34);
			printf("���� ����!", flag);
			Sleep(100);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                         ");
			gotoxy(40, 34);
			Sleep(500);
			printf("���� ����� %d �� �������� ����!", MINE_COUNT - flag);
			setCursorView(true);
			_getch();
			setCursorView(false);
			gotoxy(35, 34);
			printf("                                           ");

			playerHP -= (MINE_COUNT - flag);	// ��� ǥ���� �� ��ŭ ������ ������ ����Ѵ�.
			if (playerHP < 0) playerHP = 0;	// �÷��̾��� HP �� ����θ� ǥ���ϱ� ����
			gameMode = 0;
		}

		gotoxy(49, 30);
		printf("HP: %2d / 10", playerHP);	// �÷��̾� HP
		gotoxy(50, 5);
		printf("HP: %2d / 20", monsterHP);	// ���� HP



	}
	return isWin;
}



int keyControl()
{
	char temp = _getch();	// ���͸� �Է����� �ʾƵ� Ű�� ������ �ٷ� ��ȯ���ִ� �Է� �Լ�

	// ����Ű�� �̵�
	if (temp == 72) {
		return UP;
	}
	else if (temp == 75) {
		return LEFT;
	}
	else if (temp == 80) {
		return DOWN;
	}
	else if (temp == 77) {
		return RIGHT;
	}
	else if (temp == ' ') {		// �����̽���(����)�� ���� ��ư
		return SUBMIT;
	}
}