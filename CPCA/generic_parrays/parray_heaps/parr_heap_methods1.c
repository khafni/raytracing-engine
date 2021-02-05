/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_heap_methods1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:40:29 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:33:41 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parr_heap.h"

int		is_empty_pheap(t_pheap h)
{
	return (h->len == 0);
}

/*
**  to find the parent node of a given node: (n - 1) / 2
**  to find the left child node of a given node: 2n + 1
**  to find the right child node of a given node: 2n + 2
*/

int		pheap_has_parent(t_pheap h, int i)
{
	if (i < 0 || i >= h->len)
		return (0);
	else
		return (i > 0);
}

int		pheap_get_parent_index(t_pheap h, int i)
{
	if ((i < 0) || (i >= h->len) || (!pheap_has_parent(h, i)))
		return (-1);
	return (i - 1) / 2;
}

int		pheap_get_left_child_index(t_pheap h, int i)
{
	if (i < 0 || (i >= h->len) || (pheap_count_children(h, i) < 1))
		return (-1);
	return (2 * i + 1);
}

int		pheap_get_right_child_index(t_pheap h, int i)
{
	if (i < 0 || (i >= h->len) || (pheap_count_children(h, i) < 2))
		return (-1);
	return (2 * i + 2);
}
