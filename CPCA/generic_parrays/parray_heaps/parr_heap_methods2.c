/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_heap_methods2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:46:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:33:50 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parr_heap.h"

void	*pheap_get_head_value(t_pheap h)
{
	return (h->data[0]);
}

int		pheap_count_children(t_pheap h, int i)
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

int		pheap_get_smallest_child_index(t_pheap h, int i)
{
	void	*rc;
	void	*lc;

	if (i < 0 || (i >= h->len) || (pheap_count_children(h, i) < 1))
		return (-1);
	if ((pheap_count_children(h, i) == 1))
		return (pheap_get_left_child_index(h, i));
	else
	{
		lc = h->data[pheap_get_left_child_index(h, i)];
		rc = h->data[pheap_get_right_child_index(h, i)];
		if (((*(h->obj_cmp)) (lc, rc)) <= 0)
			return (pheap_get_left_child_index(h, i));
		else
			return (pheap_get_right_child_index(h, i));
	}
}

void	pheap_add(t_pheap h, void *n)
{
	int		index;
	int		parent_index;

	arrptr_add(h, n);
	if (h->len > 1)
	{
		index = h->len - 1;
		while (pheap_has_parent(h, index))
		{
			parent_index = pheap_get_parent_index(h, index);
			if ((*(h->obj_cmp))(h->data[index], h->data[parent_index]) < 0)
			{
				vp_swap(&h->data[index], &h->data[parent_index]);
				index = parent_index;
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

void	pheap_delete_head_value(t_pheap h)
{
	int		index;
	int		last;
	int		s_ch_index;

	if (h->len == 1)
		h->len = 0;
	else if (h->len > 0)
	{
		last = h->len - 1;
		h->data[0] = h->data[last];
		index = 0;
		h->len--;
		while (pheap_count_children(h, index) > 0)
		{
			s_ch_index = pheap_get_smallest_child_index(h, index);
			if ((*(h->obj_cmp))(h->data[index], h->data[s_ch_index]) > 0)
			{
				vp_swap(&h->data[index], &h->data[s_ch_index]);
				index = s_ch_index;
			}
			else
				break ;
		}
	}
}
