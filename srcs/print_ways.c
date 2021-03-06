/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:37:43 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:51:13 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_num(t_list *lst)
{
	int		res;
	t_list	*tmp;

	res = 0;
	tmp = lst;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

char	**list_to_arr(t_list *lst, int num_rooms)
{
	int		i;
	t_list	*tmp;
	char	**arr;

	i = -1;
	lst = reverse_list(lst);
	arr = (char**)malloc(sizeof(char*) * (num_rooms));
	tmp = lst->next;
	while (tmp)
	{
		arr[++i] = ((t_room*)tmp->content)->name;
		tmp = tmp->next;
	}
	arr[++i] = 0;
	return (arr);
}

void	print_ways(t_s *s, t_list *way, int num_rooms)
{
	int		i;
	int		j;
	char	**rooms;

	i = 0;
	rooms = list_to_arr(way, num_rooms);
	while (++i <= num_rooms + s->map.ant - 1)
	{
		j = -1;
		while (++j < s->map.ant)
		{
			if (i - j < num_rooms && i - j > 0)
			{
				ft_putchar('L');
				ft_putnbr(j + 1);
				ft_putchar('-');
				ft_putstr(rooms[i - j - 1]);
				ft_putchar((j == i - 1 || j == s->map.ant - 1) ? '\n' : ' ');
			}
		}
	}
	ft_memdel((void**)&rooms);
}
