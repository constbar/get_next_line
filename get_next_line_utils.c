#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_copy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_concat(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

char		*ft_search(const char *s, int c)
{
	char	*p;

	p = (char*)s;
	while (*p && *p != c)
		p++;
	if (*p == c)
		return (p);
	return (NULL);
}

char		*ft_duplicate(const char *s)
{
	size_t	i;
	size_t	k;
	char	*new;

	i = 0;
	k = ft_strlen(s);
	new = (char*)malloc((k + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < k)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
