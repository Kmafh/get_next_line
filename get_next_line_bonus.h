#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 1000
# endif

size_t	ft_strlen(const char *s);
char	*ft_strcompr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*get_next_line(int fd);
char	*get_line(int fd, char *src);
char	*validate_line(char *src);
char * get_new_line(char *src);

#endif