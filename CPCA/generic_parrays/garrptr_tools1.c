/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garrptr_tools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:06:56 by khafni            #+#    #+#             */
/*   Updated: 2021/01/27 19:28:53 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garrptr.h"

void		arrptr_set(t_arrptr a, int index, void *obj)
{
	size_t newalc;

	newalc = (1 + 2 * index) * sizeof(void*);
	if (index >= a->alloc)
	{
		a->data = memory_grow(a->data, a->alloc * sizeof(void*), newalc);
		a->alloc = newalc;
	}
	if (index >= a->len)
		a->len = index + 1;
	a->data[index] = obj;
}

void		arrptr_add(t_arrptr a, void *obj)
{
	arrptr_set(a, a->len, obj);
}
