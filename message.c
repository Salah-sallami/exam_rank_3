
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// DIMA F YEDI KHATEM KAKUZU
char    *ft_strdup(const char *str)
{
    char    *copy;
    int        i;

    copy = malloc(strlen(str) + 1);
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    char           line[70000];
    static int     bytes_read;
    static int     pos;
    int            i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (pos >= bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if (bytes_read <= 0)
                return NULL;
        }
        line[i++] = buffer[pos++];
        if (buffer[pos - 1] == '\n')
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}


void    print_av(char *av)
{
    int i = 0;
    while (av[i])
    {
        write(1,"*",1);
        i++;
    }
    
}

void    ft_printf(char *str, char *av)
{
    int i = 0;
    int j = 0;
    // while str
    while(str[i])
    {
        // return j = 0
        j = 0;

        // 'c' == 'c'
        if(str[i] == av[j])
        {
            // while 'c'++ == 'c'++
            while (str[i] == av[j])
            {
                i++;
                j++;
            }
            

            // check last 'c' in av
            if(av[j] == '\0')
            {
                // print * == len av
                print_av(av);

            }else
            {
                // return position i 
                i = i - j;
                // write str[i] and i++
                write(1,&str[i],1);
                i++;
            }
        }
        else
        {
             // write str[i] and i++
             write(1,&str[i],1);
             i++;

        }
    }
}

int main(int ac, char **av)
{
    // protect ac -> retun stderror
    if(ac <= 1)
        return 1;
    

    // fist line
    char *line = get_next_line(0);

    // while is line
    while(line)
    {
    
        // update line by av[1]
        ft_printf(line , av[1]);

        // free line
        free(line);

        // next line
        line = get_next_line(0);
    }

    // free last line
    free(line);

    return 0;
}
