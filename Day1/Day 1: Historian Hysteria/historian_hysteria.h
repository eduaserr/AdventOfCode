#ifndef HISTORIAN_HISTERIA_H
# define HISTORIAN_HISTERIA_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// t_list structure
typedef struct s_list
{
	int				n;
	struct s_list	*next;
}	t_list;

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

// T_LIST MANIPULATION
t_list	*lstnew(int content);
t_list	*init_stack(int nbr);
t_list	*ft_lstlast_ps(t_list *stack);
void	lstadd_back(t_list **stack, t_list *node);
void	get_nbrs(char **str, t_list **left, t_list **right);
//sort list
t_list	*sort_list(t_list *lst);

// OPERATIONS
int		getmax(int left, int right);
int		getmin(int left, int right);
int		operation(t_list **left, t_list **right);

#endif