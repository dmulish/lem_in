/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:57:18 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 01:05:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# define INF 4000000000.

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_room
{
	t_list			*links;
	char			*name;
	double			min_dist;
	int				visited;
	int				y;
	int				x;
}					t_room;

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	t_list			*file;
	int				ant;
	int				num_links;
}					t_map;

typedef struct		s_s
{
	t_list			*rooms_names;
	t_hash			*all_rooms;
	t_hash			*way_to_end;
	t_map			map;
	char			*buf;
	int				num;
	int				end_fl;
	int				start_fl;
}					t_s;

int					room_num(t_list *lst);
int					num_in_arr(t_list **arr, int size);

void				error_manag(void);
void				valid_map(t_s *s);
void				check_links(t_s *s);
void				check_rooms(t_s *s);
void				run_algorithm(t_s *s);
void				do_it(t_s *s, t_list **arr, int *j, int *i);
void				print_ways(t_s *s, t_list *way, int num_rooms);
void				search_way_to_end(t_s *s, t_list **arr, int *i);
void				dijkstra(t_s *s, t_room *neibr, t_list **arr, int j);

#endif
