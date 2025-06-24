#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void    sort(char *str)
{
    int    i = 0;
    int    j = 0;
    char    c;
    while (i < strlen(str))
    {
        j = i + 1;
        while (j < strlen(str))
        {
            if (str[i] > str[j])
            {
                c = str[i];
                str[i] = str[j];
                str[j] = c;
            }
            j++;
        }
        i++;
    }
}

void    permutation(char *arr, char *used, char *str, int index, int n)
{
    if (index == n)
    {
        arr[index] = '\0';
        write(1, arr, strlen(arr));
        write(1, "\n", 1);
        return ;
    }
    int    r = 0;
    while (r < n)
    {
        if (used[r] == 0)
        {
            used[r] = 1;
            arr[index] = str[r];
            permutation(arr, used, str, index + 1, n);
            used[r] = 0;
        }
        r++;
    }
}

int    main(int ac, char **av)
{
    if (ac != 2) return (1);
    char    *str =  strdup(av[1]);
    sort(str);
    char    *used = calloc(strlen(str), 1);
    char    *arr = malloc(strlen(str) + 1);
    permutation(arr, used, str, 0, strlen(str));
}
