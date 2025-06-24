#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int i = 0;
	char *cp = malloc(sizeof(char) * (strlen(s) + 1));
	if (!cp)
		return NULL;
	while(s[i])
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return cp;
}

char *get_next_line(int fd)
{

    // 3 static variable 
    static char buffer[BUFFER_SIZE];
    static int b_read;
    static int b_pos;

    // Protect fd and BUFFER_SIZE
    if(fd < 0 || BUFFER_SIZE < 1)
        return NULL;

    //  while inlimit
    int i = 0;
    char line[70000];
    while (1)
    {

        // if b_pos++ -> -> >= b_read
        if(b_pos >= b_read)
        {
            // read in fd for use buffer
            b_read = read(fd,buffer,BUFFER_SIZE);

            // return value 0 at b_pos for use buffer
            b_pos = 0 ;

            // non read break while
            if(b_read <= 0)
                break;
        }
		
	

        // push buffer in line
        line[i++] = buffer[b_pos++];


        // if \n for buffer
        if(buffer[b_pos - 1] == '\n')
            break;

    }
    line[i] = '\0';

    // non while so i = 0 so NULL
    if(i == 0)
        return NULL;

    
    // return line
    return(ft_strdup(line));
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}