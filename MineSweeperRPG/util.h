#pragma once
#include "main.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void init();		// �ܼ� ȭ�� ũ�� ����
void gotoxy(int, int);	// ���콺 Ŀ���� �̵�
void setCursorView(bool);	// Ŀ�� �Ѱ� ����
void ColorSet(int backColor, int textColor);	// �ؽ�Ʈ ���� ����