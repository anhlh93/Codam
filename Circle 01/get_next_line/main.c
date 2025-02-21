#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main() {
    int fd = open("bible.txt", O_RDONLY);
    char *s = get_next_line(fd);
    while(s){
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
    }
}