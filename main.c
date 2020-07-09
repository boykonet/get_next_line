#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		len;

	if (s != NULL && *s != '\0')
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*int		main()
{
	char	*len;
	int		fd;
	int		df;
	int		count;

	len = NULL;
	df = open("result.txt", O_WRONLY | O_CREAT);
//	fd = open("len.txt", O_RDONLY);
//	fd = open("gull.txt", O_RDONLY);
//	fd = open("atlas_shrugged.txt", O_RDONLY);
//	fd = open("empty.txt", O_RDONLY);
//	fd = open("many_spaces.txt", O_RDONLY);
	fd = open("147.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
//	while ((count = get_next_line(42, &len)) > 0)
	while ((count = get_next_line(fd, &len)) > 0)
	{
		ft_putendl_fd(len, df);
//		printf("[%d]%s\n", count, len);
		free(len);
	}
	if (count == 0)
		printf("[%d]\n", count);
	else if (count == -1)
		printf("[%d]\n", count);
	if (close(fd) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}*/

int		main()
{
	char	*len;
	int		count;

	while ((count = get_next_line(0, &len)) > 0)
	{
		printf("[%d] %s\n", count, len);
		free(len);
	}
	return (0);
}
