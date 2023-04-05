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
		if		(menuCode == 0) {
			mineSweeper();	// ���ӽ���
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
