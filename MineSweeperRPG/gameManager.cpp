#include "gameManager.h"


int keyControl()
{
	char temp = _getch();	// ���͸� �Է����� �ʾƵ� Ű�� ������ �ٷ� ��ȯ���ִ� �Է� �Լ�

	if (temp == 'w' || temp == 'W') {
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