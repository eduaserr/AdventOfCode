#include "../historian_hysteria.h"

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char) c)
			return ((char *) &str[i]);
	if (str[i] == (char) c)
		return ((char *) &str[i]);
	return (NULL);
}

ssize_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr_gnl(char *str, unsigned int start, ssize_t len)
{
	char	*substr;
	ssize_t	i;

	i = -1;
	if (start >= ft_strlen(str))
		return (NULL);
	if (len + start > ft_strlen(str))
		len = ft_strlen(str) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = str[i + start];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *str)
{
	char	*p;
	int		i;

	i = -1;
	p = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!p)
		return (NULL);
	while (str[++i])
		p[i] = str[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	s3 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i++] = s2[j];
	s3[i] = '\0';
	free(s1);
	return (s3);
}


char	*ft_read(int fd, char *buff)
{
	ssize_t		bytes_read;
	char		*add_buff;

	add_buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!add_buff)
		return (NULL);
	bytes_read = 1;
	add_buff[0] = '\0';
	while (!ft_strchr(add_buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, add_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(add_buff);
			free(buff);
			return (NULL);
		}
		add_buff[bytes_read] = '\0';
		if (bytes_read > 0)
			buff = ft_strjoin_gnl(buff, add_buff);
	}
	free(add_buff);
	return (buff);
}

char	*ft_line(char *buff, char **line)
{
	char	*rest;
	int		l_buff;

	rest = NULL;
	l_buff = ft_strlen(buff);
	if (!buff || !line)
		return (NULL);
	if (ft_strchr(buff, '\n'))
	{
		rest = ft_strdup(ft_strchr(buff, '\n') + 1);
		(*line) = ft_substr_gnl(buff, 0, l_buff - ft_strlen(rest));
	}
	else
	{
		(*line) = ft_substr_gnl(buff, 0, l_buff);
	}
	free(buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff || !ft_strchr(buff, '\n'))
		buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	buff = ft_line(buff, &line);
	return (line);
}