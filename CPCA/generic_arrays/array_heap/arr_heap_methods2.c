/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_heap_methods2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:46:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/29 15:20:53 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_heap.h"

void	*heap_get_head_value(t_heap h)
{
	return (garr_get(h, 0));
}

int		heap_count_children(t_heap h, int i)
{
	int fg;

	fg = 2 * i + 1;
	if (fg >= h->len)
		return (0);
	else if (fg + 1 >= h->len)
		return (1);
	else
		return (2);
}

int		heap_get_smallest_child_i(t_heap h, int i)
{
	void	*rc;
	void	*lc;

	if (i < 0 || (i >= h->len) || (heap_count_children(h, i) < 1))
		return (-1);
	if ((heap_count_children(h, i) == 1))
		return (heap_get_left_child_index(h, i));
	else
	{
		lc = garr_get(h, heap_get_left_child_index(h, i));
		rc = garr_get(h, heap_get_right_child_index(h, i));
		if (((*(h->obj_cmp)) (lc, rc)) <= 0)
			return (heap_get_left_child_index(h, i));
		else
			return (heap_get_right_child_index(h, i));
	}
}

void	heap_add(t_heap h, void *n)
{
	int		i;
	int		parent_i;
	void	*v1;
	void	*v2;

	garr_add(h, n);
	if (h->len > 1)
	{
		i = h->len - 1;
		while (heap_has_parent(h, i))
		{
			parent_i = heap_get_parent_index(h, i);
			v1 = garr_get(h, i);
			v2 = garr_get(h, parent_i);
			if ((*(h->obj_cmp))(v1, v2) < 0)
			{
				memory_swap(v1, v2, h->cell_size);
				i = parent_i;
			}
			else
				break ;
		}
	}
}

/*
**	GENERAL ALGORITHM :
**	if heap got no element we return 0
**	else if got 1 element we decrease the heap length by 1
**	else :
**	set the first element as the last one in the tree
**	decrease the length to remove the head element
**	and keep going down the tree from the new head of the tree (to sort it)
**	and swipe parent, smallest child pairs whenever it is needed
*/

void	heap_delete_head_value(t_heap h)
{
	int		i;
	int		last;
	int		s_ch_i;

	if (h->len == 1)
		h->len = 0;
	else if (h->len > 0)
	{
		last = h->len - 1;
		garr_set(h, 0, garr_get(h, last));
		i = 0;
		h->len--;
		while (heap_count_children(h, i) > 0)
		{
			s_ch_i = heap_get_smallest_child_i(h, i);
			if ((*(h->obj_cmp))(garr_get(h, i), garr_get(h, s_ch_i)) > 0)
			{
				memory_swap(garr_get(h, i), garr_get(h, s_ch_i), h->cell_size);
				i = s_ch_i;
			}
			else
				break ;
		}
	}
}
