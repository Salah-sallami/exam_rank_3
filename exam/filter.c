#include <unistd.h> // read
#include <stdio.h>	// printf
#include <stdlib.h> // realloc
#include <string.h> // strlen
#include <readline/readline.h>
#include <readline/history.h>

char *search_av_for_string(char *s, char *v)
{
	int len;
	len = strlen(v);
	int i = 0;
	int j = 0;
	while (s[i])
	{
		if (s[i] == v[j])
		{
			while (s[i] == v[j] && v[j] != '\0')
			{
				i++;
				j++;
			}
			if (j == len)
			{
				i = i - len;
				while (s[i] && j > 0)
				{
					s[i] = '*';
					i++;
					j--;
				}
				i--;
			}
			i = i - j;
			j = 0;
		}
		i++;
	}
	return s;
}

static char *ft_red_line(int fd)
{
	char *str = NULL;
	char *bfr = malloc(1);
	ssize_t nmb;
	int i = 0;
	nmb = read(fd, bfr, 1);
	if (nmb <= 0)
		return NULL;
	while (nmb > 0 && *bfr != '\n')
	{
		str = realloc(str, 1);
		str[i] = *bfr;
		nmb = read(fd, bfr, 1);
		i++;
	}
	str[i] = '\0';
	return str;
}

int main(int ac, char **av)
{
	char *str;
	if (ac != 2)
		return 1;

	while (1)
	{
		// str  = readline(STDIN_FILENO);
		str = ft_red_line(STDIN_FILENO);
		if (!str)
			break;

		str = search_av_for_string(str, av[1]);
		printf("%s\n", str);
		free(str);
	}

	// fflush(stdout);
	free(str);
}
