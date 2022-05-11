#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif



char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif