
#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize, size_t l)
{
	size_t			i;

	i = 0;
	if (dstsize > 0)
	{	
		while ((i < dstsize - 1) && (i < l))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	l = ft_strlen(s);
	if (!s)
		return (0);
	if (len > l)
		len = l;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < l)
		ft_strlcpy(str, &s[start], len + 1, l);
	else
		ft_strlcpy(str, "", 1, l);
	return (str);
}

void	*ft_calloc_bzero(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(count * size);
	if (!s)
		return (0);
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
