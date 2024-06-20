#include "game.h"

int main()
{
    int choose = 1;
    Display_Menu(); // 显示菜单
    printf("Your choose is:");
    scanf("%d", &choose);
    do
    {
        switch (choose)
        {
        case 0: // 退出
            printf("Exit succefssful!\n");
            break;
        case 1: // 游戏开始
            Run_Game();
            scanf("%d", &choose);
            break;
        default: // 输入错误，请重新输入
            printf("Your choose is error , please afresh choose!!!\n");
            printf("Your choose is:");
            scanf("%d", &choose);
            break;
        }
    } while (choose);

    printf("----------------Games Over----------------\n");

    system("pause");
    return 0;
}
