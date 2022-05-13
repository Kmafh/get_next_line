#include "get_next_line.h"
#include <stdio.h>

char * get_new_line(char *src)
{
	int i;
	int j;
	i=0;
	char *str;

	while(src[i] && src[i]!='\n')
		i++;
	if(!src[i])
		{
			free(src);
			return (NULL);
		}
	str=malloc(sizeof(char) * (ft_strlen(src) - i +1));
	
	if(!str)
			return (NULL);
			
	i++;
	j=0;

	while(src[i])
		{
			str[j]=src[i];
			i++;
			j++;
		}
	str[j]='\0';

	free(src);
	return (str);
}

char *validate_line(char *src)
{
	int i;
	char *str;
	i=0;
	if(!src[i])
		return (NULL);
	while(src[i] && src[i]!='\n')
		i++;
	str=(char *)malloc(sizeof(char) * (i + 2));
	if(!str)
		return (NULL);
	i=0;
	while(src[i] && src[i]!='\n')
		{
			str[i]=src[i];
			i++;
		}
	if(src[i]=='\n')
		{
			str[i]=src[i];
			i++;
		}
		str[i]='\0';
	
	return (str);
}

char *get_line(int fd,char *src)
{
	int result;
	char *buff;

	buff=malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
		return (NULL);
	result=1;
	while(!ft_strcompr(src,'\n') && result!=0)
		{
			result=read(fd,buff,BUFFER_SIZE);
			if(result<0)
				{
					free(buff);
					return (NULL);
				}
			buff[result]='\0';
			src= ft_strjoin(src,buff);
		}
		free(buff);
		return (src);
}

char *get_next_line(int fd)
{
	static char *src[4050];
	char *line;
	if(fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	src[fd]=get_line(fd,src[fd]);
	if(!src[fd])
		return (NULL);
	line=validate_line(src[fd]);
	src[fd]=get_new_line(src[fd]);
	return (line);
}

/*int	main(void)
{
	
	char	*line;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("test/test1.txt", O_RDONLY);
	fd2 = open("test/test2.txt", O_RDONLY);

	i = 1;
	
	while (i < 9)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/