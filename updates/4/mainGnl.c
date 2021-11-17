
#include"get_next_line.h"
#include<stdio.h>
/*
int	main(void)
{
	int		fd;
//	char	*print;
	
	fd = open("123.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));

	get_next_line(0);	
	get_next_line(0);	
	get_next_line(0);	
	get_next_line(0);	
//	system("leaks a.out");
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	close(fd);
}
*/
int				main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("lotr.txt", O_RDONLY);
// 	get_next_line(fd, &str);
//	printf("%s", str); 
	while ((str = get_next_line(fd)))
	{
        printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
	}
//	system("leaks a.out");
	return (0);
}

