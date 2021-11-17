#include "get_next_line.h"

#define BUFFER_SIZE 10

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	new_str = malloc(i + j + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	return (new_str);
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

char *get_line(char *backup)
{
	char *line;
	int i;
	int index;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			break;
		i++;
	}
	if (ft_strchr(backup, '\n') != NULL)
		i += 2;
	else
		i++;
	line = malloc(i + 1);
	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = 0;
			break;
		}
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\0')
		line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *backup;
	unsigned long bytes_read;
	char *line;
	int len_line;

	if (fd < 0 || fd >= RLIMIT_NOFILE || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (buf[BUFFER_SIZE] != '\0')
		buf[BUFFER_SIZE] = '\0';
	printf("print buf: (%s)\n", buf);
	if (bytes_read == 0 && *backup == '\0')
		return (NULL);
	if (backup == NULL)
	{
		backup = malloc(1);
		*backup = 0;
	}
	//line = backup;
	if (bytes_read != 0)
		backup = ft_strjoin(backup, buf);
	printf("print backup: (%s)\n", backup);
	//free(line);
	while (ft_strchr(backup, '\n') == NULL && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		//line = backup;
		backup = ft_strjoin(backup, buf);
		//free(line);
	}
	line = get_line(backup);
	if (ft_strchr(backup, '\n') == NULL)
	{
		while (*backup)
			backup++;
		backup++;
	} 
	else
		backup = ft_strchr(backup, '\n') + 1;
	return (line);
}

int main()
{
	int fd;
	char **a;

	a = malloc(300);
	fd = open("a.txt", O_RDONLY);
	int i = 0;
	while (1)
	{
		a[i] = get_next_line(fd);
		if (a[i] == NULL)
			break;
		i++;
	}
	int j = 0;
	while (j < i)
		printf("%s", a[j++]);
}