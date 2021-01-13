/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:05:21 by kdelport          #+#    #+#             */
/*   Updated: 2021/01/13 13:30:09 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t size);
int			contain_newline(char *str);
char		*ft_strjoin(char const *s1, char const *s2, int *error);
int			get_line_read(char *str, char **line, int *index);

#endif
