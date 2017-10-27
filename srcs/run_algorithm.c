/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:02:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:46:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		start_way(t_s *s, t_list **arr, int *i)
{
	t_list	*tmp;
	t_room	*neibr;
	t_list	*neibr_copy;

	tmp = s->map.start->links;
	if (!tmp)
		error_manag();
	while (tmp)
	{
		arr[++(*i)] = ft_lstnew((void*)s->map.start, sizeof(t_room));
		neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
		neibr_copy = ft_lstnew((void*)neibr, sizeof(t_room));
		ft_lstadd(&(arr[*i]), neibr_copy);
		dijkstra(s, (t_room*)neibr_copy->content, arr, *i);
		tmp = tmp->next;
	}
}

static void	check_if_end(t_s *s, t_list **arr)
{
	int		i;
	int		fl;
	t_list	*tmp;

	i = -1;
	while (++i < s->map.num_links)
	{
		fl = 0;
		if (!(tmp = arr[i]))
			continue ;
		while (tmp)
		{
			if (!ft_strcmp(((t_room*)tmp->content)->name, s->map.end->name))
			{
				fl = 1;
				break ;
			}
			tmp = tmp->next;
		}
		if (!fl)
		{
			ft_lstdel((void*)arr[i], delete_tlist_node);
			arr[i] = NULL;
		}
	}
}


int			find_ways(t_s *s)
{
	int		i;
	int		index;
	int		res;
	double	dist;
	double	min;

	i = -1;
	min = INF;
	dist = 0.;
	while (++i < (int)s->way_to_end->bucket_num)
	{
		if (!s->way_to_end->map[i])
			continue ;
		index = ft_atoi(((t_node*)s->way_to_end->map[i]->content)->key);
		dist = *(double*)((t_node*)s->way_to_end->map[i]->content)->data;
		if (dist < min)
		{
			res = index;
			min = dist;
		}
	}
	return (res);
}

void		run_algorithm(t_s *s)
{
	int		i;
	int		my_way;
	t_list	**arr;

	i = -1;
	s->way_to_end = new_hash_map(0);
	arr = (t_list**)ft_memalloc(sizeof(t_list*) * (size_t)s->map.num_links);
	start_way(s, arr, &i);
	if (arr[0] == NULL)
		error_manag();
	search_way_to_end(s, arr, &i);
	check_if_end(s, arr);
	my_way = find_ways(s);
	print_ways(s, arr[my_way], room_num(arr[my_way]));
	clean_up(s, arr);
}
