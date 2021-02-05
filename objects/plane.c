/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:54:54 by khafni            #+#    #+#             */
/*   Updated: 2021/01/22 18:59:06 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

 t_plane				plane(t_tup center, t_tup normal, t_tup color)
{
	t_plane p;

	p.center = center;
	p.color = color;
	p.normal = normal;
	return (p);
}


/* t_intersection		plane_intersect(t_ray r, void *p_)
{
	t_plane			p;
	t_intersection	inter;
	double			denom;
	t_tup			difference;

	p = *((t_plane*)p_);
	
	difference = tup_sub(p.center, r.origin);
	//denom = dotproduct(difference, p.normal);
	 if (dotproduct(difference, p.normal) > 0)
	{ 
		inter.shape = p_;
		//difference = tup_sub(p.center, r.origin);
		inter.type = SHAPE_TYPE_PLANE;
		inter.value = dotproduct(r.direction, p.normal) / dotproduct(difference, p.normal);
		inter.normal = p.normal;
		inter.color = p.color;
		inter.p = position(r, inter.value);
		if (inter.value > 0.00000001)
			return (inter);
 	}	 
	inter = intersection(p_, 0, NO_INTERSECTION);
	return (inter);
} */

/* t_intersection		plane_intersect(t_ray r, void *p_)
{
	t_plane			p;
	t_intersection	inter;
	double			denom;
	t_tup			difference;

	p = *((t_plane*)p_);
	denom = dotproduct(p.normal, r.direction);
	if (fabs(denom) > 1e-6)
	{
		inter.shape = p_;
		difference = tup_sub(p.center, r.origin);
		inter.type = SHAPE_TYPE_PLANE;
		inter.value = dotproduct(difference, p.normal) / denom;		
		inter.normal = p.normal;
		inter.color = p.color;
		inter.p = position(r, inter.value);
		if (inter.value >= 0)
			return (inter);
	}	
	inter = intersection(p_, 0, NO_INTERSECTION);
	return (inter);
} */

t_intersection		plane_intersect(t_ray r, void *p_)
{
	t_plane			p;
	t_intersection	inter;
	double			denom;
	t_tup			difference;

	p = *((t_plane*)p_);
	denom = dotproduct(p.normal, r.direction);
	if (fabs(denom) > 0.0001)
	{
		inter.shape = p_;
		difference = tup_sub(p.center, r.origin);
		inter.type = SHAPE_TYPE_PLANE;
		inter.value = dotproduct(difference, p.normal) / denom;
		inter.normal = p.normal;
		if (denom > 0.0001)
			inter.normal = tup_neg(p.normal);
		inter.color = p.color;
		inter.p = position(r, inter.value);
		if (inter.value > 0.0001)
			return (inter);
	}	
	inter = intersection(p_, 0, NO_INTERSECTION);
	return (inter);
}