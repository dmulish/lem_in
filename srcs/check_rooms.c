/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:37:42 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/16 20:54:56 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*new_room(char *str)
{
	int		i;
	char	**arr;

	arr = ft_strsplit(str, ' ');
}

void	check_rooms(t_s *s)
{
	int		fl;
	t_room	*room;

	fl = 0;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start"))
				fl = 1;
			else if (!ft_strcmp(s->buf, "##end"))
				fl = 2;
			else
			{
				ft_memdel((void**)&s->buf);
				continue ;
			}
		}
		// флаг не здесь
		if (fl == 1)
		{
			s->map.start = room;
			fl = 0;
		}
		if (fl == 2)
		{
			s->map.end = room;
			fl = 0;
		}
		ft_memdel((void**)&s->buf);
	}
	error_manag();
}
