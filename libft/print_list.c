/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:20:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/22 15:18:22 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putendl((char*)tmp->content);
		tmp = tmp->next;
	}
}

void	print_rev_list(t_list *lst)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	tmp = lst;
	curr = tmp;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	tmp = prev;
	print_list(tmp);
}
