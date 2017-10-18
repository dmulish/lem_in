/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:39:28 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/18 18:52:30 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	delete_tlist_node(void *data, size_t data_size)
{
	(void)data_size;
	ft_memdel(&((t_list*)data)->content);
	ft_memdel(&data);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*current;

	tmp = *alst;
	current = *alst;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		del(current->content, current->content_size);
		free(current);
	}
	*alst = NULL;
}
