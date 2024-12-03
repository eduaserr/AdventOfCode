#ifndef RED_NOSED_H
# define RED_NOSED_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// STRING MANIPULATION //
// get_next_line
char	*ft_strchr(char *str, int c);
ssize_t	ft_strlen(char *str);
char	*ft_substr_gnl(char *str, unsigned int start, ssize_t len);
char	*ft_strdup(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_read(int fd, char *buff);
char	*ft_line(char *buff, char **line);
char	*get_next_line(int fd);
// ft_split
int		countwords(char *str);
char	*ft_getword(char *str, int start, int end);
char	**ft_split(char *str);

// CHECK
int		diff(int n1, int n2);
int		check_order(char **str);

#endif