#include <stdio.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void prmt(char *s, int l, int r)
{
    if (l == r)
        puts(s);
    else
    {
        int i = l;
        while (i <= r)
        {
            swap((s + l), (s + i));
            prmt(s, l + 1, r);
            swap((s + l), (s + i)); 

            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;

    int n = strlen(av[1]);

    prmt(av[1], 0, n - 1);
    return 0;
}

