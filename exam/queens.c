#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sol(int *board, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%d", board[i]);
        if (i != size - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

int is_safe(int *board ,int index, int row ) 
{
    // while i < index
    int i = 0;
    while (i < index)
    {
        // check board[i] -+ i == row -+ index  
        if (board[i] == row || board[i] - i == row - index || board[i] + i == row + index)
            return (0);
        i++;
    }
    return (1);
}
void back_tracking( int *board,int index, int size)
{
    // index +++ = size
    if (index == size)
    {
        // print board 
        sol(board, size);
        return;
    }
    // i = 0
    int i = 0;
    // while
    while (i < size)
    {
        // check place 
        if (is_safe( board,index, i))
        {
            // board,index, i
            board[index] = i;
            // backstrack
            back_tracking( board,index + 1, size);
        }
        i++;
    }
}
int main(int ac, char **av)
{
    int *board;
    int n;

    // protect
    if (ac != 2)
        return (1);
    // char => int
    n = atoi(av[1]);

    // protect av[1]
    if (n < 0)
        return (1);

    // malloc
    board = malloc(sizeof(int) * n);
    if (!board)
        return (0);
    
    // start 
    back_tracking( board,0, n);

    // free
    free(board);

    return 0;
}


// void print(char *board , int size)
// {
//     int i = 0;
//     while (i < size)
//     {
//         printf("%d",board[i]);
//         if(i < size - 1)
//         printf(" ");
//         i++;
//     }
    
//     printf("\n");
// }


// int is_safe(char *board,int index , int row)
// {
//     int i = 0;
//     while (i < index)
//     {
//         if(board[i] == row ||board[i] - i == row - index || board[i] + i == row + index)
//             return 0;
//         i++;
//     }
//     return 1;
    
// }

// void qn(char *board ,int index,int size)
// {
//     if(index == size)
//     {
//         print(board,size);
//         return;
//     }
//     int i = 0 ;
//     while (i < size)
//     {
//         if(is_safe(board,index,i))
//         {
//             board[index] = i ;
//             qn(board,index + 1, size);
//         }
//         i++;
//     }
    
// }

// int main(int ac , char **av)
// {
//     if(ac <= 1)
//     return 1;

//     int n = atoi(av[1]);

//     if(n < 0)
//         return 1;
//     char *board = malloc(sizeof(int) * n);
//     if(!board)
//         NULL;
//     qn(board,0,n);
//     return 0;
// }