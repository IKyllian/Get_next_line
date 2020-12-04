/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:09:46 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/04 10:14:17 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*get_next_save(char *str)
{
	size_t	len_str;
	size_t	i;
	char	*new_str;

	i = 0;
	len_str = 0;
	while (str[len_str] && str[len_str] != '\n')
		len_str++;
	if (!str[len_str])
	{
		free(str);
		return (NULL);
	}
	len_str++;
	if (!(new_str = malloc(sizeof(char) * (ft_strlen(str) - len_str + 1))))
		return (NULL);
	while (str[len_str + i])
	{
		new_str[i] = str[len_str + i];
		i++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

struct s_list	*ft_lstnew(int fd)
{
	struct s_list *elem;

	if (!(elem = (struct s_list *)malloc(sizeof(*elem))))
		return (NULL);
	elem->final_str = NULL;
	elem->fd = fd;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

struct s_list	*ft_search_list(struct s_list *lst, int fd)
{
	struct s_list *list;
	struct s_list *newlist;

	list = lst;
	newlist = NULL;
	while (list->prev)
		list = list->prev;
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd == fd)
		return (list);
	else
	{
		newlist = ft_lstnew(fd);
		list->next = newlist;
		list->next->prev = list;
		list = list->next;
		return (list);
	}
}

struct s_list	*ft_check_list(struct s_list *lst, int fd)
{
	struct s_list *list;

	list = lst;
	if (!list)
		list = ft_lstnew(fd);
	else if (list->fd != fd)
		list = ft_search_list(list, fd);
	return (list);
}

int				get_next_line(int fd, char **line)
{
	static struct s_list	*list;
	int						ret;
	char					*buffer;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
		(!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	ret = 1;
	list = ft_check_list(list, fd);
	while (ret && (!contain_newline(list->final_str)))
	{
		if ((ret = read(list->fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret] = 0;
		list->final_str = ft_strjoin(list->final_str, buffer);
	}
	*line = get_line_read(list->final_str);
	list->final_str = get_next_save(list->final_str);
	free(buffer);
	if (!ret)
		return (0);
	return (1);
}
