/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:24:23 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/17 21:23:33 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**valid_links(char *str)
{
	int		i;
	size_t	sum;
	char	**arr;

	i = -1;
	sum = 0;
	arr = ft_strsplit(str, '-');
	while (arr[++i])
		sum += ft_strlen(arr[i]);
	if (i != 2 || (sum + 1 != ft_strlen(str)))
		error_manag();
	return (arr);
}

void	put_links_in_hash(t_s *s, char **arr)
{
	t_list	*tmp;

	if ((get_elem(s->all_rooms, arr[0]) == NULL) ||
		(get_elem(s->all_rooms, arr[1]) == NULL))
		error_manag();
	// ?
	tmp = ft_lstnew((void*)&arr[1], ft_strlen(arr[1]) + 1);
	ft_lstadd(&tmp, get_elem(s->links, arr[0]));
	add_elem(s->links, arr[0], (void*)tmp, sizeof(t_list*));
}

void	check_links(t_s *s)
{
	char	**arr;

	while (get_next_line(0, &(s->buf)) > 0)
	{
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start") || !ft_strcmp(s->buf, "##end"))
				error_manag();
			ft_memdel((void**)&s->buf);
			continue ;
		}
		arr = valid_links(s->buf);
		put_links_in_hash(s, arr);
	}
}
