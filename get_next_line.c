/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:34:08 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/16 14:33:44 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int  fd)
{
	char			*tmp_arr;
	static char		*stc_arr;
	// int				n_b_file;
	int				checker;
	size_t read_f;
	checker = 1;
	
	printf("File_D = %d\n", fd);
	
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		tmp_arr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_f = read(fd, tmp_arr, BUFFER_SIZE);
		tmp_arr[read_f] = '\0';
		printf("READ VAL = %zu\nSTR_IMPORTED =\n%s", read_f, tmp_arr);
		
		//printf("\n static arr  = %s", ft_strjoin(stc_arr, tmp_arr));
	}
	return (NULL);
}
int main ()
{
	int fd = open("get_next_line.h", O_RDONLY);
	get_next_line(fd);
}