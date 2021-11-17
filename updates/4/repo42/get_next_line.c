
#include"get_next_line.h"

size_t	ft_read(char **buff, char **rest, int fd)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(*rest);
	if (*rest != 0 && j != 0)
	{
		*buff = ft_substr(*rest, 0, j + 1);
		free(*rest);
	}
	else
	{
		free(*rest);
		*buff = ft_calloc_bzero(1, BUFFER_SIZE + 1);
		read(fd, *buff, BUFFER_SIZE);
	}
	i = ft_strlen(*buff);
	if (i == 0)
		free(*buff);
	return (i);
}

size_t	ft_notn(char **print, char **buff, int fd)
{
	char	*aux;

	aux = *print;
	*print = ft_strjoin(aux, *buff);
	free(aux);
	free(*buff);
	*buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
	read(fd, *buff, BUFFER_SIZE);
	return (ft_strlen(*buff));
}

char	*ft_end(char	**buff, char **print, char	**rest, size_t i[2])
{
	char	*aux;
	char	*aux2;
	size_t	j;

	aux2 = ft_substr(*buff, 0, i[1] + 1);
	aux = *print;
	*print = ft_strjoin(aux, aux2);
	free(aux);
	free(aux2);
	j = i[1] + 1;
	if (BUFFER_SIZE > 1)
		*rest = ft_substr(*buff, i[1] + 1, (i[0] - i[1] + 1));
	free(*buff);
	return (*print);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*print;
	size_t		i[2];
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i[0] = ft_read(&buff, &rest, fd);
	if (i[0] == 0)
		return (0);
	print = ft_calloc_bzero(1, 1);
	i[1] = 0;
	while (buff[i[1]] != '\n')
	{
		if (i[1] == (i[0] - 1))
		{
			i[0] = ft_notn(&print, &buff, fd);
			if (i[0] == 0)
				break ;
			i[1] = -1;
		}
		i[1]++;
	}
	return (ft_end(&buff, &print, &rest, i));
}
