#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcompr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str) //Si left_str está vacio, creamos memoria solo para el caracter \0
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)// Si tanto left_str como buff está vacio, devolvemos nulo.
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1)); //Damos a STR la cantidad de memoria de la suma de las dos cadenas
	if (str == NULL) //si ha habido error devolvemos NULL.
		return (NULL);
	i = -1;
	j = 0;
	if (left_str) //Vamos concatenando ambas cadenas en ua tercera y le damos \0 al final 
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0') //
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}