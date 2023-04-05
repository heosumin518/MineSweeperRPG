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
	printf("▶ 게임시작");
	gotoxy(x, y + 1);
	printf("게임방법");
	gotoxy(x, y + 2);
	printf("  종료  ");

	while (true)	// 키보드 입력을 무한정 받고 기다리고 하는 부분
	{
		int n = keyControl();		// 키보드 이벤트를 키값으로 받아오기 // 키보드의 키코드를 임시로 저장하는 변수
		switch (n) {
		case UP: {
			if (y > 25) {	// 메뉴 위로 벗어나지 않기
				gotoxy(x - 3, y);	// ">"를 두칸 이전에 출력하기 위해 x-2 를 함
				printf("   ");		// 원래 있던 ">"를 지움
				gotoxy(x - 3, --y);	// 새 위치로 이동하여
				printf("▶");		// 다시 ">" 그리기
			}
			break;
		}
		case DOWN: {
			if (y < 27) {	// 메뉴 아래로 벗어나지 않기
				gotoxy(x - 3, y);
				printf("   ");
				gotoxy(x - 3, ++y);
				printf("▶");
			}
			break;
		}
		case SUBMIT: {
			return y - 25;
			// y 시작 위치가 30였으므로 y-30를 하면 0, 1, 2 세 숫자를 받아올 수 있다.
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
		printf("파일 불러오기에 실패했습니다. \n");
		return;
	}

	for (int i = 0; fgets(print_temp, 255, rfp) != NULL; i++)
	{
		gotoxy(81, i);
		printf(print_temp);
	}
	puts("");
}