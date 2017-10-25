/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:33:02 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/25 14:06:21 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	search_and_delete_way(t_s *s, t_room *neibr, t_list **arr, int j)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (++i < s->map.num_links)
	{
		tmp = arr[i];
		if (tmp == NULL || i == j)
			continue ;
		if (!ft_strcmp(((t_room*)(tmp->content))->name, neibr->name))
			ft_lstdel((void*)&tmp, delete_tlist_node);
	}
}

// here! only arr[j]->next stay; need to find all arr[j]

void	dijkstra(t_s *s, t_room *neibr, t_list **arr, int j)
{
	t_list	**room;
	double	tmp;
	double	curr_dist;

	room = arr;
	if (neibr->visited)
		return ;
	tmp = pow((double)(((t_room*)(room[j]->next->content))->x - neibr->x), 2.) +
		pow((double)(((t_room*)(room[j]->next->content))->y - neibr->y), 2.);
	curr_dist = ((t_room*)(room[j]->next->content))->min_dist + sqrt(tmp);
	if (!ft_strcmp(neibr->name, s->map.end->name))
	{
		add_elem(s->way_to_end, ft_itoa(j), (void*)&curr_dist, sizeof(int));
		s->end_links--;
	}
	else
	{
		if (neibr->min_dist > curr_dist)
		{
			if (neibr->min_dist < INF)
			search_and_delete_way(s, neibr, room, j);
			neibr->min_dist = curr_dist;
		}
		else
		ft_lstdel((void*)room[j], delete_tlist_node);
	}
}
