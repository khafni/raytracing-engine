/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garrptr_tools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:06:56 by khafni            #+#    #+#             */
/*   Updated: 2020/12/25 11:40:36 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garrptr.h"

void		arrptr_set(t_arrptr a, int index, void *obj)
{
	size_t newalc;

	newalc = (1 + 2 * index) * sizeof(void*);
	if (index >= a->alloc)
		a->data = memory_grow(a->data, a->alloc * sizeof(void*), newalc);
	if (index >= a->len)
		a->len = index + 1;
	a->data[index] = obj;
}

void		arrptr_add(t_arrptr a, void *obj)
{
	arrptr_set(a, a->len, obj);
}
