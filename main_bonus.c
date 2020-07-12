#include "get_next_line_bonus.h"
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
	int		fd_1;
	int		fd_2;
	int		df_1;
	int		df_2;
	int		count;

//	len = NULL;
	df_1 = open("result1.txt", O_WRONLY | O_CREAT);
	df_2 = open("result2.txt", O_WRONLY | O_CREAT);
	fd_1 = open("len.txt", O_RDONLY);
//	fd = open("gull.txt", O_RDONLY);
	fd_2 = open("atlas_shrugged.txt", O_RDONLY);
//	fd = open("empty.txt", O_RDONLY);
//	fd = open("many_spaces.txt", O_RDONLY);
//	fd = open("147.txt", O_RDONLY);
	if (fd_1 == -1 || fd_2 == -1)
	{
		printf("open() error");
		return (1);
	}
//	while ((count = get_next_line(42, &len)) > 0)
	while ((count = get_next_line(fd_1, &len)) > 0)
	{
		ft_putendl_fd(len, df_1);
//		printf("[%d]%s\n", count, len);
		free(len);
	}
	if (count == 0)
		printf("[%d]\n", count);
	else if (count == -1)
		printf("[%d]\n", count);
	if (close(fd_1) == -1 || close(df_1) == -1)
	{
		printf("close() error");
		return (1);
	}


	while ((count = get_next_line(fd_2, &len)) > 0)
	{
		ft_putendl_fd(len, df_2);
//		printf("[%d]%s\n", count, len);
		free(len);
	}
	if (count == 0)
		printf("[%d]\n", count);
	else if (count == -1)
		printf("[%d]\n", count);
	if (close(fd_2) == -1 || close(df_2) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}*/

/*int		main()
{
	char	*len;
	int		count;

	while ((count = get_next_line(0, &len)) > 0)
	{
		printf("[%d] %s\n", count, len);
		free(len);
	}
	return (0);
}*/

/*int		main()
{
	char	*len;
	int		count;
	int		fd_1;
	int		fd_2;
	int		fd_3;

	fd_1 = open("len.txt", O_RDONLY);
    if (fd_1 == -1)
    {
        printf("open() error");
        return (1);
    }

	fd_2 = open("gull.txt", O_RDONLY);
    if (fd_2 == -1)
    {
        printf("open() error");
        return (1);
    }

	fd_3 = open("atlas_shrugged.txt", O_RDONLY);
    if (fd_3 == -1)
    {
        printf("open() error");
        return (1);
    }

	count = get_next_line(fd_1, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_2, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_3, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_1, &len);
	printf("[%d]%s\n", count, len);
	free(len);

    count = get_next_line(fd_2, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_3, &len);
    printf("[%d]%s\n", count, len);
    free(len);


    count = get_next_line(fd_1, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_2, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_3, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_1, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_2, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    count = get_next_line(fd_3, &len);
    printf("[%d]%s\n", count, len);
    free(len);

    if (close(fd_1) == -1)
    {
        printf("close() error");
        return (1);
    }

    if (close(fd_2) == -1)
    {
        printf("close() error");
        return (1);
    }
    if (close(fd_3) == -1)
    {
        printf("close() error");
        return (1);
    }
	return (0);
}*/

int main()
{
	char	*len;
	int		count;
	int		fd_3;
	int		fd_4;
	int		fd_5;
	int		fd_6;
	int		fd_7;

	fd_3 = open("3", O_RDONLY);
	fd_4 = open("4", O_RDONLY);
	fd_5 = open("5", O_RDONLY);
	fd_6 = open("6", O_RDONLY);
	fd_7 = open("7", O_RDONLY);
    if (fd_3 == -1 || fd_4 == -1 || fd_5 == -1 || fd_6 == -1 || fd_7 == -1)
    {
        printf("open() error");
        return (1);
    }
	// 1
	count = get_next_line(fd_5, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_3, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_6, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_4, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	//2
	count = get_next_line(fd_5, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_3, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_4, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_6, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	//3
	count = get_next_line(fd_3, &len);
	printf("fd_3 = [%d]%s\n", count, len);

	count = get_next_line(fd_4, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_6, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_5, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	//4
	count = get_next_line(fd_5, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_6, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_4, &len);
	printf("fd_4 = [%d]%s\n", count, len);
	
	//5
	count = get_next_line(fd_5, &len);
	printf("fd5 = [%d]%s\n", count, len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	count = get_next_line(fd_6, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	//6

    count = get_next_line(fd_6, &len);
    printf("fd_6 = [%d]%s\n", count, len);

	count = get_next_line(fd_7, &len);
	printf("[%d]%s\n", count, len);
	free(len);

	//7
    count = get_next_line(fd_7, &len);
    printf("fd_7 = [%d]%s\n", count, len);

	if (close(fd_3) == -1 || close(fd_4) == -1 || close(fd_5) == -1 || close(fd_6) == -1 || close(fd_7) == -1)
    {
        printf("close() error");
        return (1);
    }

	return 0;
}
