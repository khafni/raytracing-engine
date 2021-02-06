/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_heap_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:16:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:53:54 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_heap.h"

t_heap	heap_create(int alloc, t_comp cmp_fun, t_destruct des, int cell_size)
{
	t_array h;

	h = empty_garr(alloc, des, cell_size);
	h->obj_cmp = cmp_fun;
	return (h);
}

t_heap	standard_heap_create(t_comp cmp, t_destruct des, int cell_size)
{
	return (heap_create(HEAP_DEFAULT_ALLOC, cmp, des, cell_size));
}

void	heap_destroy(t_heap h)
{
	garr_destroy(h);
}
