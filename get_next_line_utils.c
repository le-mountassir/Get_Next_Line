/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:31 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/18 13:56:31 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srx;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = dest;
	srx = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = srx[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s + start);
	if (len > size)
		len = size;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s) && len > 0)
		ft_memcpy(sub, s + start, len);
	return (sub);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (i < (count * size))
	{
		s[i] = '\0';
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{	
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
