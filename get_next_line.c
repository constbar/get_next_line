#include "get_next_line.h"

char	*check_pn(char **remains, char **line)
{
	char	*new_pn;

	new_pn = NULL;
	if (!*remains)
	{
		*line = ft_duplicate("");
		return (NULL);
	}
	if ((new_pn = ft_search(*remains, '\n')))
	{
		*new_pn = '\0';
		new_pn++;
		*line = ft_duplicate(*remains);
		ft_copy(*remains, new_pn);
	}
	else
	{
		*line = ft_duplicate(*remains);
		if (*remains)
		{
			free(*remains);
			*remains = NULL;
		}
	}
	return (new_pn);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static	char	*remains[128];
	char			*temp;
	char			*pn;
	int				bwr;

	if (!line || fd < 0 || fd > 127 || BUFFER_SIZE < 1
	|| read(fd, buf, 0) == -1)
		return (-1);
	pn = check_pn(&remains[fd], line);
	while (!pn && (bwr = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bwr] = '\0';
		if ((pn = ft_search(buf, '\n')))
		{
			*pn = '\0';
			remains[fd] = ft_duplicate(++pn);
		}
		temp = *line;
		if (!(*line = ft_concat(*line, buf)))
			return (-1);
		free(temp);
		temp = NULL;
	}
	return (pn ? 1 : 0);
}
