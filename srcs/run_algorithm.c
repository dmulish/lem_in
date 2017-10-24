/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:02:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/24 21:15:56 by dmulish          ###   ########.fr       */
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
	while (arr[++j])
	{
		num = 0;
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
	t_list	**arr;

	i = -1;
	arr = (t_list**)ft_memalloc(sizeof(t_list*) * (size_t)s->map.num_links);
	start_way(s, arr, &i);
	search_way_to_end(s, arr, &i);
	i = -1;
	while (++i < s->map.num_links)
	{
		if (arr[i])
		{
			ft_putnbr(i);
			ft_putstr(": ");
			print_list(reverse_list(((t_room*)(arr[i]->content))->links));
		}
	}
}
