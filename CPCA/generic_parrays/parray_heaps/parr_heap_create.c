/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_heap_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:16:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:33:32 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parr_heap.h"

t_pheap	pheap_create(int alloc, t_compar cmp_fun, t_destructor des)
{
	t_arrptr h;

	h = empty_arrptr_create_size(alloc, des);
	h->obj_cmp = cmp_fun;
	return (h);
}

t_pheap	standard_pheap_create(t_compar cmp, t_destructor des)
{
	return (pheap_create(HEAP_DEFAULT_ALLOC, cmp, des));
}

void	pheap_destroy(t_pheap h)
{
	arrptr_destroy(h);
}
