#include <stdlib.h>
#include <stdio.h>

void prmt(char *s, int l, int r)
{

    if (l == r)
    {
        put(s);
    }
    else
    {
        int i = 0;
        while (i < r)
        {
            ft_swap((s + l), (s + i));
            prmt(s, l + 1, r);
            ft_swap((s + l), (s + i));
            i++;
        }
    }
}
int main()
{
    puts(getenv("HOME"));
}