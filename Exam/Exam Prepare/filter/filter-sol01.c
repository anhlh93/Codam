#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
int ft_strncmp(char *s1, char *s2, size_t n)
{
    size_t i = 0;
    while(i < n && s1 && s2)
    {
        if(s1[i] != s2[i])
            return 1;
            i++;
    }
    return 0;
}
char *ft_strdup(char *s)
{
    int  i = 0;
    char *new = malloc(strlen(s) + 1);
    if(!new)
    {
        perror("error");
        return NULL;
    }
    while(s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
char *gnl(int fd)
{
    int i = 0;
    static char buffer[BUFFER_SIZE];
    static int b_read;
    static int pos;
    char line[100000];
    while(1)
    {
        if(pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if(b_read < 0)
            {
                perror("error");
                break;
            }
            if(b_read == 0)
                break;
        }
        line[i++] = buffer[pos++];
        if(line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return (ft_strdup(line));
}
int main(int ac, char **av)
{
    if( ac != 2 || av[1][0] == '\0')
        return 1;
    size_t len_p = strlen(av[1]);
    char *line;
    while((line = gnl(0))!= NULL)
    {
        char p = line;
        while(p)
        {
            if(ft_strncmp(av[1], p, len_p) == 0)
            {
                for(size_t i = 0 ; i < len_p; i++)
                    write(1, "*", 1);
                p+=len_p;
            }
            else
                write(1, p++, 1);
        }
        free(line);
    }
}
