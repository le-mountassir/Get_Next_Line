/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:34:08 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/15 17:34:08 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int  fd)
{
	char			*tmp_arr;
	static char		*stc_arr;
	int				n_b_file;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		tmp_arr = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!tmp_arr)
			return (NULL);
		return

	}
	return (NULL);
}