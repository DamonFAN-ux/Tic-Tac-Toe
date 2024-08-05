#include"game.h"
void menu();
void game();
int main()
{
    int input;
    srand(time(NULL));
    do
    {
     menu();//打印菜单
     printf("请输入>>>");
     scanf("%d",&input);
     switch(input)
     {
     case 1:
     printf("三子棋游戏开始>>>\n");
     game();
     break;
     case 0:
     printf("游戏结束\n");
     break;
     default:
     printf("输入错误\n");
     break;
     }
    } while (input);

}
void menu()
{
    printf("**************************\n");
    printf("***** 1.PLAY  2.EXIT *****\n");
    printf("**************************\n");

}
void game()
{
    char ret;
    char board[ROW][COL]={0};
    Initboard(board,ROW,COL);
    Displayboard(board,ROW,COL);
    while(1)
    {
        Playermove(board,ROW,COL);
        ret= Iswin(board,ROW,COL);
        if(ret!='c')
        {
            break;
        }
        Displayboard(board,ROW,COL);
        Computermove(board,ROW,COL);
        ret= Iswin(board,ROW,COL);
        if(ret!='c')
        {
            break;
        }
        Displayboard(board,ROW,COL);
    }
    if (ret=='*')
    {
        printf("玩家赢了\n");
        Displayboard(board,ROW,COL);


    }
    else if(ret=='#')
    {
        printf("电脑赢了\n");
        Displayboard(board,ROW,COL);

    }
    else
    {
        printf("平局\n");
        Displayboard(board,ROW,COL);

    }
}