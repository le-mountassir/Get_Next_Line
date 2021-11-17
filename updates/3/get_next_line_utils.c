
#include "get_next_line.h"

void	free_function(char **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
}

int	index_rest(char *string)
{
	size_t		index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '\n')
			return (index + 1);
		index++;
	}
	return (-1);
}
