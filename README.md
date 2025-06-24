# 42_Exams
42 Berlin | Exams
# exam_rank_3
# exam_rank_3


void    ft_print_etoile(char    *av)
{
    int i = 0;
    while(av[i])
    {
        write(1, "*", 1);
        i++;
    }
}

void    ft_printf(char *str, char *av)
{
    int j;
    int i = 0;

    // while str
    while(str[i])
    {
        // return j = 0
        j = 0;

        // 'c' == 'c'
        if(str[i] == av[j])
        {
            // while 'c'++ == 'c'++
            while(str[i] == av[j])
            {
                i++;
                j++;
            }

            // check last 'c' in av
            if(av[j] == '\0')
                // print * == len av
                ft_print_etoile(av);
            else
            {
                // return position i 
                i = i - j;
                // write str[i] and i++
                write(1, &str[i], 1);
                i++;
            }
        }
        else
        {
             // write str[i] and i++
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    // protect ac -> retun stderror
    if (ac <= 1)
        return 1;

    // fist line
    char *line = get_next_line(0);

    // while is line
    while (line)
    {
        // update line by av[1]
        ft_printf(line, av[1]);

        // free line
        free(line);

        // next line
        line = get_next_line(0);
    }

    // free last line
    free(line);

    return 0;
}