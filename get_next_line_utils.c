/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:45:15 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/17 15:50:36 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *cara)
{
	size_t  len;

	len = 0;
	while (cara[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (s[index] == (char)c)
		return ((char *)s);
	while (s[index++] != '\0')
		if (s[index] == (char)c)
			return ((char *)s + index);
	return (NULL);
}

int	len_of_new_line(char *stc_arr)
{
	int	i;

	i = 0;
	while (stc_arr[i])
	{
		if (stc_arr[i] == '\n')
			break;
		i++;
	}
	if (ft_strchr(stc_arr, '\n') != NULL)
		i += 2;
	else
		i++;
	return (i);
}

char	*cpy_bfr_nl(char *stc_arr)
{
	char *line;
	int i;

	line = (char *)malloc(len_of_new_line(stc_arr) + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stc_arr[i])
	{
		if (stc_arr[i] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
			break;
		}
		line[i] = stc_arr[i];
		i++;
	}
	if (stc_arr[i] == '\0')
		line[i] = '\0';
	return (line);
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