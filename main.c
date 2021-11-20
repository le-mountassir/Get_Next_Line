#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDWR);
    while (1)
    {
        char *cur = get_next_line(fd);
        if (!cur)
            break;
        printf("%s", cur);
    }
}