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
	if ((data->var = ft_strchr(data->content, '\n')))
	{
		*data->var = '\0';
		if (((*line) = ft_strdup(data->content)) == NULL)
			return (-1);
		data->count = ft_strlen(data->content);
		if ((data->temp = ft_strdup(&(data->content[++(data->count)]))) == NULL)
		{
			free(*line);
			data->err = -1;
		}
		free(data->content);
		data->content = data->temp;
	}
	else
	{
		if ((*line = ft_strdup(data->content)) == NULL)
			data->err = -1;
		free(data->content);
		data->content = NULL;
	}
	return (data->err);
}

static int			update_line(char **line, char *buff, t_list *data)
{
	buff[data->len] = '\0';
	if ((data->var = ft_strchr(buff, '\n')))
	{
		*(data->var) = '\0';
		data->count = ft_strlen(buff);
		if ((data->content = ft_strdup(&buff[++(data->count)])) == NULL)
			return (data->err = -1);
	}
	data->temp = *line;
	if ((*line = ft_strjoin(*line, buff)) == NULL)
	{
		free(data->content);
		data->err = -1;
	}
	free(data->temp);
	return (data->err = 0);
}

static int			prog_logic(char **line, int fd, t_list *data)
{
	char buff[BUFFER_SIZE + 1];

	data->var = NULL;
	data->temp = NULL;
	if (BUFFER_SIZE < 0)
	{
		data->len = -1;
		return (0);
	}
	if (data->content)
	{
		if ((data->err = init_line(line, data)) == -1)
			return (-1);
	}
	else
	{
		if ((*line = ft_strdup("\0")) == NULL)
			return (-1);
	}
	while (!(data->var) && (data->len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if ((data->err = update_line(line, buff, data)) == -1)
			return (-1);
	}
	return (0);
}

static int			data_init(int fd, t_list **head, t_list **curr)
{
	if (!(*head))
	{
		if ((*head = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (-1);
		*(*head) = (t_list) { NULL, NULL, NULL, fd, 1, 0, 0, NULL };
		*curr = *head;
	}
	else
	{
		*curr = *head;
		while ((*curr)->next != NULL && (*curr)->fd != fd)
			*curr = (*curr)->next;
		if ((*curr)->next == NULL && (*curr)->fd != fd)
		{
			if (((*curr)->next = (t_list*)malloc(sizeof(t_list))) == NULL)
				return (-1);
			*curr = (*curr)->next;
			*(*curr) = (t_list) { NULL, NULL, NULL, fd, 1, 0, 0, NULL };
		}
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*curr;
	int				len;

	(*line) = NULL;
	if ((data_init(fd, &head, &curr)) == -1)
		return (-1);
	prog_logic(line, fd, curr);
	len = curr->len;
	if (len == 0 || len == -1)
	{
		curr = head;
		if (len == -1)
			free(*line);
		while ((curr->next != NULL && curr->len == 0)
			|| (curr->next != NULL && len == -1))
		{
			if (len == -1 && curr->content != NULL)
				free(curr->content);
			curr = curr->next;
		}
		if ((curr->next == NULL && curr->len == 0) || len == -1)
			ft_lstclear(&head, NULL);
	}
	return (len > 1 ? 1 : len);
}
