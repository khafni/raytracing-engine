/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_heap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:03:31 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:34:18 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parr_heap.h"
#include <strings.h>

void		pheap_sort(t_arrptr arr, t_compar cmp)
{
	t_pheap	h;
	int		i;

	h = standard_pheap_create(cmp, arr->obj_des);
	i = 0;
	while (i < arr->len)
	{
		pheap_add(h, arrptr_get(arr, i));
		i++;
	}
	i = 0;
	while (i < arr->len)
	{
		arrptr_set(arr, i, pheap_get_head_value(h));
		pheap_delete_head_value(h);
		i++;
	}
	pheap_destroy(h);
}
