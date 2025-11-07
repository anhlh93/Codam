#include <stdio.h> //printf, perror
#include <unistd.h> //read
#include <string.h> //strlen

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

void search_replace(char *line, char *str)
{
    if (!line | !str | strlen(line) <strlen(str))
        return ;
    int i = 0;
    while (line[i])
    {
        int j = 0;
        int match = 1;
        while (str[j])
        {
            if (line[i + j] != str[j])
            {
                match = 0;
                break;
            }
            j++;
        }
        if (match == 1)
        {
            j = 0;
            while (str[j])
            {
                line [i + j] = '*';
                j++;
            }
            i += j;
        }
        else
            i++;
    }
}

int main (int ac, char **av)
{
    if (ac != 2 | av[1][0] == '\0')
        return 1;
    char line[70000];
    char buffer[BUFFER_SIZE];
    int byte_read = 0;
    int line_pos = 0; 

    while (1)
    {
        byte_read = read(0, buffer, BUFFER_SIZE);
        if (byte_read < 0)
        {
            perror("Error:");
            return (1);
        }
        if (byte_read == 0)
            break;
        int i = 0;
        while (byte_read > i)
        {
            if (buffer[i] == '\n')
            {
                line[line_pos] = '\0';
                search_replace(line, av[1]);
                printf("%s\n", line);
                line_pos = 0;
                i++;
            }
            else
            {
                line[line_pos] = buffer[i];
                i++;
                line_pos++;
            }
        }
    }
    return (0);
}