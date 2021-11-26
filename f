
#include "get_next_line.h"

char	*extract_cur_line(char *stc_arr)
{
	int	i;

	i = 0;
	if (!stc_arr[i])
		return (NULL);
	i = 0;
	while (stc_arr[i] && stc_arr[i] != '\n')
		i++;
	return (ft_substr(stc_arr, 0, i + 1));
}

char	*assign_rest(char *stc_arr)
{
	char	*str;
	int		i;

	i = 0;
	if (!stc_arr)
		return (NULL);
	while (stc_arr[i])
	{
		if (stc_arr[i] == '\n')
		{
			str = ft_substr(stc_arr, i + 1, ft_strlen(stc_arr));
			free (stc_arr);
			return (str);
		}
		i++;
	}
	free (stc_arr);
	return (NULL);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stc_arr;
	t_storage	unit_1;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	unit_1.rd_len = 1;
	unit_1.buff = malloc(BUFFER_SIZE + 1);
	while (!(find_nl(stc_arr)) && (unit_1.rd_len))
	{
		unit_1.rd_len = read(fd, unit_1.buff, BUFFER_SIZE);
		if (unit_1.rd_len < 0)
		{
			free(unit_1.buff);
			return (NULL);
		}
		unit_1.buff[unit_1.rd_len] = '\0';
		stc_arr = ft_strjoin(stc_arr, unit_1.buff);
	}
	free(unit_1.buff);
	unit_1.cur_line = extract_cur_line(stc_arr);
	stc_arr = assign_rest(stc_arr);
	return (unit_1.cur_line);
}
-------
