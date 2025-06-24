#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

char *ft_strdup(char *str)
{
    char *p = malloc(sizeof(char) * (strlen(str) + 1));
    if (!p)
        return NULL;
    int i = 0;
    while (str[i] != '\0')
    {
        p[i] = str[i];
        i++;
    }
    p[i] = '\0';

    return p;
}

char *ft_get_next_line(int fd)
{
    //
    static char buffer[BUFFER_SIZE];
    static int b_pos;
    static int b_read;
    //
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    //
    int i = 0;
    char line[70000];
    while (1)
    {

        //
        if (b_pos >= b_read)
        {
            //
            b_read = read(fd, buffer, BUFFER_SIZE);
            //
            b_pos = 0;
            //
            if (b_read <= 0)
                return NULL;
        }
        //
        line[i++] = buffer[b_pos++];
        //
        if (buffer[b_pos - 1] == '\n')
            break;
    }
    line[i] = '\0';
    //
    if (i == 0)
        return NULL;
    //
    return (ft_strdup(line));
}
void print(char *av)
{
    int i = 0;
    while (av[i])
    {
        write(1, "*", 1);
        i++;
    }
}
void ft_printf(char *str, char *av)
{
    int i = 0;
    int j = 0;

    while (str[i])
    {
        //
        j = 0;
        //
        if (str[i] == av[j])
        {
            while (str[i] == av[j])
            {
                i++;
                j++;
            }
            if (av[j] == '\0')
                print(av);
            else
            {
                //
                i = i - j;
                write(1, &str[i], 1);
                i++;
            }
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    //
    if (ac <= 1)
        return 1;
    //
    char *line = ft_get_next_line(0);
    //
    while (line)
    {

        //
        ft_printf(line, av[1]);
        //
        free(line);
        //
        line = ft_get_next_line(0);
    }
    //
    free(line);
    //
    return 0;
}