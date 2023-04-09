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

		_getch();

		flag = 0;
		flag += mineSweeper(monsterHP, playerHP, gameMode);

		round++;

		if (gameMode == 0)	// �÷��̾� ��
		{
			monsterHP -= flag;	// ��� ǥ���� �� ��ŭ ������ HP�� ��´�.
			if (monsterHP < 0)
				monsterHP = 0;	// ������ HP �� ����θ� ǥ���ϱ� ����
			gameMode = 1;
		}
		else if (gameMode == 1)	// ������ ��
		{
			playerHP -= (MINE_COUNT - flag);	// ��� ǥ���� �� ��ŭ ������ ������ ����Ѵ�.
			if (playerHP < 0) playerHP = 0;	// �÷��̾��� HP �� ����θ� ǥ���ϱ� ����
			gameMode = 0;
		}

		gotoxy(49, 30);
		printf("HP: %2d / 10", playerHP);	// �÷��̾� HP
		gotoxy(50, 5);
		printf("HP: %2d / 20", monsterHP);	// ���� HP

		gotoxy(0, 2);
		printf("���� ��: %2d\n", round);
		system("pause");
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