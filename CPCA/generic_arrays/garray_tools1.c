/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garray_tools1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:25:27 by khafni            #+#    #+#             */
/*   Updated: 2021/01/27 19:27:51 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garray.h"

void			garr_set(t_array a, int index, void *obj)
{
	size_t newalc;

	newalc = (1 + 2 * index) * a->cell_size;
	if (index >= a->alloc)
	{
		a->data = memory_grow(a->data, a->alloc * a->cell_size, newalc);
		a->alloc = newalc;
	}
	if (index >= a->len)
		a->len = index + 1;
	memory_copy((a->data + index * a->cell_size), obj, a->cell_size);
}

void			garr_add(t_array a, void *obj)
{
	garr_set(a, a->len, obj);
}
