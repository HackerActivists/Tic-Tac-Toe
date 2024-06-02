#include "game.h"

int main()
{

    int choose = 1;
    Display_Menu();
    printf("Your choose is:");
    scanf("%d",&choose);

    do
    {
        switch(choose)
        {
            case 1:
                Run_Game();   scanf("%d",&choose);  break;
            default:
                printf("Your choose is error , please afresh choose!!!\n");
                printf("Your choose is:");
                scanf("%d",&choose);        break;
        }    
    } while (choose);

    printf("----------------Games Over----------------\n");

    system("pause");
    return 0;
}