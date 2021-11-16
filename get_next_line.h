/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:34:15 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/16 11:35:57 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

size_t		ft_strlen(char *cara);
int			line_len(char *cara);
char		*ft_strjoin(char *s1, char *s2);
char		*line_mallocater(char *cara);
char		*get_next_line(int fd);
char        *ft_strdup(char *cara);


#endif
