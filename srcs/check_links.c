/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:24:23 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:45:58 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	compare_links(t_list *links, char *str)
{
	t_list	*tmp;

	tmp = links;
	while (tmp)
	{
		if (!ft_strcmp((char*)tmp->content, str))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static char	**valid_links(char *str)
{
	int		i;
	size_t	sum;
	char	**arr;

	i = -1;
	sum = 0;
	arr = ft_strsplit(str, '-');
	while (arr[++i])
		sum += ft_strlen(arr[i]);
	if (i != 2 || (sum + 1 != ft_strlen(str)) || !ft_strcmp(arr[0], arr[1]))
		error_manag();
	return (arr);
}

static void	do_it1(t_room *room, char *str)
{
	if (room->links == NULL)
		room->links = ft_lstnew((void*)str, ft_strlen(str) + 1);
	else
	{
		if (!compare_links(room->links, str))
			ft_lstadd(&(room->links), ft_lstnew((void*)str,
			ft_strlen(str) + 1));
	}
}

static void	put_links_in_hash(t_s *s)
{
	char	**arr;
	t_room	*room1;
	t_room	*room2;

	arr = valid_links(s->buf);
	room1 = (t_room*)get_elem(s->all_rooms, arr[0]);
	room2 = (t_room*)get_elem(s->all_rooms, arr[1]);
	if (room1 == NULL || room2 == NULL)
		error_manag();
	do_it1(room1, arr[1]);
	do_it1(room2, arr[0]);
	s->map.num_links++;
	ft_free_arr(arr);
	ft_memdel((void**)&s->buf);
}

void		check_links(t_s *s)
{
	put_links_in_hash(s);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		(!s->buf[0]) ? error_manag() : 0;
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf,
			ft_strlen(s->buf) + 1));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start") || !ft_strcmp(s->buf, "##end"))
				error_manag();
			ft_memdel((void**)&s->buf);
			continue ;
		}
		put_links_in_hash(s);
	}
	ft_memdel((void**)&s->buf);
	s->map.start->links = ((t_room*)(get_elem(s->all_rooms,
		s->map.start->name)))->links;
	s->map.end->links = ((t_room*)(get_elem(s->all_rooms,
		s->map.end->name)))->links;
}
