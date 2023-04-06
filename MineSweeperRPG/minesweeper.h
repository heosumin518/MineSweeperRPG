#pragma once
#include "main.h"
#include "util.h"
#include <stdlib.h>		// srand, rand 함수 사용
#include <time.h>
#include <memory.h>		// memset 함수 사용

#ifndef COUNT
#define COUNT

#define MINE_COUNT 5	// 초급 10, 중급 40, 상급 99
#define X_COUNT    6	// 초급  9, 중급 16, 상급 30
#define Y_COUNT    6	// 초급  9, 중급 16, 상급 16

#endif

int mineSweeper();
void createMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT], char flag_table[][X_COUNT]);		// 지뢰찾기맵 생성
void showMineTable(char mine_table[][X_COUNT]);			/*** draw.cpp 만들어서 옮길까 고민중 ***/
void showCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT]);