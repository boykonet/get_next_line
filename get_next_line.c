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
	int			i;

	i = 0;
	count = 0;
	while (rem[count] != '\n')
		count++;
	if (((*line) = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	count = 0;
	while (rem[count] != '\n')
		(*line)[i++] = rem[count++];
	(*line)[i] = '\0';
	if ((temp = ft_strdup(&rem[++count])) == NULL)
		return (NULL);
	free(rem);
	if ((rem = ft_strdup(temp)) == NULL)
		return (NULL);
	free(temp);
	return (rem);
}

static void		init_line(char **line, char *rem, t_data *data)
{
	if (rem)
	{
		if ((data->var = ft_strchr(rem, '\n')))
		{
			if ((rem = check_remainder(line, rem)) == NULL)
				data->error = -1;
		}
		else
		{
			if ((*line = ft_strdup(rem)) == NULL)
				data->error = -1;
			free(rem);
		}
	}
	else
	{
		if ((*line = ft_strdup("\0")) == NULL)
			data->error = -1;
	}
	data->rem = rem;
}

static void		update_line(char **line, char *buff, char *rem, t_data *data)
{
	char		*temp;
	int			count;

	count = 0;
	buff[data->len] = '\0';
	if ((data->var = ft_strchr(buff, '\n')))
	{
		while (buff[count] != '\n')
			count++;
		buff[count] = '\0';
		if ((rem = ft_strdup(&buff[++count])) == NULL)
			data->error = -1;
	}
	temp = *line;
	if ((*line = ft_strjoin(*line, buff)) == NULL)
		data->error = -1;
	data->rem = rem;
	free(temp);
}

int				get_next_line(int fd, char **line)
{
	t_data		*data;
	char		buff[BUFFER_SIZE + 1];
	static char	*rem;

	data = (t_data*)malloc(sizeof(t_data));
	data->rem = rem;
	data->var = NULL;
	data->len = 1;
	data->error = 0;
	init_line(line, rem, data);
	if (data->error == -1)
		return (-1);
	while (!(data->var) && (data->len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		update_line(line, buff, rem, data);
		if (data->error == -1)
			return (-1);
	}
	rem = data->rem;
	free(data);
	if (data->len > 0)
		return (1);
	else if (data->len == 0)
		return (0);
	return (-1);
}
