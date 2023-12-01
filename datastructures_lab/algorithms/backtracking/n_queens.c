#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int CanPlace(int chess[4][4],int row,int col)
{
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            if((chess[row][j] == 1)||(chess[i][col] == 1))
            { 
                return 0;
            }
            
            if((chess[abs(row - i)][abs(col - j)] == 1) && (abs(row - i) == abs(col - j)))
            {
                printf("diag %d, %d ,row = %d, col =%d\n",abs(row - i),abs(col - j),row,col);
                return 0;
            }
        }
    }
    return 1;
}

int  NQueens(int chess[4][4],int row)
{
    
    for(int col = 0;col<4;col++)
    {
        if(CanPlace(chess,row,col))
        {
            printf("placed i= %d, j = %d \n",row,col);
            chess[row][col] = 1;
            if(row < 4)
            {
                NQueens(chess,row+1);
              
            }
            else{
                chess[row][col] = 0;
            }
            
        }
        else{
            // printf("not placed i= %d, j = %d \n",row,col);
        }
        
    }
    return 0;
}

int main(void)
{
    int chess_board[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    NQueens(chess_board,0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",chess_board[i][j]);
        }
        printf("\n");
    }
    return 0;
}