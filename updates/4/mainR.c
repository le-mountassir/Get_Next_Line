#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	char buf[26];
	size_t nbytes;
	int fd;

	fd = open("ELQuijote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (0);
	}		
	nbytes = 25;
	read(fd, buf, nbytes);
	buf[25] = '\0';
	printf("buf: %s\n", buf);

	read(fd, buf, nbytes);
	buf[25] = '\0';
	printf("buf: %s\n", buf);
	
	close(fd);
	printf("Close\n");
	fd = open("ElQuijote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (0);
	}	
	read(fd, buf, nbytes);
	buf[25] = '\0';
	printf("buf: %s\n", buf);
}
