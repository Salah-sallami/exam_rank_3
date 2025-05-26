#include "stdlib.h"
#include "stdio.h"

void Fill_1_with_0(char **map, int x, int y, int col)
{
    int position_x = x;
    int position_y = y;
    while (++position_y < col) // ->
    {
        if (map[x][position_y] == '1')
            map[x][position_y] = '0';
    }

    position_y = y;
    while (--position_y >= 0) // <-
    {
        if (map[x][position_y] == '1')
            map[x][position_y] = '0';
    }

    while (++position_x < col) // v
    {
        if (map[position_x][y] == '1' )
            map[position_x][y] = '0';
    }

    position_x = x;
    while (--position_x >= 0) // ^
    {
        if (map[position_x][y] == '1')
            map[position_x][y] = '0';
    }

    position_x = x;
    position_y = y;

    while (++position_y < col && ++position_x < col) // -> v
    {
        if (map[position_x][position_y] == '1')
            map[position_x][position_y] = '0';
    }

    position_x = x;
    position_y = y;

    while (--position_y >= 0 && --position_x >= 0) // <- ^
    {
        if (map[position_x][position_y] == '1')
            map[position_x][position_y] = '0';
    }

    position_x = x;
    position_y = y;

    while (++position_y < col && --position_x >= 0) //  ^ ->
    {
        if (map[position_x][position_y] == '1')
            map[position_x][position_y] = '0';
    }

    position_x = x;
    position_y = y;

    while (--position_y >= 0 && ++position_x < col) // <- v
    {
        if (map[position_x][position_y] == '1')
            map[position_x][position_y] = '0';
    }
}

void Fill_0_with_1(char **map, int x, int y, int col)
{
    int position_x = x;
    int position_y = y;
    while (++position_y < col) // ->
    {
        if (map[x][position_y] == '1' || map[x][position_y] == '3')
            map[x][position_y] = '3';
        else
            map[x][position_y] = '1';
    }

    position_y = y;
    while (--position_y >= 0) // <-
    {
        if (map[x][position_y] == '1' || map[x][position_y] == '3')
            map[x][position_y] = '3';
        else
            map[x][position_y] = '1';
    }

    while (++position_x < col) // v
    {
        if (map[position_x][y] == '1' || map[position_x][y] == '3')
            map[position_x][y] = '3';
        else
            map[position_x][y] = '1';
    }

    position_x = x;
    while (--position_x >= 0) // ^
    {
        if (map[position_x][y] == '1' || map[position_x][y] == '3')
            map[position_x][y] = '3';
        else
            map[position_x][y] = '1';
    }

    position_x = x;
    position_y = y;

    while (++position_y < col && ++position_x < col) // -> v
    {
        if (map[position_x][position_y] == '1' || map[position_x][position_y] == '3')
            map[position_x][position_y] = '3';
        else
            map[position_x][position_y] = '1';
    }

    position_x = x;
    position_y = y;

    while (--position_y >= 0 && --position_x >= 0) // <- ^
    {
        if (map[position_x][position_y] == '1' || map[position_x][position_y] == '3')
            map[position_x][position_y] = '3';
        else
            map[position_x][position_y] = '1';
    }

    position_x = x;
    position_y = y;

    while (++position_y < col && --position_x >= 0) //  ^ ->
    {
        if (map[position_x][position_y] == '1' || map[position_x][position_y] == '3')
            map[position_x][position_y] = '3';
        else
            map[position_x][position_y] = '1';
    }

    position_x = x;
    position_y = y;

    while (--position_y >= 0 && ++position_x < col) // <- v
    {
        if (map[position_x][position_y] == '1' || map[position_x][position_y] == '3')
            map[position_x][position_y] = '3';
        else
            map[position_x][position_y] = '1';
    }
}

void back_player(char **map, int col, int next_row)
{
        int i = 0;
        while (i < col && map[next_row - 1][i] != '2')
            i++;
        if (i == col)
            return;
        map[next_row - 1][i] = '0';
        Fill_1_with_0(map, next_row - 1, i, col);

        while (map[next_row - 1][i] != '1' && i == col)
            i++;
        if (map[next_row - 1][i] == '1')
        {
            map[next_row - 1][i] = '2';
            Fill_0_with_1(map, next_row - 1 , i, col);
        }
        else
            back_player(map,col, next_row);

}
void Move_from_the_beginning(char **map, int col, int next_row)
{
    int player = col;
    int i = 0;
    while (i < col)
    {
        if (map[next_row][i] == '0' && map[next_row][i] != '1')
        {
            map[next_row][i] = '2';
            Fill_0_with_1(map, next_row, i, col);
            break;
        }
        i++;
    }
    if( i == col)
        back_player(map,col, next_row);
}

void next_row(char **map, int row)
{
    int i = 0;
    int col = row;
    while (i < row)
    {
        Move_from_the_beginning(map, col, i);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    int col = atoi(av[1]);
    int row = atoi(av[1]);
    char **map = (char **)malloc(sizeof(char *) * (row + 1));
    if (!map)
        return 1;
    int i = 0;
    int j = 0;
    while (col > i)
    {
        map[i] = malloc(sizeof(char) * (row + 1));
        if (!map[i])
            return 1;
        map[i][row + 1] = '\0';
        j = 0;
        while (row > j)
        {
            map[i][j] = '0';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    next_row(map, row);

    i = 0;
    while (i < row)
    {
        printf("%s\n", map[i]);
        free(map[i]);
        i++;
    }
    free(map);
}