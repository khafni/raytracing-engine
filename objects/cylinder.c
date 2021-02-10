/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinderay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:58:06 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 17:50:59 by khafni           ###   ########.fr       */
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

void				cylinder_destroy(void *cy_)
{
	t_cylinder	cy;

	cy = (t_cylinder)cy_;
	free(cy);
}

t_cy_equat_sol		cy_eqt_solver(t_ray ray, t_cylinder cy)
{
	t_cy_equat_sol	sol;
	double			radius;

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
}

t_intersection	cylinder_intersect_helper(t_ray r, t_cy_equat_sol s,
t_cylinder cy)
{
	t_intersection	inter;

	inter = intersection(cy, s.root1, SHAPE_TYPE_CYLINDER);
	inter.p = position(r, inter.value);
	inter.color = cy->color;
	inter.normal = tup_sub(inter.p, cy->center);
	inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, s.m1));
	inter.normal = tup_norm(inter.normal);
	inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));

}

t_intersection	cylinder_intersect(t_ray r, void *cy_)
{
	t_cylinder cy;
	t_intersection inter;
	double			radius;
	t_cy_equat_sol	sol;

	cy = ((t_cylinder)cy_);
	sol = cy_eqt_solver(r, cy);
	if (sol.discriminant < 0)
	{
		inter.type = NO_INTERSECTION;
		return (inter);
	}
	if ((sol.m1 >= 0 && sol.m1 <= cy->cylind_height))
	{
		inter = intersection(cy_, sol.root1, SHAPE_TYPE_CYLINDER);
		inter.p = position(r, inter.value);
		inter.color = cy->color;
		inter.normal = tup_sub(inter.p, cy->center);
		inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, sol.m1));
		inter.normal = tup_norm(inter.normal);
		inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));
		return (inter);
	}
	else if ((sol.m2 >= 0 && sol.m2 <= cy->cylind_height))
	{
		inter = intersection(cy_, sol.root1, SHAPE_TYPE_CYLINDER);
		inter.p = position(r, inter.value);
		inter.color = cy->color;
		inter.normal = tup_sub(inter.p, cy->center);
		inter.normal = tup_sub(inter.normal, tup_multi(cy->normal, sol.m2));
		inter.normal = tup_norm(inter.normal);
		inter.p = tup_add(inter.p, tup_multi(inter.normal, 0.01));
		return (inter);
	}
	inter.type = NO_INTERSECTION;
	return (inter);
}
