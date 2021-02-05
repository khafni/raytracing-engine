/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garray_tools1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:25:27 by khafni            #+#    #+#             */
/*   Updated: 2020/12/25 11:33:36 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garray.h"

void			garr_set(t_array a, int index, void *obj)
{
	size_t newalc;

	newalc = (1 + 2 * index) * a->cell_size;
	if (index >= a->alloc)
		a->data = memory_grow(a->data, a->alloc * a->cell_size, newalc);
	if (index >= a->len)
		a->len = index + 1;
	memory_copy((a->data + index * a->cell_size), obj, a->cell_size);
}

void			garr_add(t_array a, void *obj)
{
	garr_set(a, a->len, obj);
}
