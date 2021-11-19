/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:24 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/18 13:56:24 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*buff_locater(int fd, char *stc_arr)
{
	char *buff;

	if (stc_arr != 0 && ft_strlen(stc_arr) != 0)
	{
		buff = ft_substr(stc_arr, 0, ft_strlen(stc_arr) + 1);
		free(stc_arr);
	}
	else
	{
		free(stc_arr);
		buff = ft_calloc(1, BUFFER_SIZE + 1);
		read(fd, buff, BUFFER_SIZE);
	}
	return (buff);
}


char	*get_next_line(int fd)
{
	static char	*stc_arr;
	char		*buff;
	char		*cur_line;
	char		*tmp;
	char		*tmp2;
	size_t		stc_len;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stc_len = ft_strlen(stc_arr);
	buff = buff_locater(fd, stc_arr);
	stc_len = ft_strlen(buff);
	if (stc_len == 0)
	{
		free(buff);
		return (0);
	}
	cur_line = ft_calloc(1, 1);
	i = 0;
	while (buff[i] != '\n')
	{
		if (i == stc_len - 1)
		{
			tmp = cur_line;
			cur_line = ft_strjoin(tmp, buff);
			free(tmp);
			free(buff);
			buff = ft_calloc(1, BUFFER_SIZE + 1);
			read(fd, buff, BUFFER_SIZE);
			stc_len = ft_strlen(buff);
			if (stc_len == 0)
				break ;
			i = -1;
		}
		i++;
	}
	tmp2 = ft_substr(buff, 0, i + 1);
	tmp = cur_line;
	cur_line = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	if (BUFFER_SIZE > 1)
		stc_arr = ft_substr(buff, i + 1, stc_len - i);
	free(buff);
	return (cur_line);
}
