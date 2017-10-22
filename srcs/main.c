/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:51:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/22 16:40:44 by dmulish          ###   ########.fr       */
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
	s->rooms_names = NULL;
}

int		main(void)
{
	t_s	s;

	init_str(&s);
	valid_map(&s);
	// print_hash(s.all_rooms);
	// ft_putchar('\n');
	// print_list(s.all_rooms->all_index);
	print_rev_list(s.map.file);
	ft_putchar('\n');
	// ft_lstdel do not work!
	ft_lstdel(&(s.map.file), delete_tlist_node);
	// while (1);
	// dijkstra's algorithm
	return (0);
}
