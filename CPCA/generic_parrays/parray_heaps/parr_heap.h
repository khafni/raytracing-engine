/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_heap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:15:59 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:48:03 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARR_HEAP_H
# define PARR_HEAP_H
# include "../garrptr.h"

/*
** A Heap is a special Tree-based data structure in
** which the tree is a complete binary tree.
** here i implement the heap data structure based on
** my generic dynamic void pointers arrays module
** and i also implement a polymorphic heap sort function
** that works similary to the C library function qsort
** but using the heap sort algorithm instead of the quick sort
** one O(nlog(n))
*/

/*
** SHORT DEFINITON : AN ARRAY THAT WE VISUALIZE AS
** A BINARY TREE
*/

typedef t_arrptr	t_pheap;

# define HEAP_DEFAULT_ALLOC 128

t_pheap		pheap_create(int alloc, t_compar cmp, t_destructor des);

t_pheap		standard_pheap_create(t_compar cmp, t_destructor des);

void		pheap_destroy(t_pheap h);

int			is_empty_pheap(t_pheap h);

int			pheap_has_parent(t_pheap h, int i);

int			pheap_get_parent_index(t_pheap h, int i);

int			pheap_get_left_child_index(t_pheap h, int i);

int			pheap_get_right_child_index(t_pheap h, int i);

int			pheap_count_children(t_pheap h, int i);

void		*pheap_get_head_value(t_pheap h);

int			pheap_get_smallest_child_index(t_pheap h, int i);

/*
** add element to the end of the heap
*/

void		pheap_add(t_pheap h, void *n);

void		pheap_delete_head_value(t_pheap h);

/*
**	sorting any array of void pointers
*/
void		pheap_sort(t_arrptr arr, t_compar cmp);

#endif
