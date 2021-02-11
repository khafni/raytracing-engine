/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:34:46 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 10:26:04 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder		cylinder(t_tup center, t_tup normal, float cylind_diameter,
float cylind_height)
{
	t_cylinder	cy;

	cy = malloc(sizeof(struct s_cylinder));
	cy->center = center;
	cy->normal = normal;
	cy->cylind_diameter = cylind_diameter;
	cy->cylind_height = cylind_height;
	return (cy);
}

void			cylinder_destroy(void *cy_)
{
	t_cylinder	cy;

	cy = (t_cylinder)cy_;
	free(cy);
}

t_cy_equat_sol	cy_eqt_solver(t_ray ray, t_cylinder cy)
{
	t_cy_equat_sol	sol;
	double			radius;

	radius = cy->cylind_diameter / 2;
	sol.x = tup_sub(ray.origin, cy->center);
	sol.a = dotproduct(ray.direction,
	ray.direction) - pow(dotproduct(ray.direction,
	cy->normal), 2);
	sol.b = (dotproduct(ray.direction, sol.x) - (dotproduct(ray.direction,
	cy->normal) * dotproduct(sol.x, cy->normal))) * 2;
	sol.c = dotproduct(sol.x, sol.x) - pow(dotproduct(sol.x,
	cy->normal), 2) - radius * radius;
	sol.discriminant = sol.b * sol.b - 4 * sol.a * sol.c;
	sol.root1 = (-sol.b - sqrt(sol.discriminant)) / (2 * sol.a);
	sol.root2 = (-sol.b + sqrt(sol.discriminant)) / (2 * sol.a);
	sol.m1 = dotproduct(ray.direction, tup_multi(cy->normal,
	sol.root1)) + dotproduct(sol.x, cy->normal);
	sol.m2 = dotproduct(ray.direction, tup_multi(cy->normal,
	sol.root2)) + dotproduct(sol.x, cy->normal);
	return (sol);
}

t_intersection	cylinder_intersect_helper(t_ray r, t_cy_equat_sol *s,
t_cylinder cy)
{
	t_intersection	inter;

	if ((s->m1 >= 0 && s->m1 <= cy->cylind_height))
	{
		s->root = s->root1;
		s->m = s->m1;
	}
	else if ((s->m2 >= 0 && s->m2 <= cy->cylind_height))
	{
		s->root = s->root2;
		s->m = s->m2;
	}
	else
	{
		inter.type = NO_INTERSECTION;
		return (inter);
	}
	inter = intersection(cy, s->root, SHAPE_TYPE_CYLINDER);
	inter.p = position(r, inter.value);
	inter.color = cy->color;
	inter.normal = tup_sub(inter.p, cy->center);
	inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, s->m));
	inter.normal = tup_norm(inter.normal);
	inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));
	return (inter);
}

t_intersection	cylinder_intersect(t_ray r, void *cy_)
{
	t_cylinder		cy;
	t_intersection	inter;
	double			radius;
	t_cy_equat_sol	sol;

	cy = ((t_cylinder)cy_);
	sol = cy_eqt_solver(r, cy);
	if (sol.discriminant < 0)
	{
		inter.type = NO_INTERSECTION;
		return (inter);
	}
	inter = cylinder_intersect_helper(r, &sol, cy);
	return (inter);
}
