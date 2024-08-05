#include "game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
 int i=0;
 int j=0;
 for(i=0;i<row;i++)
 {
    for(j=0;j<col;j++)
    board[i][j]=' ';
 }
}
void Displayboard(char board[ROW][COL], int row, int col)
{
    int i=0;
    for(i=0;i<row;i++)
    {
        int j=0;
        for(j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
            printf("|");
        }
        printf("\n");
        if(i<row-1)
        {
            int j=0;
            for(j=0;j<col;j++)
            {
                printf("---");
                if(j<col-1)
                printf("|");
            }
            printf("\n");
        }
    }
}
void Playermove(char board[ROW][COL], int row, int col)
{
    int x,y;
    printf("玩家下棋>>>\n");
    printf("请输入坐标>>>\n");
    scanf("%d%d",&x,&y);
    if((x>=1&&x<=row)&&(x>=1&&x<=col))
    {
        if(board[x-1][y-1]==' ')
        {
            board[x-1][y-1]='*';
        }
        else
        {
            printf("坐标被占用,请输入其它位置>>>\n");
        }
    }
    else
    {
        printf("坐标非法,请重新输入>>>\n");
    }
}
void Computermove(char board[ROW][COL], int row, int col)
{
    printf("电脑下棋>>>\n");
    int x,y;
    while(1)
    {
        x=rand()%row;
        y=rand()%col;
        if(board[x][y]==' ')
        {
            board[x][y]='#';
            break;
        }
    }

}
int Isfull(char board[ROW][COL], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
        if(board[i][j]==' ')
        {
            return 0;
        }
    }
    }
    return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
    int i;
    for(i=0;i<row;i++)
    {
            if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
            return board[i][0];
    }
    int j;
    for(j=0;j<col;j++)
    {
            if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[1][j]!=' ')
            return board[0][j];
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    if(Isfull(board,row,col))
    {
      return 'Q';
    }
    return 'c';
}



