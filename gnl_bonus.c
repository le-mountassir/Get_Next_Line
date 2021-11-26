/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:40:13 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/26 05:40:13 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_bonus.h"

void	check_if_1stcall(t_storage *unit_4, char **stc_arr)
{
	if (*stc_arr != 0 && ft_strlen(*stc_arr) != 0)
	{
		unit_4->buff = ft_calloc(ft_strlen(*stc_arr) + 1, sizeof(char));
		ft_memcpy(unit_4->buff, *stc_arr, ft_strlen(*stc_arr) + 1);
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
	unit_4->buf_len = ft_strlen(unit_4->buff);
}

char	*get_next_line(int fd)
{
	static char		*stc_arr[69024];
	t_storage		unit_1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	unit_1.fd = fd;
	if (!(ft_strlen(stc_arr[fd])))
		stc_arr[fd] = ft_calloc(1, 1);
	check_if_1stcall(&unit_1, &stc_arr[fd]);
	if (unit_1.buf_len == 0)
		return (0);
	unit_1.cur_line = ft_calloc(1, sizeof(char));
	unit_1.j = 0;
	while (unit_1.buff[unit_1.j] != '\n')
	{
		if (unit_1.j == (unit_1.buf_len - 1))
		{	
			keep_joinin_nl(&unit_1);
			if (unit_1.buf_len == 0)
				break ;
			unit_1.j = -1;
		}
		unit_1.j++;
	}
	return (rt_cur_line(&stc_arr[fd], &unit_1));
}