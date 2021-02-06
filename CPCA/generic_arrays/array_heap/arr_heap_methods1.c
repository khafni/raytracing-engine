/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_heap_methods1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:40:29 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:58:56 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_heap.h"

int		is_empty_heap(t_heap h)
{
	return (h->len == 0);
}

/*
**  to find the parent node of a given node: (n - 1) / 2
**  to find the left child node of a given node: 2n + 1
**  to find the right child node of a given node: 2n + 2
*/

int		heap_has_parent(t_heap h, int i)
{
	if (i < 0 || i >= h->len)
		return (0);
	else
		return (i > 0);
}

int		heap_get_parent_index(t_heap h, int i)
{
	if ((i < 0) || (i >= h->len) || (!heap_has_parent(h, i)))
		return (-1);
	return (i - 1) / 2;
}

int		heap_get_left_child_index(t_heap h, int i)
{
	if (i < 0 || (i >= h->len) || (heap_count_children(h, i) < 1))
		return (-1);
	return (2 * i + 1);
}

int		heap_get_right_child_index(t_heap h, int i)
{
	if (i < 0 || (i >= h->len) || (heap_count_children(h, i) < 2))
		return (-1);
	return (2 * i + 2);
}
