/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:10:17 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/03 16:35:52 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char *dest;
	char *source;

	dest = (char *)dst;
	source = (char *)src;
	if (!source && !dest)
		return (NULL);
	while (size--)
		*dest++ = *source++;
	return (dst);
}

int		contain_newline(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	x = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (i + x + 1))))
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, x);
	str[i + x] = 0;
	free((void *)s1);
	return (str);
}

char	*get_line_read(char *str)
{
	int i;
	char *new_str;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(new_str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}