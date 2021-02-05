/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:00:26 by khafni            #+#    #+#             */
/*   Updated: 2021/01/21 17:15:58 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_intersection	intersect(void *shape, t_shape_type type, t_ray r)
{
	t_intersection inter;

	if (type == SHAPE_TYPE_SPHERE)
		inter = sphere_intersect(r, shape);
	else if(type == SHAPE_TYPE_PLANE)
		inter = plane_intersect(r, shape);
	else if (type == SHAPE_TYPE_TRIANGLE)
		inter = triangle_intersect(r, shape);
	else if (type == SHAPE_TYPE_SQUARE)
		inter = square_intersect(r, shape);
	return (inter);
}

t_intersection	intersection(void *shape, double value, t_shape_type type)
{
	t_intersection intr;

	intr.shape = shape;
	intr.value = value;
	intr.type = type;
	return (intr);
}

int				intersections_cmp(void *i1_, void *i2_)
{
	t_intersection *i1;
	t_intersection *i2;

	i1 = (t_intersection*)i1_;
	i2 = (t_intersection*)i2_;
	if (i1->value > i2->value)
		return (1);
	return (-1);
}

void			intersections_add(t_array a, t_intersection it)
{
	void *it_;

	it_ = (void*)&it;
	garr_add(a, it_);
}

t_intersection	hit(t_array is)
{
	int				i;
	t_intersection	intr;

	i = 0;
	heap_sort(is, intersections_cmp);
	while (i < is->len)
	{
		intr = *((t_intersection*)garr_get(is, i));
		if (intr.value > 0)
			return (intr);
		i++;
	}
	intr.shape = NULL;
	intr.value = -1;
	intr.type = NO_INTERSECTION;
	return (intr);
}
