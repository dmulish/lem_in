/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:51:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/23 20:55:51 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// some trash in the end of s.map.file's strings
// search_way_to_end <- nedd to be improved
// some leaks in print_list/ft_lstdel
// same coord need to be checked
// ft_lstdel do not work (?)
// free array of t_list* !

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
	// print_hash(s.all_rooms);
	// ft_putchar('\n');
	// print_list(s.all_rooms->all_index);
	print_rev_list(s.map.file);
	ft_putchar('\n');
	ft_lstdel(&(s.map.file), delete_tlist_node);
	// run_algorithm(&s);
	return (0);
}
