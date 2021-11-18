/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:45:34 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/17 16:09:10 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*locat_next_line(char *stc_arr)
{
	if (!(ft_strchr(stc_arr, '\n')))
	{
		while (*stc_arr)
			stc_arr++;
		stc_arr++;
	} 
	else
		stc_arr = ft_strchr(stc_arr, '\n') + 1;
	return (stc_arr);
}

char	*join_strings(int fd, int bytes_read, char *stc_arr, char *buf)
{	
	if (!stc_arr)
	{
		stc_arr = (char *)malloc(1 * sizeof(char));
		*stc_arr = '\0';
	}
	if (bytes_read)
		stc_arr = ft_strjoin(stc_arr, buf);
	while (!(ft_strchr(stc_arr, '\n')) && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		stc_arr = ft_strjoin(stc_arr, buf);
	}
	return (stc_arr);
}

char *get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stc_arr;
	char			*line;
	size_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (bytes_read == 0 && !(*stc_arr))
		return (NULL);
	stc_arr = join_strings(fd, bytes_read, stc_arr, buf);
	line = cpy_bfr_nl(stc_arr);
	if (!line)
		return (NULL);
	stc_arr = locat_next_line(stc_arr);
	return (line);
}

int main()
{
	int fd;
	int i = 5;
	fd = open("get_next_line.h", O_RDONLY);
	while (i > 0)
	{
		printf ("\n%s", get_next_line(fd));
		i--;
	}
}