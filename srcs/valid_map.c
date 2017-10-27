/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:48:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 01:08:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ants_to_list(t_s *s)
{
	if (s->map.file == NULL)
		s->map.file = ft_lstnew((void*)s->buf, ft_strlen(s->buf) + 1);
	else
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf,
		ft_strlen(s->buf) + 1));
}

int			check_ants(t_s *s)
{
	int		res;

	res = 0;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		(!s->buf[0]) ? error_manag() : 0;
		ants_to_list(s);
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
		ft_memdel((void**)&s->buf);
		return (res);
	}
	error_manag();
	return (0);
}

void		valid_map(t_s *s)
{
	s->map.ant = check_ants(s);
	s->all_rooms = new_hash_map(0);
	check_rooms(s);
	(s->start_fl != 1 || s->end_fl != 1) ? error_manag() : 0;
	check_links(s);
	print_rev_list(s->map.file);
	ft_putchar('\n');
}
