/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:52:19 by khafni            #+#    #+#             */
/*   Updated: 2021/01/27 19:27:04 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tools.h"

void	*memory_copy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*s;
	char			*d;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*memory_grow(void *address, size_t old_size, size_t new_size)
{
	void *tmp;

	if ((tmp = malloc(new_size)) == NULL)
		return (NULL);
	memory_copy(tmp, address, old_size);
	free(address);
	return (tmp);
}

void	vp_swap(void **v1, void **v2)
{
	void *tmp;

	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void	memory_swap(void *a1_, void *a2_, size_t size)
{
	char	tmp;
	char	*a1;
	char	*a2;

	a1 = (char*)a1_;
	a2 = (char*)a2_;
	while (size--)
	{
		tmp = *a1;
		*a1 = *a2;
		*a2 = tmp;
		a1++;
		a2++;
	}
}
