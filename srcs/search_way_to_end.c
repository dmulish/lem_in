/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_way_to_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:10:53 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/26 22:06:02 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		compare_it(t_s *s, t_list *links)
{
	t_list	*tmp;

	tmp = links;
	while (tmp)
	{
		if (!ft_strcmp((char*)tmp->content, s->map.end->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		num_in_arr(t_list **arr, int size)
{
	int		i;
	int		res;

	i = -1;
	res = 0;
	while (++i < size)
	{
		if (!arr[i])
			continue ;
		res++;
	}
	return (res);
}

void	search_way_to_end(t_s *s, t_list **arr, int *i)
{
	int		j;
	int		arr_num;
	int		num;
	t_list	*tmp;
	t_room	*neibr;
	t_room	*room;

	j = -1;
	arr_num = 0;
	while (++j <= s->map.num_links)
	{
		if (j == s->map.num_links)
			j = 0;
		num = 0;
		if (!arr[j])
			continue ;
		else
		{
			if (!ft_strcmp(((t_room*)arr[j]->content)->name, s->map.end->name))
				arr_num++;
		}
		if (arr_num == num_in_arr(arr, s->map.num_links))
			return ;
		room = (t_room*)get_elem(s->all_rooms,
			((t_room*)(arr[j]->content))->name);
		tmp = room->links;
		while (tmp && (!room->visited ||
			(room->visited && compare_it(s, room->links))))
		{
			neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
			if (neibr->visited || !ft_strcmp(neibr->name, s->map.start->name))
			{
				tmp = tmp->next;
				continue ;
			}
			if (!num)
			{
				ft_lstadd(&(arr[j]), ft_lstnew((void*)neibr, sizeof(t_room)));
				dijkstra(s, neibr, arr, j);
			}
			else
			{
				arr[++(*i)] = cpy_list_without_last(arr[j]); //SEGFAULT!!! arr[j]
				ft_lstadd(&(arr[*i]), ft_lstnew((void*)neibr, sizeof(t_room)));
				dijkstra(s, neibr, arr, *i);
			}
			tmp = tmp->next;
			num++;
		}
		room->visited = 1;
	}
}
