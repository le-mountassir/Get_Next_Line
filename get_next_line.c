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

size_t	read_or_continue(t_storage *unit_4, char **stc_arr)
{
	if (*stc_arr != 0 && ft_strlen(*stc_arr) != 0)
	{
		unit_4->buff = ft_substr(*stc_arr, 0, ft_strlen(*stc_arr) + 1);
		free(*stc_arr);
	}
	else
	{
		free(*stc_arr);
		unit_4->buff = ft_calloc(1, BUFFER_SIZE + 1);
		read(unit_4->fd, unit_4->buff, BUFFER_SIZE);
	}
	if (ft_strlen(unit_4->buff) == 0)
		free(unit_4->buff);
	return (ft_strlen(unit_4->buff));
}

size_t	join_nd_free(t_storage *unit_3)
{
	unit_3->tmp = unit_3->cur_line;
	unit_3->cur_line = ft_strjoin(unit_3->tmp, unit_3->buff);
	free(unit_3->tmp);
	free(unit_3->buff);
	unit_3->buff = (char *)ft_calloc(1, (BUFFER_SIZE + 1));
	read(unit_3->fd, unit_3->buff, BUFFER_SIZE);
	return (ft_strlen(unit_3->buff));
}

char	*curr_line(char **stc_arr, t_storage *unit_2)
{
	unit_2->tmp2 = ft_substr(unit_2->buff, 0, unit_2->j + 1);
	unit_2->tmp = unit_2->cur_line;
	unit_2->cur_line = ft_strjoin(unit_2->tmp, unit_2->tmp2);
	free(unit_2->tmp);
	free(unit_2->tmp2);
	if (BUFFER_SIZE > 1)
		*stc_arr = ft_substr(unit_2->buff, unit_2->j + 1, (unit_2->buf_len - unit_2->j + 1));
	free(unit_2->buff);
	return (unit_2->cur_line);
}

char	*get_next_line(int fd)
{
	static char		*stc_arr;
	t_storage		unit_1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	unit_1.fd = fd;
	unit_1.buf_len = read_or_continue(&unit_1, &stc_arr);
	if (unit_1.buf_len == 0)
		return (0);
	unit_1.cur_line = ft_calloc(1, 1);
	unit_1.j = 0;
	while (unit_1.buff[unit_1.j] != '\n')
	{
		if (unit_1.j == (unit_1.buf_len - 1))
		{
			unit_1.buf_len = join_nd_free(&unit_1);
			if (unit_1.buf_len == 0)
				break ;
			unit_1.j = -1;
		}
		unit_1.j++;
	}
	return (curr_line(&stc_arr, &unit_1));
}
