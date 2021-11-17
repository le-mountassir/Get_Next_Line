
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buff;
	char		*print;
	char		*aux;
	char		*aux2;
	size_t		j;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	j = ft_strlen(rest);
	if (rest != 0 && j != 0)
	{
		buff = ft_substr(rest, 0, j + 1);
		free(rest);
	}
	else
	{
		free(rest);
		buff = ft_calloc(1, BUFFER_SIZE + 1);
		read(fd, buff, BUFFER_SIZE);
	}
	j = ft_strlen(buff);
	if (j == 0)
	{
		free(buff);
		return (0);
	}
	print = ft_calloc(1, 1);
	i = 0;
	while (buff[i] != '\n')
	{
		if (i == j - 1)
		{
			aux = print;
			print = ft_strjoin(aux, buff);
			free(aux);
			free(buff);
			buff = ft_calloc(1, BUFFER_SIZE + 1);
			read(fd, buff, BUFFER_SIZE);
			j = ft_strlen(buff);
			if (j == 0)
				break ;
			i = -1;
		}
		i++;
	}
	aux2 = ft_substr(buff, 0, i + 1);
	aux = print;
	print = ft_strjoin(aux, aux2);
	free(aux);
	free(aux2);
	if (BUFFER_SIZE > 1)
		rest = ft_substr(buff, i + 1, j - i);
	free(buff);
	return (print);
}
