#include "historian_hysteria.h"

int main(void)
{
	t_list	*left = NULL;
	t_list	*right = NULL;
	char	**str;
	long	result = 0;
	char	*line;
	int		fd;

	fd = open("txt.txt", O_RDONLY);
	if (fd < 0)
		return (printf("error fd\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		str = ft_split(line);
		free(line);
		get_nbrs(str, &left, &right);
		line = get_next_line(fd);
	}
	result = operation(left, right);
	close(fd);
	printf("%ld\n", result);
	return (0);
}
