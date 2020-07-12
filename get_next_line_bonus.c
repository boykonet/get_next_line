/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarina <gkarina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:35:24 by gkarina           #+#    #+#             */
/*   Updated: 2020/07/10 22:35:24 by gkarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int			init_line(char **line, t_list *data)
{
	if ((data->var = ft_strchr(data->rem, '\n')))
	{
		data->count = 0;
		while (data->rem[data->count] != '\n')
			data->count++;
		if (((*line) = (char*)malloc(sizeof(char) * (data->count + 1))) == NULL)
			return (data->err = -1);
		ft_strlcpy(*line, data->rem, ++(data->count));
		(*line)[--(data->count)] = '\0';
		if ((data->temp = ft_strdup(&(data->rem[++(data->count)]))) == NULL)
		{
			free(*line);
			return (data->err = -1);
		}
		free(data->rem);
		data->rem = data->temp;
	}
	else
	{
		if ((*line = ft_strdup(data->rem)) == NULL)
			data->err = -1;
		free(data->rem);
	}
	return (data->err);
}

static int			update_line(char **line, char *buff, t_list *data)
{
	buff[data->len] = '\0';
	if ((data->var = ft_strchr(buff, '\n')))
	{
		data->count = 0;
		while (buff[data->count] != '\n')
			data->count++;
		buff[data->count] = '\0';
		if ((data->rem = ft_strdup(&buff[++(data->count)])) == NULL)
			return (data->err = -1);
	}
	data->temp = *line;
	if ((*line = ft_strjoin(*line, buff)) == NULL)
	{
		free(data->rem);
		data->err = -1;
	}
	free(data->temp);
	return (data->err = 0);
}

static int			prog_logic(char **line, int fd, t_list *data)
{
	char buff[BUFFER_SIZE + 1];

	data->len = 1;
	data->var = NULL;
	if (data->rem)
	{
		init_line(line, data);
		if (data->err == -1)
			return (-1);
	}
	else
	{
		if ((*line = ft_strdup("\0")) == NULL)
			data->err = -1;
	}
	while (!(data->var) && (data->len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if ((data->err = update_line(line, buff, data)) == -1)
			return (-1);
	}
	return (0);
}

static void			data_init(int fd, t_list **head, t_list **curr, t_list **p)
{
	if (!(*head))
	{
		if ((*head = (t_list*)malloc(sizeof(t_list))) == NULL)
			return ;
		*curr = *head;
		(*curr)->next = NULL;
	}
	else
	{
		*curr = *head;
		while ((*curr)->next != NULL && (*curr)->fd != fd)
		{
			*p = *curr;
			*curr = (*curr)->next;
		}
		if ((*curr)->next == NULL && (*curr)->fd != fd)
		{
			if (((*curr)->next = (t_list*)malloc(sizeof(t_list))) == NULL)
				return ;
			*curr = (*curr)->next;
			(*curr)->rem = NULL;
			(*curr)->next = NULL;
		}
	}
	(*curr)->fd = fd;
}

int					get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*curr;
	t_list			*prev;
	t_list			*next;

	prev = head;
	data_init(fd, &head, &curr, &prev);
	if ((!head) || (!curr))
		return (-1);
	next = curr->next;
	if ((prog_logic(line, fd, curr)) == -1)
	{
		free(curr);
		return (-1);
	}
	if (curr->len == 0)
	{
		free(curr);
		prev->next = next;
		free(*line);
	}
	return (curr->len > 1 ? 1 : curr->len);
}
