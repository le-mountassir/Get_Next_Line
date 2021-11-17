#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>	  //  printf
#include <sys/stat.h> // open
#include <fcntl.h>	  // open

char *get_next_line(int fd);

#endif