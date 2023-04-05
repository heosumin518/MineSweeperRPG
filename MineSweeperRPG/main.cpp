#include "main.h"
#include "title.h"
#include "util.h"
#include "gameManager.h"


int main()
{
	init();
	while (true)
	{
		titleDraw();
		descOneDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 게임시작
		}
		else if (menuCode == 1) {
			// 게임정보
		}
		else if (menuCode == 2) {
			return 0;	// 종료
		}
		system("cls");		// 콘솔창의 모든 글자 클리어. 콘솔 좌표 0, 0 으로 초기화
	}

}
