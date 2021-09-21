#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_concat(char const *s1, char const *s2);
char	*ft_search(const char *s, int c);
char	*ft_copy(char *dst, char *src);
char	*ft_duplicate(const char *s);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

#endif
