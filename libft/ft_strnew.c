/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:11:18 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/04 16:22:36 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t			i;
	unsigned char	*fresh;

	i = 0;
	fresh = malloc(size + 1);
	if (!fresh)
		return (0);
	while (i++ < size)
		fresh[i] = '\0';
	fresh[i] = '\0';
	*fresh = 0;
	return ((char *)fresh);
}
