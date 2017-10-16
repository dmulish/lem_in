/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:48:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/16 14:06:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_ants(t_s *s)
{
	int	res;

	res = 0;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (ft_strlen(s->buf) > 1 && s->buf[1] == '#')
				error_manag();
			ft_memdel((void**)&s->buf);
			continue ;
		}
		res = ft_atoi(s->buf);
		if (!res || (ft_digitnum(res) != (int)ft_strlen(s->buf)))
			error_manag();
		ft_memdel((void**)&s->buf);
		return (res);
	}
	error_manag();
	return (0);
}

void	valid_map(t_s *s)
{
	s->map.ant = check_ants(s);
	check_rooms(s);
}
