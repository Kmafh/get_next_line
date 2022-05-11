#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != (char)c)
		p++;
	if (*p == (char)c)
		return (p);
	return (0);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*rtr;

	if (count + size < count || count + size < size)
		return (0);
	rtr = malloc(count * size);
	if (!rtr)
		return (0);
	ft_bzero (rtr, count * size);
	return (rtr);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}
