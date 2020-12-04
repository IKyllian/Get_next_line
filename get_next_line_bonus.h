/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:11:16 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/04 10:06:32 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	char			*final_str;
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dst, const void *src, size_t size);
int					contain_newline(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_line_read(char *str);

#endif
