

/*Nombre de fun- ción get_next_line
Prototipo  char *get_next_line(int fd);
Archivos a entre- gar get_next_line.c, get_next_line_utils.c,
get_next_line.h
Parámetros Valor devuelto File descriptor del que leer
Si todo va bien: la línea leída
En caso de fallo o si la lectura termina: NULL
Funciones autori- zadas

read, malloc, free

Descripción

Escribe una función que devuelva la línea leída de
un file descriptor
*/

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *get_next_line(int fd)
{
    char *buf;
	char *dest;
	char *src;
	int i;
    ssize_t nbytes;
	i=0;
	buf=(char *)malloc(BUFFER_SIZE * sizeof(char));
	dest=(char *)malloc(BUFFER_SIZE * sizeof(char));
    if(fd==-1)
        {
            return "Error al abrir el archivo.\n";
        }
        else{

           nbytes=read(fd,buf,BUFFER_SIZE);
           if(nbytes==0)
			 		printf("Archvio vacio.\n");
            else
				{
					//printf("%d",BUFFER_SIZE);
					while(buf[i]!='\n' && i!=BUFFER_SIZE)
					{
						
						dest[i]=buf[i];
						//printf("%c",buf[i]);
						i++;
					}
					dest[i]='\0';
				}
				src=ft_strjoin(src,dest);
        }
	free(buf);
	return(src);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test/test1.txt", O_RDONLY);

	i = 1;
	while (i < 3)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
