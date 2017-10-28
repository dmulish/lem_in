/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_way_to_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:10:53 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 03:22:04 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		search_way_to_end(t_s *s, t_list **arr, int *i)
{
	int		j;
	int		arr_num;

	j = -1;
	arr_num = 0;
	while (++j <= s->map.num_links)
	{
		if (j == s->map.num_links)
			j = 0;
		if (!arr[j])
			continue ;
		else
		{
			if (!ft_strcmp(((t_room*)arr[j]->content)->name, s->map.end->name))
				arr_num++;
		}
		if (arr_num == num_in_arr(arr, s->map.num_links))
			return ;
		s->num = 0;
		do_it(s, arr, &j, i);
	}
}
