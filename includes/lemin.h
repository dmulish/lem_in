/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:57:18 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/18 20:49:35 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
}					t_room;

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	t_list			*file;
	int				ant;
}					t_map;

typedef struct		s_s
{
	t_map			map;
	t_list			*rooms_names;
	t_hash			*all_rooms;
	t_hash			*links;
	char			*buf;
	int				end_fl;
	int				start_fl;
}					t_s;

void				error_manag(void);
void				valid_map(t_s *s);
void				check_links(t_s *s);
void				check_rooms(t_s *s);

#endif
