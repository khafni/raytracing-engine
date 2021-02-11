/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:51:06 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 10:36:03 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (dst == src)
		return (dst);
	if (dst > src && dst < src + len)
	{
		while (len-- > 0)
			d[len] = s[len];
		return (dst);
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
}
