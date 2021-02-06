/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_heap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:03:31 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 16:59:14 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_heap.h"
#include <strings.h>

void		heap_sort(t_array arr, t_comp cmp)
{
	t_heap	h;
	int		i;

	h = standard_heap_create(cmp, arr->obj_des, arr->cell_size);
	i = 0;
	while (i < arr->len)
	{
		heap_add(h, garr_get(arr, i));
		i++;
	}
	i = 0;
	while (i < arr->len)
	{
		garr_set(arr, i, heap_get_head_value(h));
		heap_delete_head_value(h);
		i++;
	}
	heap_destroy(h);
}
