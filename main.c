#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c

int main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	ret = get_next_line(fd, &line);

	while (ret) {
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}

	close(fd);
	return 0;
}