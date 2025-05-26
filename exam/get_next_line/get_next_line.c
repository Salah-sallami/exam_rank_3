#include "get_next_line.h"



char *ft_strdup(char *str)
{
    char *copy;
    int i;

    copy = malloc(strlen(str) + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[1024];
    static int n_read;
    static int offset;
    int i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        printf("%d >= %d\n",offset >= n_read);
        if (offset >= n_read)
        {
            n_read = read(fd, buffer, BUFFER_SIZE);
            offset = 0;
            if (n_read <= 0)
            {
                if (n_read == -1)
                    return NULL;
                break;
            }
        }
        line[i++] = buffer[offset++];
        if (buffer[offset - 1] == '\n')
            break;
    }
    if (n_read == -1)
        return NULL;
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}

     #include <fcntl.h>
      #include <stdio.h>
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
}