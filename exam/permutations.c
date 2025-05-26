#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

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
            swap((s + l), (s + i)); // Backtrack
            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;

    int n = ft_strlen(av[1]);
    prmt(av[1], 0, n - 1);
    return 0;
}
