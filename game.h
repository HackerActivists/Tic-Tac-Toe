#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define  ROW    3
#define  COL    3

//棋盘
extern char board[ROW][COL];

//显示菜单
void Display_Menu(void);
//初始化棋盘
void Init_Board(void);
//显示棋盘
void Disp_Board(void);
//运行游戏
void Run_Game(void);
//玩家移动
void Player_Move(void);
//电脑移动
void Computer_Move(void);
//判断输赢
char Is_Win(void);