
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize, size_t l);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc_bzero(size_t count, size_t size);
char	*get_next_line(int fd);
#endif
