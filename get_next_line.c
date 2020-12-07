/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:06:22 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/07 10:58:49 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_save(char *str)
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

void	free_elems(char *buffer, char *final_str)
{
	if (final_str)
		free(final_str);
	free(buffer);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buffer;
	static char *final_str;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
		(!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	ret = 1;
	while (ret && (!contain_newline(final_str)))
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free_elems(buffer, final_str);
			return (-1);
		}
		buffer[ret] = 0;
		final_str = ft_strjoin(final_str, buffer);
	}
	*line = get_line_read(final_str);
	final_str = get_next_save(final_str);
	free(buffer);
	if (!ret)
		return (0);
	return (1);
}
