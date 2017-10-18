/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:48:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/18 21:22:51 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_ants(t_s *s)
{
	int		res;
	char	*tmp;

	res = 0;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		tmp = ft_strdup(s->buf);
		(!s->buf[0]) ? error_manag() : 0;
		ft_lstadd(&s->map.file, ft_lstnew((void*)tmp, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start") || !ft_strcmp(s->buf, "##end"))
				error_manag();
			ft_memdel((void**)&s->buf);
			continue ;
		}
		res = ft_atoi(s->buf);
		if (!res || (ft_digitnum(res) != (int)ft_strlen(s->buf)))
			error_manag();
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&s->buf);
		return (res);
	}
	error_manag();
	return (0);
}

void	check_same_coord(t_s *s)
{
	void	*p1;
	void	*p2;
	t_list	*tmp;
	t_list	*cpy_room;

	cpy_room = s->rooms_names;
	while (cpy_room)
	{
		tmp = cpy_room->next;
		while (tmp)
		{
			p1 = get_elem(s->all_rooms, (char*)((cpy_room)->content));
			p2 = get_elem(s->all_rooms, (char*)((tmp)->content));
			if (!p1 || !p2 || !ft_memcmp(p1, p2, sizeof(int) * 2))
				error_manag();
			tmp = tmp->next;
		}
		cpy_room = tmp;
	}
}

void	valid_map(t_s *s)
{
	s->map.ant = check_ants(s);
	s->all_rooms = new_hash_map(0);
	check_rooms(s);
	(s->start_fl != 1 || s->end_fl != 1) ? error_manag() : 0;
	s->links = new_hash_map(0);
	check_links(s);
	check_same_coord(s);
}
