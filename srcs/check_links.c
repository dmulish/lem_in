/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:24:23 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/18 18:23:23 by dmulish          ###   ########.fr       */
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
	if (i != 2 || (sum + 1 != ft_strlen(str)) || !ft_strcmp(arr[0], arr[1]))
		error_manag();
	return (arr);
}

void	put_links_in_hash(t_s *s, char **arr)
{
	if ((get_elem(s->all_rooms, arr[0]) == NULL) ||
		(get_elem(s->all_rooms, arr[1]) == NULL))
		error_manag();
	add_elem(s->links, arr[0], (void*)arr[1], ft_strlen(arr[1]));
	ft_free_arr(arr);
}

void	check_links(t_s *s)
{
	char	*tmp;
	char	**arr;

	arr = valid_links(s->buf);
	put_links_in_hash(s, arr);
	ft_memdel((void**)&s->buf);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		(!s->buf[0]) ? error_manag() : 0;
		tmp = ft_strdup(s->buf);
		ft_lstadd(&s->map.file, ft_lstnew((void*)tmp, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start") || !ft_strcmp(s->buf, "##end"))
				error_manag();
			ft_memdel((void**)&s->buf);
			continue ;
		}
		arr = valid_links(s->buf);
		put_links_in_hash(s, arr);
		ft_memdel((void**)&s->buf);
		ft_memdel((void**)&tmp);
	}
}
