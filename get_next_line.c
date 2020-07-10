/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarina <gkarina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:53:52 by gkarina           #+#    #+#             */
/*   Updated: 2020/07/01 14:53:52 by gkarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*check_remainder(char **line, char *rem)
{
	char		*temp;
	int			count;

	count = 0;
	while (rem[count] != '\n')
		count++;
	if (((*line) = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	ft_strlcpy(*line, rem, ++count);
	(*line)[--count] = '\0';
	if ((temp = ft_strdup(&rem[++count])) == NULL)
	{
		free(*line);
		return (NULL);
	}
	free(rem);
	rem = temp;
	return (rem);
}

static void		init_line(char **line, t_data *data)
{
	data->var = NULL;
	data->err = 0;
	if (data->rem)
		if ((data->var = ft_strchr(data->rem, '\n')))
		{
			if ((data->rem = check_remainder(line, data->rem)) == NULL)
				data->err = -1;
		}
		else
		{
			if ((*line = ft_strdup(data->rem)) == NULL)
				data->err = -1;
			free(data->rem);
		}
	else
	{
		if ((*line = ft_strdup("\0")) == NULL)
			data->err = -1;
	}
}

static t_data	*update_line(char **line, char *buff, int len, t_data *data)
{
	char		*temp;
	int			count;

	buff[len] = '\0';
	count = 0;
	if ((data->var = ft_strchr(buff, '\n')))
	{
		while (buff[count] != '\n')
			count++;
		buff[count] = '\0';
		if ((data->rem = ft_strdup(&buff[++count])) == NULL)
		{
			data->err = -1;
			return (data);
		}
	}
	temp = *line;
	if ((*line = ft_strjoin(*line, buff)) == NULL)
	{
		free(data->rem);
		data->err = -1;
	}
	free(temp);
	return (data);
}

static int		prog_logic(char **line, char *buff, int fd, t_data *data)
{
	init_line(line, data);
	if (data->err == -1)
	{
		free(data);
		return (-1);
	}
	while (!(data->var) && (data->len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		data = update_line(line, buff, data->len, data);
		if (data->err == -1)
		{
			free(data);
			return (-1);
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	t_data		*data;
	char		buff[BUFFER_SIZE + 1];
	static char	*rem;
	int         len;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (-1);
	data->rem = rem;
	data->len = 1;
	if ((prog_logic(line, buff, fd, data)) == -1)
		return (-1);
	rem = data->rem;
	len = data->len;
	free(data);
	if (len > 0)
        return (1);
	else if (len == 0)
        return (0);
	return (-1);
}
