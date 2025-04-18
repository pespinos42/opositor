#ifndef OPOSITOR_H
# define OPOSITOR_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>  //PARA OPERACIONES DE FICHEROS OPEN...
# include <stddef.h> //PARA DEFINIR NULL
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> //PARA READ
# include <string.h>

char	*ft_get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int	    ft_strlen_n(const char *s);
int	    ft_strlen(char *str);


#endif
