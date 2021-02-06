/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:58:06 by khafni            #+#    #+#             */
/*   Updated: 2021/02/05 17:52:07 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	cylinder(t_tup center, t_tup normal, float cylind_diameter, float cylind_height, t_tup color)
{
	t_cylinder  cy;

	cy = malloc(sizeof(struct s_cylinder));
	cy->center = center;
	cy->normal = normal;
	cy->cylind_diameter = cylind_diameter;
	cy->cylind_height = cylind_diameter;
	cy->color = color;
	return (cy);
}

/* t_intersection		cylinder_intersect(t_ray r, void *cy_); */
t_intersection cylinder_intersect(t_ray r, void *cy_)
{
	t_cylinder cy;
	t_intersection inter;
	double			radius;
	t_tup x;
	double a;
	double b;
	double c;
	float root1;
	float root2;
	float delta;
	float m1;
	float m2;

	cy = ((t_cylinder)cy_);
	radius = cy->cylind_diameter / 2;
	x = tup_sub(r.origin, cy->center);
	a = dotproduct(r.direction, r.direction) - pow(dotproduct(r.direction,cy->normal), 2);
	b = (dotproduct(r.direction, x) - (dotproduct(r.direction, cy->normal) * dotproduct(x, cy->normal))) * 2;
	c = dotproduct(x, x) - pow(dotproduct(x, cy->normal), 2) - radius * radius;
	delta = b * b - 4 * a * c;
	if (delta < 0) 
	{
		inter.type = NO_INTERSECTION;
		return (inter);
	}
	root1 = (-b - sqrt(delta)) / (2 * a);
	root2 = (-b + sqrt(delta)) / (2 * a);
	m1 = dotproduct(r.direction, tup_multi(cy->normal,root1)) + dotproduct(x, cy->normal);
	m2 = dotproduct(r.direction, tup_multi(cy->normal,root2)) + dotproduct(x, cy->normal);
	if ((m1 >= 0 && m1 <= cy->cylind_height))
	{
		inter.value = root1;
		inter.p = position(r, inter.value);
		//inter.p = tup_add(inter.p, tuple(0.1,0.1,0.1));
		inter.color = cy->color;	
		inter.shape = cy_;
		inter.type = SHAPE_TYPE_CYLINDER;
		inter.normal = tup_sub(inter.p, cy->center);
		inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, m1));
		inter.normal = tup_norm(inter.normal);
		inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));
		//inter.normal = tup_norm(tup_sub(tup_sub(inter.p, cy->center), tup_multi(cy->normal, m1)));
		//inter.normal =  tup_neg(inter.normal);	
		return (inter);
	}
	else if ((m2 >= 0 && m2 <= cy->cylind_height))
	{
		inter.value = root2;
		inter.p = position(r, inter.value);
		//inter.p = tup_add(inter.p, tuple(0.1,0.1,0.1));
		inter.color = cy->color;	
		inter.shape = cy_;
		inter.type = SHAPE_TYPE_CYLINDER;
		inter.normal = tup_sub(inter.p, cy->center);
		inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, m2));
		inter.normal = tup_norm(inter.normal);
		inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));

		//inter.normal = tup_norm(tup_sub(tup_sub(inter.p, cy->center), tup_multi(cy->normal, m2)));
		//inter.normal =  tup_neg(inter.normal);	
		return (inter);
	}
	inter.type = NO_INTERSECTION;	
	return (inter);
}
