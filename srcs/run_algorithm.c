/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:02:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/25 13:37:32 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	search_way_to_end(t_s *s, t_list **arr, int *i)
{
	int		j;
	int		num;
	t_list	*tmp;
	t_room	*neibr;
	t_room	*room;

	j = -1;
	while (++j <= s->map.num_links)
	{
		if (!s->end_links)
			return ;
		if (j == s->map.num_links)
			j = 0;
		num = 0;
		if (!arr[j])
			continue ;
		room = (t_room*)get_elem(s->all_rooms,
			((t_room*)(arr[j]->content))->name);
		tmp = room->links;
		while (tmp)
		{
			neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
			if (!num)
			{
				ft_lstadd(&(arr[j]), ft_lstnew((void*)neibr, sizeof(t_room)));
				dijkstra(s, neibr, arr, j);
			}
			else
			{
				arr[++(*i)] = cpy_list_without_last(arr[j]);
				ft_lstadd(&(arr[*i]), ft_lstnew((void*)neibr, sizeof(t_room)));
				dijkstra(s, neibr, arr, *i);
			}
			tmp = tmp->next;
			num++;
		}
		room->visited = 1;
	}
}

void	start_way(t_s *s, t_list **arr, int *i)
{
	t_list	*tmp;
	t_room	*neibr;

	tmp = s->map.start->links;
	while (tmp)
	{
		arr[++(*i)] = ft_lstnew((void*)s->map.start, sizeof(t_room));
		neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
		ft_lstadd(&(arr[*i]), ft_lstnew((void*)neibr, sizeof(t_room)));
		dijkstra(s, neibr, arr, 0);
		tmp = tmp->next;
	}
	s->map.start->visited = 1;
}

void	run_algorithm(t_s *s)
{
	int		i;
	t_list	*tmp;
	t_list	**arr;

	i = -1;
	s->way_to_end = new_hash_map(0);
	arr = (t_list**)ft_memalloc(sizeof(t_list*) * (size_t)s->map.num_links);
	start_way(s, arr, &i);
	search_way_to_end(s, arr, &i);
	i = -1;
	while (++i < s->map.num_links)
	{
		ft_putnbr(i);
		ft_putstr(": ");
		// tmp = reverse_list(arr[i]);
		tmp = arr[i];
		while (tmp)
		{
			ft_putstr(((t_room*)tmp->content)->name);
			ft_putstr(" -> ");
			tmp = tmp->next;
		}
		ft_putstr("NULL");
		ft_putchar('\n');
	}
}
