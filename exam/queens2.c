#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_safe(int index, int row, int *board)
{
    int i = 0;
    while (i < index)
    {
        if (board[i] == row || board[i] - i == row - index || board[i] + i == row + index)
            return (0);
        i++;
    }
    return 1;
}

void sol(int *board, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d", board[i]);
         if (i != size - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

void back_tracking(int index, int *board, int size)
{
    if (index == size)
    {
        sol(board, size);
        return;
    }

        int row = 0;
        while (row < size)
        {
            if (is_safe(index, row, board))
            {
                board[index] = row;
                back_tracking(index + 1, board, size);
            }
            row++;
        }
}

int main(int ac, char **av)
{
    int *board;
    int n;

    if (ac != 2)
        return (1);
    n = atoi(av[1]);
    if (n < 0)
        return (1);
    board = malloc(sizeof(int) * n);
    if (!board)
        return (0);
    back_tracking(0, board, n);
    free(board);
}