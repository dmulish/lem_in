/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:37:42 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/17 20:42:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	valid_room(char **arr, char *str)
{
	int		i;
	int		j;
	size_t	sum;

	i = -1;
	sum = 0;
	while (arr[++i])
		sum += ft_strlen(arr[i]);
	if (i != 3 || (sum + 2 != ft_strlen(str)) || arr[0][0] == 'L')
		error_manag();
	i = 0;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (j == 0 && arr[i][j] == '-')
				continue ;
			if (!ft_isdigit(arr[i][j]))
				error_manag();
		}
	}
}

void	new_room(t_s *s, int start, int end)
{
	int		i;
	char	**arr;
	t_room	*new_room;

	i = -1;
	if (char_num(s->buf, ' ') != 2)
		error_manag();
	arr = ft_strsplit(s->buf, ' ');
	valid_room(arr, s->buf);
	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->name = ft_strdup(arr[0]);
	new_room->x = ft_atoi(arr[1]);
	new_room->y = ft_atoi(arr[2]);
	(get_elem(s->all_rooms, arr[0]) == NULL) ? add_elem(s->all_rooms, arr[0],
		(void*)&new_room, sizeof(t_room)) : error_manag();
	if (start == 1 && s->start_fl == 0)
	{
		s->map.start = new_room;
		s->start_fl++;
	}
	else if (end == 1 && s->end_fl == 0)
	{
		s->map.end = new_room;
		s->end_fl++;
	}
}

void	check_rooms(t_s *s)
{
	int	end;
	int	start;

	end = 0;
	start = 0;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start"))
				start++;
			else if (!ft_strcmp(s->buf, "##end"))
				end++;
			ft_memdel((void**)&s->buf);
			continue ;
		}
		(start > 1 || end > 1) ? error_manag() : 0;
		new_room(s, start, end);
		ft_memdel((void**)&s->buf);
	}
	error_manag();
}
