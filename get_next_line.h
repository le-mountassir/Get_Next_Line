/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:45:24 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/17 15:37:30 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//open
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *c1, char *c2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *cara);
int		len_of_line(char *stc_arr);
char    *cpy_bfr_nl(char *stc_arr);

#endif