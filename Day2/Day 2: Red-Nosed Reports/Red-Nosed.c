#include "Red-Nosed.h"

int main(void)
{
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
		if (check_order(str) == 1)
		{
			result++;
		}
		line = get_next_line(fd);
	}
	close(fd);
	printf("%ld\n", result);
	return (0);
}
