/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:02:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/23 20:52:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	dijkstra(t_room *room, t_room *neibr)
{
	double	tmp;
	double	curr_dist;

	if (neibr->visited)
		return ;
	tmp = pow((double)(room->x - neibr->x), 2.) +
		pow((double)(room->y - neibr->y), 2.);
	curr_dist = room->min_dist + sqrt(tmp);
	if (neibr->min_dist > curr_dist)
		neibr->min_dist = curr_dist;
}

void	start_way(t_s *s, t_list **arr, int *i)
{
	t_list	*tmp;
	t_room	*neibr;
	t_room	*room;

	room = s->map.start;
	tmp = room->links;
	while (tmp)
	{
		arr[++(*i)] = ft_lstnew((void*)room, sizeof(t_room));
		neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
		ft_lstadd(&(arr[*i]), ft_lstnew((void*)neibr, sizeof(t_room)));
		dijkstra(room, neibr);
		tmp = tmp->next;
	}
	room->visited = 1;
}

void	search_way_to_end(t_s *s, t_list **arr, int *i)
{
	int		j;
	t_list	*tmp;
	t_room	*neibr;
	t_room	*room;

	(void)i;
	j = -1;
	while (arr[++j])
	{
		room = (t_room*)get_elem(s->all_rooms, (char*)arr[j]->content);
		tmp = room->links;
		while (tmp)
		{
			neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
		}
		room->visited = 1;
	}
}

void	run_algorithm(t_s *s)
{
	int		i;
	t_list	*arr[s->map.num_links];

	i = -1;
	while (++i < s->map.num_links)
		arr[i] = NULL;
	i = -1;
	start_way(s, arr, &i);
	search_way_to_end(s, arr, &i);
}
