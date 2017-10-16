/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:57:18 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/16 14:05:05 by dmulish          ###   ########.fr       */
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
	struct s_room	*next;
	char			*name;
	int				x;
	int				y;
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
	char			*buf;
}					t_s;

void				valid_map(t_s *s);
void				error_manag(void);
void				check_rooms(t_s *s);

#endif
