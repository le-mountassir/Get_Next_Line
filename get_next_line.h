/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/18 13:56:20 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// typedef struct get_next_line
// {
// 	char		*tmp;
// 	char		*tmp2;
// 	char		*cur_line;
// 	char		*buff;
// }   storage_unit;

char	*get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_substr(char const *s, int star, size_t len);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
