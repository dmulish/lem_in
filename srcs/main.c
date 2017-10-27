/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:51:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 01:08:32 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error_manag(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	init_str(t_s *s)
{
	s->buf = 0;
	s->end_fl = 0;
	s->start_fl = 0;
	s->map.file = NULL;
	s->map.num_links = 0;
	s->rooms_names = NULL;
}

int		main(void)
{
	t_s	s;

	init_str(&s);
	valid_map(&s);
	ft_lstdel(&(s.map.file), delete_tlist_node);
	run_algorithm(&s);
	while(1);
	return (0);
}
