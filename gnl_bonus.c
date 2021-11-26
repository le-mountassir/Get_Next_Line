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