#pragma once
#include "main.h"
#include "util.h"
#include <stdlib.h>		// srand, rand �Լ� ���
#include <time.h>
#include <memory.h>		// memset �Լ� ���

#ifndef COUNT
#define COUNT

#define MINE_COUNT 5	// �ʱ� 10, �߱� 40, ��� 99
#define X_COUNT    6	// �ʱ�  9, �߱� 16, ��� 30
#define Y_COUNT    6	// �ʱ�  9, �߱� 16, ��� 16

#endif

int mineSweeper();
void createMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT], char flag_table[][X_COUNT]);		// ����ã��� ����
void showMineTable(char mine_table[][X_COUNT]);			/*** draw.cpp ���� �ű�� ����� ***/
void showCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT]);