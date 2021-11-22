/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/21 15:27:35 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct dipo_dial_variablat
{
	int		fd;
	size_t	buf_len;
	size_t	j;
	char	*tmp;
	char	*tmp2;
	char	*buff;
	char	*cur_line;
}			t_storage;

size_t		ft_strlen(const char *cara);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t count, size_t size);
char		*get_next_line(int fd);

#endif
