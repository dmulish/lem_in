/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:37:42 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/16 14:06:17 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_rooms(t_s *s)
{
	while (get_next_line(0, &(s->buf)) > 0)
	{
		ft_lstadd(&s->map.file, ft_lstnew((void*)s->buf, ft_strlen(s->buf)));
		if (s->buf[0] == '#')
		{
			if (!ft_strcmp(s->buf, "##start"))
			{
			}
			else if (!ft_strcmp(s->buf, "##end"))
			{
			}
			else
			{
				ft_memdel((void**)&s->buf);
				continue ;
			}
		}
	}
	error_manag();
}
