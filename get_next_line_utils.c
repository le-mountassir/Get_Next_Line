/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:34:01 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/17 09:07:48 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_nl_detec(char *cara)
{
	int i = 0;
	while (*cara)
	{
		if (*cara == '\n')
			return (0);
	
	}
	return (1);
}

size_t  ft_strlen(char *cara)
{
    size_t  len;

    len = 0;
    while (cara[len])
        len++;
    return (len);   
}

int		line_len(char *cara)
{
	int	len;
	while (cara[len] && cara[len] != '\n')
		len++;
	return (len);
}

char    *ft_strdup(char *s)
{
        size_t          i;
        char            *str;

        i = 0;
        str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
        if (!str)
                return (NULL);
        while (s[i])
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*line_mallocater(char *string)
{
	int		len;
	char	*rt;
	int		i;

	i = 0;
	len = line_len(string);
	rt = (char *)malloc(sizeof(char) * len + 1);
	while (i++ < len)
		rt[i] = string[i];
	return (rt);
}
