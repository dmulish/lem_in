/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:33:02 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/24 14:42:50 by dmulish          ###   ########.fr       */
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

void	dijkstra(t_s *s, t_room *neibr, t_list **arr, int j)
{
	double	tmp;
	double	curr_dist;

	if (neibr->visited)
		return ;
	tmp = pow((double)(s->map.start->x - neibr->x), 2.) +
		pow((double)(s->map.start->y - neibr->y), 2.);
	curr_dist = s->map.start->min_dist + sqrt(tmp);
	if (neibr->min_dist > curr_dist)
	{
		if (neibr->min_dist < INF)
			search_and_delete_way(s, neibr, arr, j);
		neibr->min_dist = curr_dist;
	}
	else
		ft_lstdel((void*)arr[j], delete_tlist_node);
}
