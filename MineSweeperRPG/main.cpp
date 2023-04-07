#include "main.h"
#include "title.h"
#include "util.h"
#include "gameManager.h"
#include "minesweeper.h"


int main()
{
	init();
	while (true)
	{
		titleDraw();
		int menuCode = menuDraw();
		bool isWin = false;
		if		(menuCode == 0) {
			isWin = gamePlay();
			gotoxy(0, 35);
			printf("��������");
			if (isWin)
			{
				gotoxy(40, 35);
				printf("�÷��̾��� �¸�!");
			}
			else
			{
				gotoxy(40, 35);
				printf("�й�..!");
			}
			system("pause");	// ������. ���� �����ϱ�
		}
		else if (menuCode == 1) {
			howToPlay();	// ���� ���
		}
		else if (menuCode == 2) {
			return 0;		// ����
		}
		system("cls");		// �ܼ�â�� ��� ���� Ŭ����. �ܼ� ��ǥ 0, 0 ���� �ʱ�ȭ
	}

}
