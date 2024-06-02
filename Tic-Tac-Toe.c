#include "game.h"


char board[ROW][COL] = {'\0'};

//显示菜单
void Display_Menu()
{
    printf("******************************\n");
    printf("********  1.player  **********\n");
    printf("********  0.exit    **********\n");
    printf("******************************\n");
}
//初始化棋盘
void Init_Board()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < ROW; i++)
        for(j = 0; j < COL; j++)
            board[i][j] = ' ';
}
//显示棋盘
void Disp_Board()
{
    system("cls");      //清屏
    int i = 0;
    int j = 0;
    for(i = 0; i < ROW; i++)        //控制循环的行数
        {
            for(j = 0; j < COL; j++)    //控制循环的列数
                {
                    printf(" %c ",board[i][j]);
                    if(j < COL - 1)
                        printf("|");
                }
        printf("\n");   //换行
        for(j = 0; j < COL; j++)    //控制循环的列数
            {
                printf("---");
            if(j < COL - 1)
                printf("|");
            }
        printf("\n");    //换行
        }
}
//运行游戏
void Run_Game()
{
    char tag = ' '; //临时变量-->用来储存 判断输赢 返回的信息
    Init_Board();            //初始化棋盘
    while(1)
    {
        Disp_Board();             //显示棋盘
    printf("Player move:\n");    //提示信息
        Player_Move();          //玩家移动 
        tag = Is_Win();               //判断输赢
        if(tag != 'c')        //如果返回的不是 c 就说明已经得到了谁输谁赢的结果 就直接结束 
            break;
        Computer_Move();      //电脑移动
        tag = Is_Win();            //判断输赢
        if(tag != 'c')      //如果返回的不是 c 就说明已经得到了谁输谁赢的结果 就直接结束
            break;
    }
    Disp_Board();             //显示棋盘
    switch(tag)
    {
        case '#':   //玩家胜利
            printf("Congratulations,you have won!\n");  break;
        case '*':
            printf("Unfortunately,you lost !\n");       break;
        case 'q':
            printf("Draw !\n");
    }
        printf("Do you want to continue ?\n");
        printf("*********** 1.continue  0.break ***********\n");
        printf("Your choose is:");
}
//玩家移动
void Player_Move()
{
    int X = 0;
    int Y = 0;
    printf("Please input your coordinate -->");
    scanf("%d%d",&X,&Y);

    while(1)    //循环方便输入错误时重新输入
    {
    //当 该位置不为 ' ' 时只有两种情况 --> 1.坐标被占用 2.坐标超出范围
    //此时这两种情况都是不符合题意的可以放在一块写    
        if( board[X - 1][Y - 1] != ' ')
        {
            if(X < 0 || X > ROW || Y < 0 || Y > COL)     //坐标超出范围时
                printf("Your coordinate error!\n");    
            else
                printf("coordinate occupied!!!\n");   //剩下的这个只能是坐标被占用
        
        printf("Please afresh input -->");          //提示重新输入
        scanf("%d%d",&X,&Y);
        }
        else        //不满足以上情况就说明该坐标输入正确
            {
                board[X - 1][Y - 1] = '#';      //给该坐标赋值，循环结束
                break;
            }

    }
}
//电脑移动
void Computer_Move()
{
    srand((unsigned int)time(NULL));    //确保每次产生的时间起始点不一样

    while(1)    //已防随机产生的坐标错误
    {
        int X = rand() % ROW;   //0 -- ROW - 1
        int Y = rand() % COL;  //0 -- COL - 1
        if(board[X][Y] == ' ')
            {
                board[X][Y] = '*';
                break;
            }
    }
}
//判断输赢
char Is_Win()
{
    int i = 0;
    int j = 0;
    int flag = 0;        //判断 (行 or 列) 是否保持一致的标志
    char tag = ' ';    //临时变量-->用作储存(行 or 列)起始位置的信息
//判断 行 是否全部相等
    for(i = 0; i < ROW; i++)
        {
        if(board[i][0] != ' ')       //先判断该起始位置是否不为 ' ' 然后才进行判断 大大减少了资源浪费   
            {   
            flag = 1;
            tag = board[i][0];
            for(j = 1; j < COL; j++) //如果从 0 开始相当于起始位置和起始位置判断(多判断了一次)所以从1开始
                if(tag != board[i][j])    //当有一个不一样时就直接结束本轮循环
                    {flag = 0;break;}    
            }
        if(flag == 1)    //如果循环结束flang为1则该行始终保持一致
            return tag;    
        }
//判断 列 是否全部相等
    for(j = 0; j < COL; j++)
        {
        if(board[0][j] != ' ')       //先判断该起始位置是否不为 ' ' 然后才进行判断 大大减少了资源浪费   
            {   
            flag = 1;
            tag = board[0][j];
            for(i = 1; i < ROW; i++) //如果从 0 开始相当于起始位置和起始位置判断(多判断了一次)所以从1开始
                if(tag != board[i][j])    //当有一个不一样时就直接结束本轮循环
                    {flag = 0;break;}    
            }
        if(flag == 1)    //如果循环结束flang为1则该行始终保持一致
            return tag;    
        }
//判断 对角线 是否相等
    if(ROW == COL)      //首先判断它是否有对角线 如果行和列不相等就没有对角线这种情况了
        {
//对角线 1 ：
            if(board[0][0] != ' ')
            {   
                flag = 1;
                tag = board[0][0];
                for(i = 1; i < ROW; i++)    //因为此时 行和列 是一样的所以这里用 ROW 或 COL 都行
                    if(tag != board[i][i])
                        {flag = 0;break;}
            if(flag == 1)
                return tag;
            }
//对角线 2 ：
            if(board[0][COL -1] != ' ')
            {   
                flag = 1;
                tag = board[0][COL - 1];
                for(j = 1; j < COL; j++)    //因为此时 行和列 是一样的所以这里用 ROW 或 COL 都行
                    if(tag != board[j][COL - j - 1])
                        {flag = 0;break;}
            if(flag == 1)
                return tag;
            }
        }
//判断是否平局(棋盘占满)
    for(i = 0; i < ROW; i++)
    {
            for(j = 0; j < COL; j++)
            {
                if(board[i][j] == ' ')  //当有一个为 空格 时就直接返回 --> 继续
                    return 'c';
            }        
    }
        return 'q';      //这个判断是否平局是放在最后的 所以只有上述所有情况都不满足后才会走到这一步
                        //此时只有 平局 或 不是平局继续 两种情况     
}
