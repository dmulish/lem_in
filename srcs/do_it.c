/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:27:26 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 01:51:20 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			compare_it(t_s *s, t_list *links)
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

int			num_in_arr(t_list **arr, int size)
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

static void	func(t_s *s, t_list **arr, t_room *neibr, int *j)
{
	ft_lstadd(&(arr[*j]), ft_lstnew((void*)neibr, sizeof(t_room)));
	dijkstra(s, neibr, arr, *j);
}

static int	func1(t_s *s, t_room *neibr, t_room *r, t_list **tmp)
{
	if (neibr->visited || !ft_strcmp(r->name, s->map.end->name) ||
		!ft_strcmp(neibr->name, s->map.start->name))
	{
		*tmp = (*tmp)->next;
		return (1);
	}
	return (0);
}

void		do_it(t_s *s, t_list **arr, int *j, int *i)
{
	t_list	*tmp;
	t_room	*r;
	t_room	*neibr;

	r = (t_room*)get_elem(s->all_rooms, ((t_room*)(arr[*j]->content))->name);
	tmp = r->links;
	while (tmp && (!r->visited || (r->visited && compare_it(s, r->links))))
	{
		neibr = (t_room*)get_elem(s->all_rooms, (char*)tmp->content);
		if (func1(s, neibr, r, &tmp))
			continue ;
		if (!(s->num))
			func(s, arr, neibr, j);
		else
		{
			ft_lstdel(&arr[++(*i)], delete_tlist_node);
			arr[++(*i)] = cpy_list_without_last(arr[*j]);
			func(s, arr, neibr, i);
		}
		tmp = tmp->next;
		s->num++;
	}
	r->visited = 1;
}
